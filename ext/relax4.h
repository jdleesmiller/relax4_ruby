#ifndef RELAX4_H_
#define RELAX4_H_

/* Constants */
#define RELAX4_OK 0
#define RELAX4_INFEASIBLE 1
#define RELAX4_FAIL_OUT_OF_MEMORY 2
#define RELAX4_OUTPUT_FAIL_NONZERO_DEMAND 101
#define RELAX4_OUTPUT_FAIL_COMPLEMENTARY_SLACKNESS 102

/**
 * The default value used for the LARGE parameter. It is set to 500 million,
 * which is the value in the original relax4 source.
 *
 * Guidance on how to set LARGE is given in Note 3:
 * ALL PROBLEM DATA SHOULD BE LESS THAN LARGE IN MAGNITUDE, AND LARGE SHOULD BE
 * LESS THAN, SAY, 1/4 THE LARGEST INTEGER*4 OF THE MACHINE USED.  THIS WILL
 * GUARD PRIMARILY AGAINST OVERFLOW IN UNCAPACITATED PROBLEMS WHERE THE ARC
 * CAPACITIES ARE TAKEN FINITE BUT VERY LARGE.  NOTE, HOWEVER, THAT AS IN ALL
 * CODES OPERATING WITH INTEGERS, OVERFLOW MAY OCCUR IF SOME OF THE PROBLEM DATA
 * TAKES VERY LARGE VALUES.
 */
#define RELAX4_DEFAULT_LARGE 500000000

/**
 * Set global state and allocate memory for internal arrays.
 *
 * The input arrays are not copied.
 *
 * There can be only one relax4 problem active at a time, because it currently
 * uses global state.
 *
 * The caller is responsible for allocating (and later freeing) the arrays
 * passed to this function. The relax4_free method should be called to free the
 * internal arrays.
 *
 * If the call fails, you do not have to call relax4_free to clean up.
 *
 * @return RELAX4_OK if allocations succeeded, or RELAX4_FAIL_OUT_OF_MEMORY if
 * any failed.
 */
int relax4_init(integer num_nodes, integer num_arcs,
    integer start_node[],
    integer end_node[],
    integer cost[],
    integer capacity[],
    integer demand[],
    integer flows[],
    integer large);

/**
 * INITIALIZATION PHASE I
 *
 * IN THIS PHASE, WE REDUCE THE ARC CAPACITIES BY AS MUCH AS POSSIBLE WITHOUT
 * CHANGING THE PROBLEM.
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found
 * to be infeasible during arc capacity reduction.
 */
int relax4_init_phase_1();

/**
 * INITIALIZE THE ARC FLOWS TO SATISFY COMPLEMENTARY SLACKNESS WITH THE 
 * PRICES.
 *
 * You must call relax4_init_phase_1 first.
 * Call this method or call relax4_auction, but do not call both.
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found to be
 * infeasible.
 */
int relax4_init_phase_2();

/**
 * USES A VERSION OF THE AUCTION ALGORITHM FOR MIN COST NETWORK FLOW TO COMPUTE
 * A GOOD INITIAL FLOW AND PRICES FOR THE PROBLEM.
 *
 * You must call relax4_init_phase_1 first.
 * Call this method or call relax4_init_phase_2, but do not call both.
 * You can get an approximate solution by just calling this method (and not
 * calling relax4_run).
 *
 * @return RELAX4_OK if successful; RELAX4_INFEASIBLE if problem was found to be
 * infeasible.
 */
int relax4_auction();

/**
 * Solve.
 *
 * You must call (exactly) one of relax4_init_phase_2 or relax4_auction first.
 */
int relax4_run();

/**
 * Check that there are no unsatisfied demands and that complementary slackness
 * conditions are satisfied.
 *
 * You must call relax4_run() first.
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
