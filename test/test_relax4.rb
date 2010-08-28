require "test/unit"
require "relax4"

class TestRelax4< Test::Unit::TestCase
  def test_solve_1
    flows = Relax4.solve \
      :start_nodes => [1, 1,1,2, 3,4,4, 4,5, 5,6, 6, 6,7, 8, 9,10,10,10,11,12],
      :end_nodes   => [2, 3,4,8, 5,6,7, 8,7,11,3, 9,10,1,12,12,12, 2, 7,10,11],
      :costs       => [7,15,8,8,14,6,8,11,6,12,0,14, 9,3, 6, 5, 7,10, 6, 2, 3].
                      map{|i|i*10},
      :demands     => [-20,4,0,0,-9,6,0,0,-3,2,0,20]
    p flows
  end

  def test_basic_1
    start_node = Relax4::IntegerArray.new(2)
    start_node[0] = 1
    start_node[1] = 2

    end_node = Relax4::IntegerArray.new(2)
    end_node[0] = 3
    end_node[1] = 3

    cost = Relax4::IntegerArray.new(2)
    cost[0] = 10
    cost[1] = 20

    capacity = Relax4::IntegerArray.new(2)
    capacity[0] = 99
    capacity[1] = 99

    demand = Relax4::IntegerArray.new(3)
    demand[0] = -5
    demand[1] = -3
    demand[2] = 8

    flows = Relax4::IntegerArray.new(2)

    Relax4.run_relax4(3, 2, start_node, end_node, cost, capacity,
                           demand, flows, 0)

    assert flows[0] == 5
    assert flows[1] == 3
  end
end
