#ifndef RELAX4_H_
#define RELAX4_H_

int run_relax4(integer num_nodes, integer num_arcs,
    integer start_node[],
    integer end_node[],
    integer cost[],
    integer capacity[],
    integer demand[],
    integer flows[], integer use_auction_init);

#endif /* guard */
