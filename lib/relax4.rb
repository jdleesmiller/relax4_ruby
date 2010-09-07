require 'relax4.so'

# 
# Methods for calling the RELAX IV solver.
#
# There is a Ruby-friendly wrapper method called {Relax4.solve}.
#
# There are also lower-level methods. Unfortunately, swig and rdoc don't work
# very well together, so the best references for these calls are currently the
# source of {Relax4.solve} and the <tt>ext/relax4.h</tt> header file listed
# below:
#  :include:../ext/relax4.h
#
module Relax4
  #
  # Solve a minimum cost network flow problem.
  #
  # @param [Hash] args named arguments
  #
  # @option args [Array<Integer>] :start_nodes index of node at the start of
  # each arc, where the first node is numbered 1.
  #
  # @option args [Array<Integer>] :end_nodes index of node at the end of each
  # arc, where the first node is numbered 1.
  #
  # @option args [Array<Integer>] :costs for each arc; negative costs are
  # allowed; negative cost cycles are allowed (edges involved in the cycle are
  # set to large); all costs must be less than +large+ and should be less than
  # <tt>large/10</tt> to avoid overflow (see RELAX4_DEFAULT_MAX_COST in
  # relax4.h, above).
  #
  # @option args [Array<Integer>] :capacities (nil) for each arc; if not
  # specified (problem is uncapacitated), all arc capacities are set to
  # +RELAX4_UNCAPACITATED+; capacities must be in [0, +large+].
  #
  # @option args [Array<Integer>] :demands for each node; a node with negative
  # demand is a surplus node; demands should balance (sum to zero), or else the
  # problem will be infeasible (but you can add a dummy node).
  #
  # @option args [Boolean] :auction_init (false) use the auction routine to find
  # an initial feasible solution; this is recommended only for hard problems.
  #
  # @option args [Integer] :large (RELAX4_DEFAULT_LARGE) a very large integer to
  # represent infinity; see the ext/relax4.h listing above for more info.
  #
  # @option args [Integer] :max_cost (RELAX4_DEFAULT_MAX_COST) largest allowed
  # cost, in order to avoid integer overflow; see the ext/relax4.h listing above
  # for more info.
  #
  # @return [Array<Integer>] optimal flows for each arc
  #
  # @raise [ArgumentError] if problem inputs are invalid
  #
  # @raise [InfeasibleError] if problem is infeasible
  #
  def self.solve args

    start_nodes = get_arg(args, :start_nodes)
    end_nodes   = get_arg(args, :end_nodes)
    costs       = get_arg(args, :costs)
    large       = args[:large] || RELAX4_DEFAULT_LARGE
    max_cost    = args[:max_cost] || RELAX4_DEFAULT_MAX_COST
    num_arcs    = start_nodes.size
    capacities  = args[:capacities] ||
      [[large, RELAX4_UNCAPACITATED].min]*num_arcs

    sizes = [start_nodes, end_nodes, costs, capacities].map{|a| a.size}
    raise ArgumentError.new("bad sizes for start/end_nodes, costs, capacities:"\
      " #{sizes.join(',')}") unless sizes.all? {|s| s == num_arcs}

    demands     = get_arg(args, :demands)
    num_nodes   = demands.size

    flows_ia = IntegerArray.new(num_arcs)
    case relax4_init(num_nodes, num_arcs,
                     IntegerArray.from_array(start_nodes),
                     IntegerArray.from_array(end_nodes),
                     IntegerArray.from_array(costs),
                     IntegerArray.from_array(capacities),
                     IntegerArray.from_array(demands),
                     flows_ia, large)
    when RELAX4_OK then
      # continue
    when RELAX4_FAIL_OUT_OF_MEMORY then
      raise "could not allocate enough memory in relax4_init"
    else
      raise "relax4_init_phase_1 failed with unrecognized code"
    end

    begin
      case relax4_check_inputs(max_cost)
      when RELAX4_OK then
        # continue
      when RELAX4_FAIL_BAD_SIZE then
        raise ArgumentError.new('problem has zero nodes or zero arcs')
      when RELAX4_FAIL_BAD_NODE then
        raise ArgumentError.new('start_nodes or end_nodes has a bad index')
      when RELAX4_FAIL_BAD_COST then
        raise ArgumentError.new("a cost exceeds the maximum (#{max_cost})")
      when RELAX4_FAIL_BAD_CAPACITY then
        raise ArgumentError.new("a capacity exceeds the maximum (#{large})")
      else
        raise "relax4_check_inputs failed with unrecognized code"
      end

      case relax4_init_phase_1()
      when RELAX4_OK then
        # continue
      when RELAX4_INFEASIBLE then
        raise InfeasibleError.new("infeasibility detected in phase 1 init")
      else
        raise "relax4_init_phase_1 failed with unrecognized code"
      end

      if args[:auction_init]
        case relax4_auction()
        when RELAX4_OK then
          # continue
        when RELAX4_INFEASIBLE then
          raise InfeasibleError.new("infeasibility detected in auction")
        else
          raise "relax4_auction failed with unrecognized code"
        end
      else
        case relax4_init_phase_2()
        when RELAX4_OK then
          # continue
        when RELAX4_INFEASIBLE then
          raise InfeasibleError.new("infeasibility detected in phase 2 init")
        else
          raise "relax4_init_phase_2 failed with unrecognized code"
        end
      end

      case relax4_run()
      when RELAX4_OK then
        # continue
      when RELAX4_INFEASIBLE then
        raise InfeasibleError.new("infeasibility detected in relax4_run")
      else
        raise "relax4_run failed with unrecognized code"
      end

      case relax4_check_output()
      when RELAX4_OK then
        # continue
      when RELAX4_OUTPUT_FAIL_NONZERO_DEMAND then
        raise "relax4 failed: output contains nonzero demands"
      when RELAX4_OUTPUT_FAIL_COMPLEMENTARY_SLACKNESS then
        raise "relax4 failed: output does not satisfy complementary slackness"
      else
        raise "relax4_check_output failed with unrecognized code"
      end 

      flows_ia.to_a!(num_arcs)
    ensure
      relax4_free()
    end
  end

  #
  # Raised to indicate that a problem is infeasible.
  #
  # There are several points in the program at which infeasibility is detected.
  # If it fails in "phase 1" initialization, this means that the exogenous
  # flow into / out of a node exceeds the total capacity of arcs out of / into
  # that node. Otherwise, the information in the solver isn't of much help in
  # figuring out why an instance is infeasible.
  #
  class InfeasibleError < RuntimeError; end

  #
  # Provided by SWIG for exchanging data with the solver.
  # Intended for internal use; see relax4_init in relax4.h, above.
  # You do not have to use this if you call {Relax4.solve}.
  #
  class IntegerArray
    #
    # Create from Ruby Array of Integers; creates C array of appropriate length
    # and copies the Ruby values in.
    #
    # @param [Array<Integer>] a elements to assign to new IntegerArray
    #
    # @return [IntegerArray] not nil
    #
    def self.from_array a
      ia = self.new(a.size) or raise 'failed to create IntegerArray'
      ia.assign! a
    end

    #
    # Set elements from Ruby Array; array length is not checked.
    #
    # @param [Array<Integer>] a elements to assign; must be of correct size, 
    # because array bounds are not checked.
    #
    # @return [IntegerArray] self
    #
    def assign! a
      for i in 0...a.size
        self[i] = a[i]
      end
      self
    end

    #
    # Convert to Ruby Array of given size; array length is not checked.
    #
    # @return [Array<Integer>] with given +size+
    #
    def to_a! size
      a = Array.new(size)
      for i in 0...a.size
        a[i] = self[i]
      end
      a
    end
  end

  private

  def self.get_arg(args, key); args[key] or raise "#{key} is required" end
end

