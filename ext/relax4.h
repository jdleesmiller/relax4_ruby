#ifndef RELAX4_H_
#define RELAX4_H_

/* Constants */
#define RELAX4_OK 0
#define RELAX4_INFEASIBLE 1
#define RELAX4_FAIL_OUT_OF_MEMORY 2
#define RELAX4_FAIL_BAD_SIZE 3
#define RELAX4_FAIL_BAD_NODE 4
#define RELAX4_FAIL_BAD_COST 5
#define RELAX4_FAIL_BAD_CAPACITY 6
#define RELAX4_OUTPUT_FAIL_NONZERO_DEMAND 101
#define RELAX4_OUTPUT_FAIL_COMPLEMENTARY_SLACKNESS 102

/* Just use int by default; must have at least 32 bits. */
#ifndef RELAX4_INT
#define RELAX4_INT int
#endif

/**
 * The default value used for the <tt>large</tt> parameter. It is set to 500
 * million, which is the value in the original relax4 source.
 *
 * Further guidance on how to set <tt>large</tt> is given in NOTE 3 in the
 * original source:
 * ALL PROBLEM DATA SHOULD BE LESS THAN LARGE IN MAGNITUDE, AND LARGE SHOULD BE
 * LESS THAN, SAY, 1/4 THE LARGEST INTEGER*4 OF THE MACHINE USED.  THIS WILL
 * GUARD PRIMARILY AGAINST OVERFLOW IN UNCAPACITATED PROBLEMS WHERE THE ARC
 * CAPACITIES ARE TAKEN FINITE BUT VERY LARGE.  NOTE, HOWEVER, THAT AS IN ALL
 * CODES OPERATING WITH INTEGERS, OVERFLOW MAY OCCUR IF SOME OF THE PROBLEM DATA
 * TAKES VERY LARGE VALUES.
 *
 * Edge capacities must be non-negative and less than or equal to
 * <tt>large</tt>, and edge costs should not exceed <tt>large/10</tt> in
 * absolute value, in order to avoid overflow (see RELAX4_DEFAULT_MAX_COST).
 */
#define RELAX4_DEFAULT_LARGE 500000000

/**
 * The guidance in the original relax4 source is that edge costs should not
 * exceed <tt>large/10</tt> in absolute value, in order to avoid overflow.
 *
 * This can be enforced by the relax4_check_inputs function.
 */
#define RELAX4_DEFAULT_MAX_COST (RELAX4_DEFAULT_LARGE/10)

/**
 * Suggested capacity to use for arcs in uncapacitated problems.
 *
 * The guidance in the original relax4 source was that LARGE should be used, but
 * this has been known to cause overflow problems. Moreover, when relax4 read
 * its input, it only read the first eight digits of each number, so it read
 * 500 million (nine decimal digits) as 50 million; so, this is a reasonable
 * value to use, if you don't have a tighter upper bound.
 */
#define RELAX4_UNCAPACITATED (RELAX4_DEFAULT_LARGE/10)

/**
 * Set global state and allocate memory for internal arrays.
 *
 * The input arrays are not copied. You can solve several instances of the same
 * size (same number of nodes and arcs) by modifying the input arrays and then
 * restarting the call sequence from relax4_check_inputs (or relax4_init_phase1,
 * if you trust your inputs).
 *
 * There can be only one relax4 problem active at a time, because it currently
 * uses global state.
 *
 * The caller is responsible for allocating (and later freeing) the arrays
 * passed to this function. The relax4_free method should be called to free the
 * internal arrays. If this call fails, you do not have to call relax4_free to
 * clean up the internal arrays.
 *
 * @param[in] num_nodes number of nodes in the graph; strictly positive
 *
 * @param[in] num_arcs number of arcs (edges) in the graph; strictly positive
 *
 * @param[in] start_nodes index of node at the start of each arc; the first node
 * is numbered 1.
 *
 * @param[in] end_nodes index of node at the end of each arc; the first node
 * is numbered 1.
 *
 * @param[in] costs cost for each arc; negative costs are allowed; negative cost
 * cycles are allowed (flows on edges involved in such a cycle are set to
 * <tt>large</tt>); absolute values of costs must be less than <tt>large</tt>
 * and should be less than <tt>large/10</tt> to avoid overflow (see
 * RELAX4_DEFAULT_MAX_COST).
 *
 * @param[in] capacities capacity for each arc; for an uncapacitated problem,
 * set these to a suitably large value (such as +RELAX4_UNCAPACITATED+);
 * capacities must be in [0, <tt>large</tt>].
 *
 * @param[in] demands demand for each node; a node with negative demand is a
 * surplus node; demands should balance (sum to zero), or else the problem will
 * be infeasible.
 *
 * @param[in] flows flow on each arc; the solution from relax4_run is stored
 * in this array.
 *
 * @param[in] large a very large integer to represent infinity; see
 * RELAX4_LARGE_DEFAULT for more information.
 *
 * @return RELAX4_OK if allocations succeeded, or RELAX4_FAIL_OUT_OF_MEMORY if
 * any failed.
 */
