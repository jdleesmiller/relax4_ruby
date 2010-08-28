require 'relax4.so'

# 
# Methods for calling the RELAX IV solver.
#
module Relax4
  ##
  # :singleton-method: run_relax4
  # :call-seq:
  #   run_relax4(num_nodes, num_arcs, start_nodes, end_nodes, costs, capacities,
  #   demands, flows, use_auction_init)
  #
  # Internal interface to the solver. You should use {Relax4.solve}, which is
  # more Ruby-friendly and less likely to change in the future.
  #
  # The data must be packaged into {IntegerArray} objects (provided by SWIG),
  # which translate from Ruby to C; see {IntegerArray}.
  #
  # This method does not warn about oversize variables; TODO.
  #
  # @param [Integer] num_nodes number of nodes; positive
  #
  # @param [Integer] num_arcs number of arcs; positive
  #
  # @param [IntegerArray] start_nodes indices of node at the start of each arc; 
  # must have +num_arcs+ elements with values in 1..+num_nodes+.
  #
  # @param [IntegerArray] end_nodes indices of node at the end of each arc; 
  # must have +num_arcs+ elements with values in 1..+num_nodes+.
  #
  # @param [IntegerArray] costs costs for each arc; some costs can be negative,
  # but I'm not sure about negative weight cycles. TODO
  #
  # @param [IntegerArray] capacities for each arc; for an uncapacitated problem,
  # you should set these equal to {Relax4::LARGE}.
  #
  # @param [IntegerArray] demands for each node; a node with negative supply is
  # a surplus node.
  #
  # @param [IntegerArray] flows for each arc (output); values are overwritten
  # and do not need to be initialized.
  #
  # @param [Integer] use_auction_init 1 to use the auction method to obtain an
  # initial feasible solution; 0 otherwise.
  #
  
  #
  # Large value used for infinity.
  # TODO this should come from the C source
  #
  LARGE = 500_000_000

  #
  # Solve a minimum cost network flow problem.
  #
  # @param [Hash] args named arguments
  #
  # @option args [Array<Integer>] :start_nodes indices of node at the start of
  # each arc, where the first node is numbered 1.
  #
  # @option args [Array<Integer>] :end_nodes indices of node at the end of each
  # arc, where the first node is numbered 1.
  #
  # @option args [Array<Integer>] :costs costs for each arc; some costs can be
  # negative, but I'm not sure about negative weight cycles. TODO
  #
  # @option args [Array<Integer>] :capacities (nil) for each arc; if not
  # specified, all arc capacities are set to {Relax4::LARGE}.
  #
  # @option args [Array<Integer>] :demands for each node; a node with negative
  # supply is a surplus node.
  #
  # @return [Array<Integer>] flows for each arc
  #
  # @throws if problem is infeasible
  #
  def self.solve args

    start_nodes = get_arg(args, :start_nodes)
    end_nodes   = get_arg(args, :end_nodes)
    costs       = get_arg(args, :costs)
    num_arcs    = start_nodes.size
    capacities  = args[:capacities] || [Relax4::LARGE]*num_arcs

    sizes = [start_nodes, end_nodes, costs, capacities].map{|a| a.size}
    raise "bad sizes: start/end_nodes, costs, capacities: #{sizes.join(',')}"\
      unless sizes.all? {|s| s == num_arcs}

    demands     = get_arg(args, :demands)
    num_nodes   = demands.size

    bad = [start_nodes,end_nodes].map{|a| a.reject{|i| 0 < i && i <= num_nodes}}
    raise "bad nodes: #{bad.flatten.join(',')}" unless bad.all? {|a| a.empty?}

    flows = IntegerArray.new(num_arcs)
    run_relax4(num_nodes, num_arcs,
               IntegerArray.from_array(start_nodes),
               IntegerArray.from_array(end_nodes),
               IntegerArray.from_array(costs),
               IntegerArray.from_array(capacities),
               IntegerArray.from_array(demands), flows, 1)

    # TODO auction init param

    # TODO check solution status

    flows.to_a!(num_arcs)
  end
  
  #
  # Provided by SWIG for exchanging data with the solver.
  # Intended for internal use; see {Relax4.run_relax4}.
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

  #
  # Extra information about why the problem was infeasible.
  #
  class Result
  end

  private

  def self.get_arg(args, key); args[key] or raise "#{key} is required" end
end

