require "test/unit"
require "relax4"

class TestRelax4< Test::Unit::TestCase
  def test_basic_1
    start_node = Relax4_ruby::IntegerArray.new(2)
    start_node[0] = 1
    start_node[1] = 2

    end_node = Relax4_ruby::IntegerArray.new(2)
    end_node[0] = 3
    end_node[1] = 3

    cost = Relax4_ruby::IntegerArray.new(2)
    cost[0] = 10
    cost[1] = 20

    capacity = Relax4_ruby::IntegerArray.new(2)
    capacity[0] = 99
    capacity[1] = 99

    demand = Relax4_ruby::IntegerArray.new(3)
    demand[0] = -5
    demand[1] = -3
    demand[2] = 8

    flows = Relax4_ruby::IntegerArray.new(2)

    Relax4_ruby.run_relax4(3, 2, start_node, end_node, cost, capacity,
                           demand, flows, 0)

    assert flows[0] == 5
    assert flows[1] == 3
  end
end
