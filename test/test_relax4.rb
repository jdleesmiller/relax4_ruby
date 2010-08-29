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
    assert_equal soln, Relax4.solve(prob)
    assert_equal soln, Relax4.solve(prob.merge(:auction_init => true))
    # note: total cost is 27
  end

  def test_solve_3
    # This is the RELAX4.INP file packaged with the RELAX IV code.
    arc_text = <<ARCS
       1      10      -4     215
       1      16      -8     138
       8      18       2     215
       8      14      -5      76
       8      20      -6     193
      10       8      -9     215
      10      16      -4     215
      10       6       9     190
      10      20      -8     141
      10       4      -5     152
      10      11       2      63
       2      15       5     266
       2       4      -5     186
       2       6      -3     162
       2      17       7      84
       2      11       6      94
       2      18      -6     113
      12      18      -6     266
      12       7       9     106
      12       9       4     143
      12      17       7      95
      12      15       7     181
      12       4       9     104
      12      20      -9      84
      15      12       8     266
      15      16      -4     266
      15      17       5     154
      15      20       3     132
      15       4       2     164
       3       6       2      50
       3      18      -7     131
       3      19      -8      89
       6       7      -2      50
       6      19      -6     102
       6       9       6      56
       7       9      -7      50
       7       6       3     129
       7       5      -7     141
       9      19      -1      50
       9      17      -2      50
       9      18       4      50
       9      13      -7     162
       9      16      -2     121
       9      11      10     115
       9      10      -3     166
       9       4       1     111
       4      13     -10     195
       4      19       8     112
       4      16       2     195
       4      10      -9     143
       4       9     -10     135
       4      14      -4     191
      13      18      -9     195
      13      19     -10     195
      13       8      -8     165
      13      17       0     132
       5      11      -8     319
       5       7      -8      70
       5      20       0      63
       5       9      -9     194
      11      14      -3     319
      11      19       2     125
      11      12      -9     177
      14      20      -7     319
      14      16       7     319
      14       8       9     174
      14      11      10      77
      14       5      -4     123
      14      18       5     125
      14      12     -10      69
      16      19      -3     128
      16      10      -4      56
      16       6       0     145
      16      17      10     104
      16      12       2     199
      16       5      -5     159
      17       7       2      68
      17      12      -3      57
      17      18      -3     113
      17      11      -2     130
ARCS
  node_text = <<NODES # note: these are supplies (= -ve demands)
     215
     266
       5
     195
     319
       0
       0
       0
       0
       0
       0
       0
       0
       0
       0
    -386
      -1
    -399
     -54
    -160
NODES
    arc_rx = /^\s+(\d+)\s+(\d+)\s+(-?\d+)\s+(\d+)\s*$/
    prob = {
      :demands     => node_text.strip.split(/\s+/m).map{|x| -x.to_i},
      :start_nodes => arc_text.scan(arc_rx).map{|x| x[0].to_i},
      :end_nodes   => arc_text.scan(arc_rx).map{|x| x[1].to_i},
      :costs       => arc_text.scan(arc_rx).map{|x| x[2].to_i},
      :capacities  => arc_text.scan(arc_rx).map{|x| x[3].to_i}}

    flows = Relax4.solve(prob)
    assert_equal -26464, flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)

    flows = Relax4.solve(prob.merge(:auction_init => true))
    assert_equal -26464, flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)
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
    assert_equal 5240, flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)

    # l1, s2
    flows = Relax4.solve(prob.merge(:demands => demands[1]))
    assert_equal 7620, flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)

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
    assert_equal 74, flows.zip(prob_unit[:costs]).map{|f,c|f*c}.inject(:+)

    # l1, s3
    flows = Relax4.solve(prob_unit.merge(:demands => demands[2]))
    assert_equal 0, flows.zip(prob_unit[:costs]).map{|f,c|f*c}.inject(:+)
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
    assert_equal -40000, flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)

    # If we put capacity bounds on, we get less flow around the -ve cost cycle.
    flows = Relax4.solve(prob.merge(:capacities=>[5000]*9, :auction_init=>true))
    assert_equal -40000, flows.zip(prob[:costs]).map{|f,c|f*c}.inject(:+)
  end
end