int relax4_init(RELAX4_INT num_nodes, RELAX4_INT num_arcs,
    RELAX4_INT start_nodes[],
    RELAX4_INT end_nodes[],
    RELAX4_INT costs[],
    RELAX4_INT capacities[],
    RELAX4_INT demands[],
    RELAX4_INT flows[],
    RELAX4_INT large);

/**
 * Basic checks on the parameters given to relax4_init.
 *
 * You do not have to call this method, but it is recommended (avoid segfaults).
 *
 * @param max_cost return RELAX4_FAIL_BAD_COST if any arc cost exceeds
 * max_cost in absolute value; see RELAX4_DEFAULT_MAX_COST.
 *
 * @return RELAX4_OK if checks pass; RELAX4_FAIL_BAD_SIZE (zero arcs or nodes),
 * RELAX4_FAIL_BAD_NODE (in start_nodes or end_nodes), RELAX4_FAIL_BAD_COST or
 * RELAX4_FAIL_BAD_CAPACITY otherwise.
 */
int relax4_check_inputs(int max_cost);

/**
 * Reduce arc capacities by as much as possible without changing the problem.
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found
 * to be infeasible during arc capacity reduction.
 */
int relax4_init_phase_1();

/**
 * Initialize the arc flows to satisfy complementary slackness with the node
 * prices.
 *
 * You must call relax4_init_phase_1 first.
 * Call either this method or relax4_auction, but do not call both.
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found to be
 * infeasible.
 */
int relax4_init_phase_2();

/**
 * Uses a version of the auction algorithm for min cost network flow to compute
 * a good initial flow and prices for the problem.
 *
 * You must call relax4_init_phase_1 first.
 * Call either this method or relax4_init_phase_2, but do not call both.
 *
 * You can get an approximate solution using the auction algorithm by just
 * calling this method (and not calling relax4_run). The flows will be stored in
 * the <tt>flows</tt> array passed to relax4_init.
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found to be
 * infeasible.
 */
int relax4_auction();

/**
 * The main solve routine.
 *
 * If the problem is feasible, the optimal flows will be stored in
 * the <tt>flows</tt> array passed to relax4_init. Otherwise, RELAX4_INFEASIBLE
 * is returned. See also the notes in relax4_init regarding negative cost
 * cycles.
 *
 * You must call (exactly) one of relax4_init_phase_2 or relax4_auction first.
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found to be
 * infeasible.
 */
int relax4_run();

/**
 * Check that there are no unsatisfied demands and that complementary slackness
 * conditions are satisfied.
 *
 * You must call relax4_run first.
 * You do not have to call this method; it just provides an independent check on
 * the correctness of relax4_run.
 *
 * @return RELAX4_OK if output passes checks; otherwise one of
 * RELAX4_OUTPUT_FAIL_NONZERO_DEMAND or
 * RELAX4_OUTPUT_FAIL_COMPLEMENTARY_SLACKNESS.
 */
int relax4_check_output();

/**
 * Free internal working arrays.
 *
 * The caller is responsible for freeing the input and output arrays passed in
 * via relax4_init.
 */
void relax4_free();

#endif /* guard */
