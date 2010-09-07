require "test/unit"
require "relax4"

class TestRelax4< Test::Unit::TestCase
  def test_solve_1
    # From Figure 7.14 of Bertsimas and Tsitsiklis (1997). Introduction to
    # Linear Optimization.
    prob = {
      :demands     => [-1, 0, 0, 0, 1],
      :start_nodes => [ 1, 1, 2, 3, 4, 4],
      :end_nodes   => [ 2, 3, 4, 5, 3, 5],
      :costs       => [ 0, 1, 0, 0, 0, 1]}
    soln =            [ 1, 0, 1, 1, 1, 0]
    assert_equal soln, Relax4.solve(prob)
    assert_equal soln, Relax4.solve(prob.merge(:auction_init => true))
  end

  def test_solve_2
    # From Figure 29.3 of Cormen, Leiserson, Rivest and Stein (2001).
    # Introduction to Algorithms, 2nd Edition.
    prob = {
      :demands     => [-4, 0, 0, 4],
      :start_nodes => [ 1, 1, 2, 2, 3],
      :end_nodes   => [ 2, 3, 3, 4, 4],
      :costs       => [ 2, 5, 3, 7, 1],
      :capacities  => [ 5, 2, 1, 2, 4]}
    soln =            [ 2, 2, 1, 1, 3]
    flows = Relax4.solve(prob)
    assert_equal soln, flows
    assert_equal 27, problem_cost(prob, flows)

    assert_equal soln, Relax4.solve(prob.merge(:auction_init => true))
  end

  # Load problem from relax4_input format.
  # Note that the input format has node surpluses rather than demands.
  # No error checking.
  def problem_from_relax4_inp file_name
    require 'scanf'
    File.open(file_name) {|f|
      num_nodes, num_arcs = f.scanf('%d %d')
      arcs = num_arcs.times.collect {f.scanf('%d %d %d %d')}
      demands = num_nodes.times.collect {-f.scanf('%d').first}
      {
        :demands     => demands,
        :start_nodes => arcs.map{|x| x[0].to_i},
        :end_nodes   => arcs.map{|x| x[1].to_i},
        :costs       => arcs.map{|x| x[2].to_i},
        :capacities  => arcs.map{|x| x[3].to_i}
      }
    }
  end

  # Compute cost of flows.
  def problem_cost prob, flows
    flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)
  end

  def test_solve_3
    prob = problem_from_relax4_inp 'test/RELAX4.INP'

    flows = Relax4.solve(prob)
    assert_equal -26464, problem_cost(prob, flows)

    flows = Relax4.solve(prob.merge(:auction_init => true))
    assert_equal -26464, problem_cost(prob, flows)
  end

  def test_solve_4
    # This problem appears to fail due to overflow. Its arc capacities are set
    # to 500 million (equal to the default LARGE constant), and this causes the
    # solver to incorrectly report that the problem is infeasible. Reducing the
    # capacities by a factor of 10 makes it work OK.
    #
    # Note that giving this file to the original application works, because it
    # only reads the first 8 digits of any input number (format I8) -- i.e. it
    # sets the capacities to 50M not 500M. 
    prob = problem_from_relax4_inp 'test/test_solve_4.inp'
    prob[:capacities].map! {|x| [x, Relax4::RELAX4_UNCAPACITATED].min}
    flows = Relax4.solve(prob)
    assert_equal 1381, problem_cost(prob, flows)
  end

  def test_solve_lemon_1
    # Some tests stolen from LEMON version 1.2 (test/min_cost_flow_test.cc).
    # Note that we can't handle minimum flows, so we can only run tests with the
    # 'low1' series.
    nodes_text = <<NODES.lines.drop(1).join("\n")
label  sup1 sup2 sup3 sup4 sup5 sup6
    1    20   27    0   30   20   30
    2    -4    0    0    0   -8   -3
    3     0    0    0    0    0    0
    4     0    0    0    0    0    0
    5     9    0    0    0    6   11
    6    -6    0    0    0   -5   -6
    7     0    0    0    0    0    0
    8     0    0    0    0    0    3
    9     3    0    0    0    0    0
   10    -2    0    0    0   -7   -2
   11     0    0    0    0  -10    0
   12   -20  -27    0  -30  -30  -20
NODES
    node_rx = /^\s*\d#{'+\s+(-?\d+)'*6}\s*$/
    demands = (0...6).map{|i| nodes_text.scan(node_rx).map{|x| -x[i].to_i}}

    arcs_text = <<ARCS.lines.drop(1).join("\n")
       cost  cap 
 1  2    70   11 
 1  3   150    3 
 1  4    80   15 
 2  8    80   12 
 3  5   140    5 
 4  6    60   10 
 4  7    80    2 
 4  8   110    3 
 5  7    60   14 
 5 11   120   12 
 6  3     0    3 
 6  9   140    4 
 6 10    90    8 
 7  1    30    5 
 8 12    60   16 
 9 12    50    6 
10 12    70   13 
10  2   100    7 
10  7    60   10 
11 10    20   14 
12 11    30   10 
ARCS

    arc_rx = /^\s*(\d+)\s+(\d+)\s+(-?\d+)\s+(\d+)\s*$/
    prob = {
      :start_nodes => arcs_text.scan(arc_rx).map{|x| x[0].to_i},
      :end_nodes   => arcs_text.scan(arc_rx).map{|x| x[1].to_i},
      :costs       => arcs_text.scan(arc_rx).map{|x| x[2].to_i},
      :capacities  => arcs_text.scan(arc_rx).map{|x| x[3].to_i}}

    # l1, s1
    flows = Relax4.solve(prob.merge(:demands => demands[0]))
    assert_equal 5240, problem_cost(prob, flows)

    # l1, s2
    flows = Relax4.solve(prob.merge(:demands => demands[1]))
    assert_equal 7620, problem_cost(prob, flows)

    # l1, s5 is infeasible because s5 doesn't have balanced supply and demand
    assert_raise Relax4::InfeasibleError do
      Relax4.solve(prob.merge(:demands => demands[4]))
    end

    # unit costs and no capacities (corresponding to "cc" and "cu")
    prob_unit = {
      :start_nodes => arcs_text.scan(arc_rx).map{|x| x[0].to_i},
      :end_nodes   => arcs_text.scan(arc_rx).map{|x| x[1].to_i},
      :costs       => [1]*21}

    # l1, s1
    flows = Relax4.solve(prob_unit.merge(:demands => demands[0]))
    assert_equal 74, problem_cost(prob_unit, flows)

    # l1, s3
    flows = Relax4.solve(prob_unit.merge(:demands => demands[2]))
    assert_equal 0, problem_cost(prob_unit, flows)
  end

  def test_solve_lemon_2
    # From test_neg1_lgf in test/min_cost_flow_test.cc. This contains a negative
    # cost cycle (5, 6, 7). The result is that edges in the cycle are at
    # capacity; if capacities are not specified, they go to the LARGE constant.
    prob = {
      :demands     => [-100, 0, 0, 100, 0, 0, 0],
      :start_nodes => [  1, 1, 2, 3, 3, 5, 5, 6,   7],
      :end_nodes   => [  2, 3, 4, 4, 2, 3, 6, 7,   5],
      :costs       => [100,30,20,80,50,10,80,30,-120],
    }

    flows = Relax4.solve(prob)
    assert_equal [0,100,100,0,100,0,500000000,500000000,500000000], flows

    flows = Relax4.solve(prob.merge(:auction_init => true))
    assert_equal [0,100,100,0,100,0,500000000,500000000,500000000], flows

    # If we put capacity bounds on, we get less flow around the -ve cost cycle.
    flows = Relax4.solve(prob.merge(:capacities=>[5000]*9))
    assert_equal -40000, problem_cost(prob, flows)

    # If we put capacity bounds on, we get less flow around the -ve cost cycle.
    flows = Relax4.solve(prob.merge(:capacities=>[5000]*9, :auction_init=>true))
    assert_equal -40000, problem_cost(prob, flows)
  end

  def test_bad_args_1
    # Empty problem is invalid.
    assert_raise ArgumentError do
      Relax4.solve(:start_nodes => [], 
                   :end_nodes   => [],
                   :costs       => [],
                   :demands     => [])
    end

    # Mismatch in array lengths.
    assert_raise ArgumentError do
      Relax4.solve(:start_nodes => [1,2], 
                   :end_nodes   => [2,1],
                   :costs       => [1,1,1], # too many
                   :demands     => [-1,1])
    end

    # Node out of range.
    assert_raise ArgumentError do
      Relax4.solve(:start_nodes => [1,3], # bad node: 3
                   :end_nodes   => [2,1],
                   :costs       => [1,1],
                   :demands     => [-1,1])
    end
    assert_raise ArgumentError do
      Relax4.solve(:start_nodes => [1,2], 
                   :end_nodes   => [2,3], # bad node: 3 
                   :costs       => [1,1],
                   :demands     => [-1,1])
    end

    # Cost out of range.
    assert_raise ArgumentError do
      Relax4.solve(:start_nodes => [1,2],
                   :end_nodes   => [2,1],
                   :costs       => [99,101], # bad cost: 100
                   :demands     => [-1,1],
                   :large       => 1000,
                   :max_cost    => 100)
    end

    # Capacity out of range.
    assert_raise ArgumentError do
      Relax4.solve(:start_nodes => [1,2],
                   :end_nodes   => [2,1],
                   :costs       => [99,100],
                   :capacities  => [1000,1001], # bad capacity: 1001
                   :demands     => [-1,1],
                   :large       => 1000,
                   :max_cost    => 100)
    end
  end

  def test_infeasible
    #
    # A problem for which the phase 1 init doesn't detect infeasibility.
    #
    #         (1)             (6)    all edges have capacity 1
    #            \           /       1 unit surplus for 1, 2
    #             \         /        1 unit deficit for 6, 7
    #             (3)-->--(4)        link (3, 4) is the bottleneck
    #             /         \
    #            /           \
    #         (2)             (7)
    #
    prob = {
      :demands     => [-1, -1, 0, 0, 1, 1],
      :start_nodes => [  1,  2,  3,  4, 4],
      :end_nodes   => [  3,  3,  4,  5, 6],
      :costs       => [  1,  1,  1,  1, 1],
      :capacities  => [  1,  1,  1,  1, 1]}
    
    assert_raise Relax4::InfeasibleError do
      Relax4.solve(prob)
    end
    assert_raise Relax4::InfeasibleError do
      Relax4.solve(prob.merge(:auction_init => true))
    end
  end
end
