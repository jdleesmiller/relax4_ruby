/* relax4.f -- translated by f2c (version 20090411).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"
#include "stdio.h"

/* Common Block Declarations */

struct {
    integer n, na, large;
} input_;

#define input_1 input_

struct {
    integer *startn;
} arrays_;

#define arrays_1 arrays_

struct {
    integer *endn;
} arraye_;

#define arraye_1 arraye_

struct {
    integer *c__;
} arrayc_;

#define arrayc_1 arrayc_

struct {
    integer *u;
} arrayu_;

#define arrayu_1 arrayu_

union {
    struct {
	integer *b;
    } _1;
    struct {
	integer *dfct;
    } _2;
} arrayb_;

#define arrayb_1 (arrayb_._1)
#define arrayb_2 (arrayb_._2)

struct {
    integer *x;
} arrayx_;

#define arrayx_1 arrayx_

struct {
    integer rc[70000];
} arrayrc_;

#define arrayrc_1 arrayrc_

struct {
    integer nmultinode, iter, num_augm__, num_ascnt__, nsp;
} output_;

#define output_1 output_

union {
    struct {
	integer i1[10000];
    } _1;
    struct {
	integer tempin[10000];
    } _2;
    struct {
	integer label[10000];
    } _3;
    struct {
	integer p[10000];
    } _4;
} blk1_;

#define blk1_1 (blk1_._1)
#define blk1_2 (blk1_._2)
#define blk1_3 (blk1_._3)
#define blk1_4 (blk1_._4)

union {
    struct {
	integer i2[10000];
    } _1;
    struct {
	integer tempou[10000];
    } _2;
    struct {
	integer prdcsr[10000];
    } _3;
    struct {
	integer price[10000];
    } _4;
} blk2_;

#define blk2_1 (blk2_._1)
#define blk2_2 (blk2_._2)
#define blk2_3 (blk2_._3)
#define blk2_4 (blk2_._4)

union {
    struct {
	integer i3[10000];
    } _1;
    struct {
	integer fou[10000];
    } _2;
} blk3_;

#define blk3_1 (blk3_._1)
#define blk3_2 (blk3_._2)

union {
    struct {
	integer i4[70000];
    } _1;
    struct {
	integer nxtou[70000];
    } _2;
} blk4_;

#define blk4_1 (blk4_._1)
#define blk4_2 (blk4_._2)

union {
    struct {
	integer i5[10000];
    } _1;
    struct {
	integer fin[10000];
    } _2;
} blk5_;

#define blk5_1 (blk5_._1)
#define blk5_2 (blk5_._2)

union {
    struct {
	integer i6[70000];
    } _1;
    struct {
	integer nxtin[70000];
    } _2;
} blk6_;

#define blk6_1 (blk6_._1)
#define blk6_2 (blk6_._2)

union {
    struct {
	integer i7[70000];
    } _1;
    struct {
	integer save[70000];
    } _2;
} blk7_;

#define blk7_1 (blk7_._1)
#define blk7_2 (blk7_._2)

struct {
    logical1 scan[10000];
} blk8_;

#define blk8_1 blk8_

union {
    struct {
	logical1 mark[10000];
    } _1;
    struct {
	logical1 path_id__[10000];
    } _2;
} blk9_;

#define blk9_1 (blk9_._1)
#define blk9_2 (blk9_._2)

union {
    struct {
	integer tfstou[10000];
    } _1;
    struct {
	integer fpushf[10000];
    } _2;
} blk10_;

#define blk10_1 (blk10_._1)
#define blk10_2 (blk10_._2)

union {
    struct {
	integer tnxtou[70000];
    } _1;
    struct {
	integer nxtpushf[70000];
    } _2;
} blk11_;

#define blk11_1 (blk11_._1)
#define blk11_2 (blk11_._2)

union {
    struct {
	integer tfstin[10000];
    } _1;
    struct {
	integer fpushb[10000];
    } _2;
} blk12_;

#define blk12_1 (blk12_._1)
#define blk12_2 (blk12_._2)

union {
    struct {
	integer tnxtin[70000];
    } _1;
    struct {
	integer nxtpushb[70000];
    } _2;
} blk13_;

#define blk13_1 (blk13_._1)
#define blk13_2 (blk13_._2)

union {
    struct {
	integer i14[10000];
    } _1;
    struct {
	integer nxtqueue[10000];
    } _2;
} blk14_;

#define blk14_1 (blk14_._1)
#define blk14_2 (blk14_._2)

union {
    struct {
	integer i15[10000];
    } _1;
    struct {
	integer extend_arc__[10000];
    } _2;
} blk15_;

#define blk15_1 (blk15_._1)
#define blk15_2 (blk15_._2)

union {
    struct {
	integer i16[10000];
    } _1;
    struct {
	integer sb_level__[10000];
    } _2;
} blk16_;

#define blk16_1 (blk16_._1)
#define blk16_2 (blk16_._2)

union {
    struct {
	integer i17[10000];
    } _1;
    struct {
	integer sb_arc__[10000];
    } _2;
} blk17_;

#define blk17_1 (blk17_._1)
#define blk17_2 (blk17_._2)

struct {
    integer crash;
} cr_;

#define cr_1 cr_

struct {
    logical1 repeat;
} blkr_;

#define blkr_1 blkr_

struct {
    integer cap[70000];
} blkcap_;

#define blkcap_1 blkcap_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;


/*  SAMPLE CALLING PROGRAM FOR RELAX-IV */

/* --------------------------------------------------------------- */

/*  PURPOSE - THIS PROGRAM READS IN DATA FOR A LINEAR COST */
/*     ORDINARY NETWORK FLOW PROBLEM FROM THE FILE `RELAX4.INP', */
/*     CALLS THE ROUTINE INIDAT TO CONSTRUCT LINKED LIST FOR THE PROBLEM, */
/*     AND THEN CALLS THE ROUTINE RELAX4 TO SOLVE THE PROBLEM. */

/*  ZIB modification: */
/*  ---------------- */
/*  Timing Function SECNDS replaced by DTIME */

/*  G. Skorobohatyj */
/* --------------------------------------------------------------- */

/* Subroutine */ int inidat_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, i1, i2;


/* --------------------------------------------------------------- */

/*  PURPOSE - THIS ROUTINE CONSTRUCTS TWO LINKED LISTS FOR */
/*     THE NETWORK TOPOLOGY: ONE LIST (GIVEN BY FOU, NXTOU) FOR */
/*     THE OUTGOING ARCS OF NODES AND ONE LIST (GIVEN BY FIN, */
/*     NXTIN) FOR THE INCOMING ARCS OF NODES.  THESE TWO LISTS */
/*     ARE REQUIRED BY RELAX4. */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */


/*  INPUT PARAMETERS */

/*     N         = NUMBER OF NODES */
/*     NA        = NUMBER OF ARCS */
/*     STARTN(J) = STARTING NODE FOR ARC J,           J = 1,...,NA */
/*     ENDN(J)   = ENDING NODE FOR ARC J,             J = 1,...,NA */


/*  OUTPUT PARAMETERS */

/*     FOU(I)    = FIRST ARC OUT OF NODE I,           I = 1,...,N */
/*     NXTOU(J)  = NEXT ARC OUT OF THE STARTING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     FIN(I)    = FIRST ARC INTO NODE I,             I = 1,...,N */
/*     NXTIN(J)  = NEXT ARC INTO THE ENDING NODE OF ARC J, */
/*                                                    J = 1,...,NA */


/*  WORKING PARAMETERS */


/* --------------------------------------------------------------- */

    i__1 = input_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blk5_2.fin[i__ - 1] = 0;
	blk3_2.fou[i__ - 1] = 0;
	blk1_2.tempin[i__ - 1] = 0;
/* L10: */
	blk2_2.tempou[i__ - 1] = 0;
    }
    i__1 = input_1.na;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blk6_2.nxtin[i__ - 1] = 0;
	blk4_2.nxtou[i__ - 1] = 0;
	i1 = arrays_1.startn[i__ - 1];
	i2 = arraye_1.endn[i__ - 1];
	if (blk3_2.fou[i1 - 1] != 0) {
	    blk4_2.nxtou[blk2_2.tempou[i1 - 1] - 1] = i__;
	} else {
	    blk3_2.fou[i1 - 1] = i__;
	}
	blk2_2.tempou[i1 - 1] = i__;
	if (blk5_2.fin[i2 - 1] != 0) {
	    blk6_2.nxtin[blk1_2.tempin[i2 - 1] - 1] = i__;
	} else {
	    blk5_2.fin[i2 - 1] = i__;
	}
/* L20: */
	blk1_2.tempin[i2 - 1] = i__;
    }
    return 0;
} /* inidat_ */



/* Subroutine */ int relax4_(void)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_paus(char *, ftnlen), s_stop(char *, ftnlen);

    /* Local variables */
    static integer node_def__, prevnode, i__, j, t, t1, t2, lastqueue, 
	    numpasses, numnz_new__, ib, nb, dp, dm, dx, tp, ts, num_passes__, 
	    arc;
    extern /* Subroutine */ int printflows_(integer *);
    static integer trc, narc, node, delx;
    static logical1 quit;
    static integer node2;
#define ddneg ((integer *)&blk12_1)
    static integer indef, capin;
    /*extern doublereal dtime_(real *);*/
    static integer nscan;
#define ddpos ((integer *)&blk10_1)
    static logical1 posit;
    static integer numnz;
    extern /* Subroutine */ int ascnt1_(integer *, integer *, integer *, 
	    logical1 *, logical1 *, integer *, integer *, integer *), ascnt2_(
	    integer *, integer *, integer *, logical1 *, logical1 *, integer *
	    , integer *, integer *);
    static logical1 feasbl;
    static integer nlabel, defcit, maxcap, delprc, scapin, augnod, tmparc, 
	    scapou, capout, passes, rdcost, nxtarc;
    static logical1 switch__;
    static integer prvarc, nxtbrk;
    static logical1 pchange;
    static integer naugnod;
    extern /* Subroutine */ int auction_(void);
    static integer nxtnode;

    /* Fortran I/O blocks */
    static cilist io___52 = { 0, 6, 0, 0, 0 };
    static cilist io___53 = { 0, 6, 0, 0, 0 };
    static cilist io___56 = { 0, 6, 0, 0, 0 };
    static cilist io___57 = { 0, 6, 0, 0, 0 };
    static cilist io___99 = { 0, 6, 0, 0, 0 };
    static cilist io___100 = { 0, 6, 0, 0, 0 };



/* --------------------------------------------------------------- */

/*                 RELAX-IV  (VERSION OF OCTOBER 1994) */

/*  RELEASE NOTE - THIS VERSION OF RELAXATION CODE HAS OPTION FOR */
/*     A SPECIAL CRASH PROCEDURE FOR */
/*     THE INITIAL PRICE-FLOW PAIR. THIS IS RECOMMENDED FOR DIFFICULT */
/*     PROBLEMS WHERE THE DEFAULT INITIALIZATION */
/*     RESULTS IN LONG RUNNING TIMES. */
/*     CRASH =1 CORRESPONDS TO AN AUCTION/SHORTEST PATH METHOD */

/*     THESE INITIALIZATIONS ARE RECOMMENDED IN THE ABSENCE OF ANY */
/*     PRIOR INFORMATION ON A FAVORABLE INITIAL FLOW-PRICE VECTOR PAIR */
/*     THAT SATISFIES COMPLEMENTARY SLACKNESS */

/*     THE RELAXATION PORTION OF THE CODE DIFFERS FROM THE CODE RELAXT-III */
/*     AND OTHER EARLIER RELAXATION CODES IN THAT IT MAINTAINS */
/*     THE SET OF NODES WITH NONZERO DEFICIT IN A FIFO QUEUE. */
/*     LIKE ITS PREDECESSOR RELAXT-III, THIS CODE MAINTAINS A LINKED LIST */
/*     OF BALANCED (I.E., OF ZERO REDUCED COST) ARCS SO TO REDUCE */
/*     THE WORK IN LABELING AND SCANNING. */
/*     UNLIKE RELAXT-III, IT DOES NOT USE SELECTIVELY */
/*     SHORTEST PATH ITERATIONS FOR INITIALIZATION. */

/* --------------------------------------------------------------- */

/*  PURPOSE - THIS ROUTINE IMPLEMENTS THE RELAXATION METHOD */
/*     OF BERTSEKAS AND TSENG (SEE [1], [2]) FOR LINEAR */
/*     COST ORDINARY NETWORK FLOW PROBLEMS. */

/*  [1] BERTSEKAS, D. P., "A UNIFIED FRAMEWORK FOR PRIMAL-DUAL METHODS ..." */
/*      MATHEMATICAL PROGRAMMING, VOL. 32, 1985, PP. 125-145. */
/*  [2] BERTSEKAS, D. P., AND TSENG, P., "RELAXATION METHODS FOR */
/*      MINIMUM COST ..." OPERATIONS RESEARCH, VOL. 26, 1988, PP. 93-114. */

/*     THE RELAXATION METHOD IS ALSO DESCRIBED IN THE BOOKS: */

/*  [3] BERTSEKAS, D. P., "LINEAR NETWORK OPTIMIZATION: ALGORITHMS AND CODES" */
/*      MIT PRESS, 1991. */
/*  [4] BERTSEKAS, D. P. AND TSITSIKLIS, J. N., "PARALLEL AND DISTRIBUTED */
/*      COMPUTATION: NUMERICAL METHODS", PRENTICE-HALL, 1989. */



/* --------------------------------------------------------------- */

/*  SOURCE -  THIS CODE WAS WRITTEN BY DIMITRI P. BERTSEKAS */
/*     AND PAUL TSENG, WITH A CONTRIBUTION BY JONATHAN ECKSTEIN */
/*     IN THE PHASE II INITIALIZATION.  THE ROUTINE AUCTION WAS WRITTEN */
/*     BY DIMITRI P. BERTSEKAS AND IS BASED ON THE METHOD DESCRIBED IN */
/*     THE PAPER: */

/*  [5] BERTSEKAS, D. P., "AN AUCTION/SEQUENTIAL SHORTEST PATH ALGORITHM */
/*      FOR THE MINIMUM COST FLOW PROBLEM", LIDS REPORT P-2146, MIT, NOV. 1992. */

/*     FOR INQUIRIES ABOUT THE CODE, PLEASE CONTACT: */

/*     DIMITRI P. BERTSEKAS */
/*     LABORATORY FOR INFORMATION AND DECISION SYSTEMS */
/*     MASSACHUSETTS INSTITUTE OF TECHNOLOGY */
/*     CAMBRIDGE, MA 02139 */
/*     (617) 253-7267, DIMITRIB@MIT.EDU */

/* --------------------------------------------------------------- */

/*  USER GUIDELINES - */

/*     THIS ROUTINE IS IN THE PUBLIC DOMAIN TO BE USED ONLY FOR RESEARCH */
/*     PURPOSES.  IT CANNOT BE USED AS PART OF A COMMERCIAL PRODUCT, OR */
/*     TO SATISFY IN ANY PART COMMERCIAL DELIVERY REQUIREMENTS TO */
/*     GOVERNMENT OR INDUSTRY, WITHOUT PRIOR AGREEMENT WITH THE AUTHORS. */
/*     USERS ARE REQUESTED TO ACKNOWLEDGE THE AUTHORSHIP OF THE CODE, */
/*     AND THE RELAXATION METHOD.  THEY SHOULD ALSO REGISTER WITH THE */
/*     AUTHORS TO RECEIVE UPDATES AND SUBSEQUENT RELEASES. */

/*     NO MODIFICATION SHOULD BE MADE TO THIS CODE OTHER */
/*     THAN THE MINIMAL NECESSARY */
/*     TO MAKE IT COMPATIBLE WITH THE FORTRAN COMPILERS OF SPECIFIC */
/*     MACHINES.  WHEN REPORTING COMPUTATIONAL RESULTS PLEASE BE SURE */
/*     TO DESCRIBE THE MEMORY LIMITATIONS OF YOUR MACHINE. GENERALLY */
/*     RELAX4 REQUIRES MORE MEMORY THAN PRIMAL SIMPLEX CODES AND MAY */
/*     BE PENALIZED SEVERELY BY LIMITED MACHINE MEMORY. */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */


/*  INPUT PARAMETERS (SEE NOTES 1, 2, 4) */

/*     N         = NUMBER OF NODES */
/*     NA        = NUMBER OF ARCS */
/*     LARGE     = A VERY LARGE INTEGER TO REPRESENT INFINITY */
/*                 (SEE NOTE 3) */
/*     REPEAT    = .TRUE. IF INITIALIZATION IS TO BE SKIPPED */
/*                 (.FALSE. OTHERWISE) */
/*     CRASH     = 0 IF DEFAULT INITIALIZATION IS USED */
/*                 1 IF AUCTION INITIALIZATION IS USED */
/*     STARTN(J) = STARTING NODE FOR ARC J,           J = 1,...,NA */
/*     ENDN(J)   = ENDING NODE FOR ARC J,             J = 1,...,NA */
/*     FOU(I)    = FIRST ARC OUT OF NODE I,          I = 1,...,N */
/*     NXTOU(J)  = NEXT ARC OUT OF THE STARTING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     FIN(I)    = FIRST ARC INTO NODE I,             I = 1,...,N */
/*     NXTIN(J)  = NEXT ARC INTO THE ENDING NODE OF ARC J, */
/*                                                    J = 1,...,NA */


/*  UPDATED PARAMETERS (SEE NOTES 1, 3, 4) */

/*     RC(J)     = REDUCED COST OF ARC J,             J = 1,...,NA */
/*     U(J)      = CAPACITY OF ARC J ON INPUT */
/*                 AND (CAPACITY OF ARC J) - X(J) ON OUTPUT, */
/*                                                    J = 1,...,NA */
/*     DFCT(I)   = DEMAND AT NODE I ON INPUT */
/*                 AND ZERO ON OUTPUT,                I = 1,...,N */


/*  OUTPUT PARAMETERS (SEE NOTES 1, 3, 4) */

/*     X(J)      = FLOW ON ARC J,                     J = 1,...,NA */
/*     NMULTINODE = NUMBER OF MULTINODE RELAXATION ITERATIONS IN RELAX4 */
/*     ITER       = NUMBER OF RELAXATION ITERATIONS IN RELAX4 */
/*     NUM_AUGM   = NUMBER OF FLOW AUGMENTATION STEPS IN RELAX4 */
/*     NUM_ASCNT  = NUMBER OF MULTINODE ASCENT STEPS IN RELAX4 */
/*     NSP        = NUMBER OF AUCTION/SHORTEST PATH ITERATIONS */


/*  WORKING PARAMETERS (SEE NOTES 1, 4, 5) */


/*  TIMING PARAMETERS */

/*     COMMON /T/TIME0,TIME1 */

/*  NOTE 1 - */
/*     TO RUN IN LIMITED MEMORY SYSTEMS, DECLARE THE ARRAYS */
/*     STARTN, ENDN, NXTIN, NXTOU, FIN, FOU, LABEL, */
/*     PRDCSR, SAVE, TFSTOU, TNXTOU, TFSTIN, TNXTIN, */
/*     DDPOS,DDNEG,NXTQUEUE AS INTEGER*2 INSTEAD. */

/*  NOTE 2 - */
/*     THIS ROUTINE MAKES NO EFFORT TO INITIALIZE WITH A FAVORABLE X */
/*     FROM AMONGST THOSE FLOW VECTORS THAT SATISFY COMPLEMENTARY SLACKNESS */
/*     WITH THE INITIAL REDUCED COST VECTOR RC. */
/*     IF A FAVORABLE X IS KNOWN, THEN IT CAN BE PASSED, TOGETHER */
/*     WITH THE CORRESPONDING ARRAYS U AND DFCT, TO THIS ROUTINE */
/*     DIRECTLY.  THIS, HOWEVER, REQUIRES THAT THE CAPACITY */
/*     TIGHTENING PORTION AND THE FLOW INITIALIZATION PORTION */
/*     OF THIS ROUTINE (UP TO LINE LABELED 90) BE SKIPPED. */

/*  NOTE 3 - */
/*     ALL PROBLEM DATA SHOULD BE LESS THAN LARGE IN MAGNITUDE, */
/*     AND LARGE SHOULD BE LESS THAN, SAY, 1/4 THE LARGEST INTEGER*4 */
/*     OF THE MACHINE USED.  THIS WILL GUARD PRIMARILY AGAINST */
/*     OVERFLOW IN UNCAPACITATED PROBLEMS WHERE THE ARC CAPACITIES */
/*     ARE TAKEN FINITE BUT VERY LARGE.  NOTE, HOWEVER, THAT AS IN */
/*     ALL CODES OPERATING WITH INTEGERS, OVERFLOW MAY OCCUR IF SOME */
/*     OF THE PROBLEM DATA TAKES VERY LARGE VALUES. */

/*  NOTE 4 - */
/*     EACH COMMON BLOCK CONTAINS JUST ONE ARRAY, SO THE ARRAYS IN RELAX4 */
/*     CAN BE DIMENSIONED TO 1 AND TAKE THEIR DIMENSION FROM THE */
/*     MAIN CALLING ROUTINE.  WITH THIS TRICK, RELAX4 NEED NOT BE RECOMPILED */
/*     IF THE ARRAY DIMENSIONS IN THE CALLING ROUTINE CHANGE. */
/*     IF YOUR FORTRAN COMPILER DOES NOT SUPPORT THIS FEATURE, THEN */
/*     CHANGE THE DIMENSION OF ALL THE ARRAYS TO BE THE SAME AS THE ONES */
/*     DECLARED IN THE MAIN CALLING PROGRAM. */

/*  NOTE 5 - */
/*     DDPOS AND DDNEG ARE ARRAYS THAT GIVE THE DIRECTIONAL DERIVATIVES FOR */
/*     ALL POSITIVE AND NEGATIVE SINGLE-NODE PRICE CHANGES.  THESE ARE USED */
/*     ONLY IN PHASE II OF THE INITIALIZATION PROCEDURE, BEFORE THE */
/*     LINKED LIST OF BALANCED ARCS COMES TO PLAY.  THEREFORE, TO REDUCE */
/*     STORAGE, THEY ARE EQUIVALENCE TO TFSTOU AND TFSTIN, */
/*     WHICH ARE OF THE SAME SIZE (NUMBER OF NODES) AND ARE USED */
/*     ONLY AFTER THE TREE COMES INTO USE. */

/* --------------------------------------------------------------- */

/*  INITIALIZATION PHASE I */

/*     IN THIS PHASE, WE REDUCE THE ARC CAPACITIES BY AS MUCH AS */
/*     POSSIBLE WITHOUT CHANGING THE PROBLEM; */
/*     THEN WE SET THE INITIAL FLOW ARRAY X, TOGETHER WITH */
/*     THE CORRESPONDING ARRAYS U AND DFCT. */

/*     THIS PHASE AND PHASE II (FROM HERE UP TO LINE LABELED 90) */
/*     CAN BE SKIPPED (BY SETTING REPEAT TO .TRUE.) IF THE CALLING PROGRAM */
/*     PLACES IN COMMON USER-CHOSEN VALUES FOR THE ARC FLOWS, THE RESIDUAL ARC */
/*     CAPACITIES, AND THE NODAL DEFICITS.  WHEN THIS IS DONE, */
/*     IT IS CRITICAL THAT THE FLOW AND THE REDUCED COST FOR EACH ARC */
/*     SATISFY COMPLEMENTARY SLACKNESS */
/*     AND THE DFCT ARRAY PROPERLY CORRESPOND TO THE INITIAL ARC/FLOWS. */

    if (blkr_1.repeat) {
	goto L90;
    }

    i__1 = input_1.n;
    for (node = 1; node <= i__1; ++node) {
	node_def__ = arrayb_2.dfct[node - 1];
	ddpos[node - 1] = node_def__;
	ddneg[node - 1] = -node_def__;
	maxcap = 0;
	scapou = 0;
	arc = blk3_2.fou[node - 1];
L11:
	if (arc > 0) {
	    if (scapou <= input_1.large - arrayu_1.u[arc - 1]) {
		scapou += arrayu_1.u[arc - 1];
	    } else {
		goto L10;
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L11;
	}
	if (scapou <= input_1.large - node_def__) {
	    capout = scapou + node_def__;
	} else {
	    goto L10;
	}
	if (capout < 0) {

/*     PROBLEM IS INFEASIBLE - EXIT */

	    s_wsle(&io___52);
	    do_lio(&c__9, &c__1, "EXIT DURING CAPACITY ADJUSTMENT", (ftnlen)
		    31);
	    e_wsle();
	    s_wsle(&io___53);
	    do_lio(&c__9, &c__1, "EXOGENOUS FLOW INTO NODE", (ftnlen)24);
	    do_lio(&c__3, &c__1, (char *)&node, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, " EXCEEDS OUT CAPACITY", (ftnlen)21);
	    e_wsle();
	    printflows_(&node);
	    goto L4400;
	}

	scapin = 0;
	arc = blk5_2.fin[node - 1];
L12:
	if (arc > 0) {
/* Computing MIN */
	    i__2 = arrayu_1.u[arc - 1];
	    arrayu_1.u[arc - 1] = min(i__2,capout);
	    if (maxcap < arrayu_1.u[arc - 1]) {
		maxcap = arrayu_1.u[arc - 1];
	    }
	    if (scapin <= input_1.large - arrayu_1.u[arc - 1]) {
		scapin += arrayu_1.u[arc - 1];
	    } else {
		goto L10;
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L12;
	}
	if (scapin <= input_1.large + node_def__) {
	    capin = scapin - node_def__;
	} else {
	    goto L10;
	}
	if (capin < 0) {

/*     PROBLEM IS INFEASIBLE - EXIT */

	    s_wsle(&io___56);
	    do_lio(&c__9, &c__1, "EXIT DURING CAPACITY ADJUSTMENT", (ftnlen)
		    31);
	    e_wsle();
	    s_wsle(&io___57);
	    do_lio(&c__9, &c__1, "EXOGENOUS FLOW OUT OF NODE", (ftnlen)26);
	    do_lio(&c__3, &c__1, (char *)&node, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, " EXCEEDS IN CAPACITY", (ftnlen)20);
	    e_wsle();
	    printflows_(&node);
	    goto L4400;
	}

	arc = blk3_2.fou[node - 1];
L15:
	if (arc > 0) {
/* Computing MIN */
	    i__2 = arrayu_1.u[arc - 1];
	    arrayu_1.u[arc - 1] = min(i__2,capin);
	    arc = blk4_2.nxtou[arc - 1];
	    goto L15;
	}
L10:
	;
    }

/* --------------------------------------------------------------- */

/*  INITIALIZATION PHASE II */

/*     IN THIS PHASE, WE INITIALIZE THE PRICES AND FLOWS BY EITHER CALLING */
/*     THE ROUTINE AUCTION OR BY PERFORMING ONLY SINGLE NODE (COORDINATE) */
/*     RELAXATION ITERATIONS. */

    if (cr_1.crash == 1) {
	output_1.nsp = 0;
	auction_();
	goto L70;
    }

/*     INITIALIZE THE ARC FLOWS TO SATISFY COMPLEMENTARY SLACKNESS WITH THE */
/*     PRICES.  U(ARC) IS THE RESIDUAL CAPACITY OF ARC, AND X(ARC) IS THE FLOW. */
/*     THESE TWO ALWAYS ADD UP TO THE TOTAL CAPACITY FOR ARC. */
/*     ALSO COMPUTE THE DIRECTIONAL DERIVATIVES FOR EACH COORDINATE */
/*     AND COMPUTE THE ACTUAL DEFICITS. */

    i__1 = input_1.na;
    for (arc = 1; arc <= i__1; ++arc) {
	arrayx_1.x[arc - 1] = 0;
	if (arrayrc_1.rc[arc - 1] <= 0) {
	    t = arrayu_1.u[arc - 1];
	    t1 = arrays_1.startn[arc - 1];
	    t2 = arraye_1.endn[arc - 1];
	    ddpos[t1 - 1] += t;
	    ddneg[t2 - 1] += t;
	    if (arrayrc_1.rc[arc - 1] < 0) {
		arrayx_1.x[arc - 1] = t;
		arrayu_1.u[arc - 1] = 0;
		arrayb_2.dfct[t1 - 1] += t;
		arrayb_2.dfct[t2 - 1] -= t;
		ddneg[t1 - 1] -= t;
		ddpos[t2 - 1] -= t;
	    }
	}
/* L20: */
    }

/*     MAKE 2 OR 3 PASSES THROUGH ALL NODES, PERFORMING ONLY */
/*     SINGLE NODE RELAXATION ITERATIONS.  THE NUMBER OF */
/*     PASSES DEPENDS ON THE DENSITY OF THE NETWORK */

    if (input_1.na > input_1.n * 10) {
	numpasses = 2;
    } else {
	numpasses = 3;
    }

    i__1 = numpasses;
    for (passes = 1; passes <= i__1; ++passes) {
	i__2 = input_1.n;
	for (node = 1; node <= i__2; ++node) {
	    if (arrayb_2.dfct[node - 1] == 0) {
		goto L40;
	    }
	    if (ddpos[node - 1] <= 0) {

/*     COMPUTE DELPRC, THE STEPSIZE TO THE NEXT BREAKPOINT */
/*     IN THE DUAL COST AS THE PRICE OF NODE IS INCREASED. */
/*     [SINCE THE REDUCED COST OF ALL OUTGOING (RESP., */
/*     INCOMING) ARCS WILL DECREASE (RESP., INCREASE) AS */
/*     THE PRICE OF NODE IS INCREASED, THE NEXT BREAKPOINT IS */
/*     THE MINIMUM OF THE POSITIVE REDUCED COST ON OUTGOING */
/*     ARCS AND OF THE NEGATIVE REDUCED COST ON INCOMING ARCS.] */

		delprc = input_1.large;
		arc = blk3_2.fou[node - 1];
L51:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc > 0 && trc < delprc) {
			delprc = trc;
		    }
		    arc = blk4_2.nxtou[arc - 1];
		    goto L51;
		}
		arc = blk5_2.fin[node - 1];
L52:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc < 0 && trc > -delprc) {
			delprc = -trc;
		    }
		    arc = blk6_2.nxtin[arc - 1];
		    goto L52;
		}

/*     IF NO BREAKPOINT IS LEFT AND DUAL ASCENT IS STILL */
/*     POSSIBLE, THE PROBLEM IS INFEASIBLE. */

		if (delprc >= input_1.large) {
		    if (ddpos[node - 1] == 0) {
			goto L40;
		    }
		    goto L4400;
		}

/*     DELPRC IS THE STEPSIZE TO NEXT BREAKPOINT.  INCREASE */
/*     PRICE OF NODE BY DELPRC AND COMPUTE THE STEPSIZE TO */
/*     THE NEXT BREAKPOINT IN THE DUAL COST. */

L53:
		nxtbrk = input_1.large;

/*     LOOK AT ALL ARCS OUT OF NODE. */

		arc = blk3_2.fou[node - 1];
L54:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc == 0) {
			t1 = arraye_1.endn[arc - 1];
			t = arrayu_1.u[arc - 1];
			if (t > 0) {
			    arrayb_2.dfct[node - 1] += t;
			    arrayb_2.dfct[t1 - 1] -= t;
			    arrayx_1.x[arc - 1] = t;
			    arrayu_1.u[arc - 1] = 0;
			} else {
			    t = arrayx_1.x[arc - 1];
			}
			ddneg[node - 1] -= t;
			ddpos[t1 - 1] -= t;
		    }

/*     DECREASE THE REDUCED COST ON ALL OUTGOING ARCS. */

		    trc -= delprc;
		    if (trc > 0 && trc < nxtbrk) {
			nxtbrk = trc;
		    } else if (trc == 0) {

/*     ARC GOES FROM INACTIVE TO BALANCED.  UPDATE THE */
/*     RATE OF DUAL ASCENT AT NODE AND AT ITS NEIGHBOR. */

			ddpos[node - 1] += arrayu_1.u[arc - 1];
			ddneg[arraye_1.endn[arc - 1] - 1] += arrayu_1.u[arc - 
				1];
		    }
		    arrayrc_1.rc[arc - 1] = trc;
		    arc = blk4_2.nxtou[arc - 1];
		    goto L54;
		}

/*     LOOK AT ALL ARCS INTO NODE. */

		arc = blk5_2.fin[node - 1];
L55:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc == 0) {
			t1 = arrays_1.startn[arc - 1];
			t = arrayx_1.x[arc - 1];
			if (t > 0) {
			    arrayb_2.dfct[node - 1] += t;
			    arrayb_2.dfct[t1 - 1] -= t;
			    arrayu_1.u[arc - 1] = t;
			    arrayx_1.x[arc - 1] = 0;
			} else {
			    t = arrayu_1.u[arc - 1];
			}
			ddpos[t1 - 1] -= t;
			ddneg[node - 1] -= t;
		    }

/*     INCREASE THE REDUCED COST ON ALL INCOMING ARCS. */

		    trc += delprc;
		    if (trc < 0 && trc > -nxtbrk) {
			nxtbrk = -trc;
		    } else if (trc == 0) {

/*     ARC GOES FROM ACTIVE TO BALANCED.  UPDATE THE */
/*     RATE OF DUAL ASCENT AT NODE AND AT ITS NEIGHBOR. */

			ddneg[arrays_1.startn[arc - 1] - 1] += arrayx_1.x[arc 
				- 1];
			ddpos[node - 1] += arrayx_1.x[arc - 1];
		    }
		    arrayrc_1.rc[arc - 1] = trc;
		    arc = blk6_2.nxtin[arc - 1];
		    goto L55;
		}

/*     IF PRICE OF NODE CAN BE INCREASED FURTHER WITHOUT DECREASING */
/*     THE DUAL COST (EVEN IF THE DUAL COST DOESN'T INCREASE), */
/*     RETURN TO INCREASE THE PRICE FURTHER. */

		if (ddpos[node - 1] <= 0 && nxtbrk < input_1.large) {
		    delprc = nxtbrk;
		    goto L53;
		}
	    } else if (ddneg[node - 1] <= 0) {

/*     COMPUTE DELPRC, THE STEPSIZE TO THE NEXT BREAKPOINT */
/*     IN THE DUAL COST AS THE PRICE OF NODE IS DECREASED. */
/*     [SINCE THE REDUCED COST OF ALL OUTGOING (RESP., */
/*     INCOMING) ARCS WILL INCREASE (RESP., DECREASE) AS */
/*     THE PRICE OF NODE IS DECREASED, THE NEXT BREAKPOINT IS */
/*     THE MINIMUM OF THE NEGATIVE REDUCED COST ON OUTGOING */
/*     ARCS AND OF THE POSITIVE REDUCED COST ON INCOMING ARCS.] */

		delprc = input_1.large;
		arc = blk3_2.fou[node - 1];
L61:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc < 0 && trc > -delprc) {
			delprc = -trc;
		    }
		    arc = blk4_2.nxtou[arc - 1];
		    goto L61;
		}
		arc = blk5_2.fin[node - 1];
L62:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc > 0 && trc < delprc) {
			delprc = trc;
		    }
		    arc = blk6_2.nxtin[arc - 1];
		    goto L62;
		}

/*     IF NO BREAKPOINT IS LEFT AND DUAL ASCENT IS STILL */
/*     POSSIBLE, THE PROBLEM IS INFEASIBLE. */

		if (delprc == input_1.large) {
		    if (ddneg[node - 1] == 0) {
			goto L40;
		    }
		    goto L4400;
		}

/*     DELPRC IS THE STEPSIZE TO NEXT BREAKPOINT.  DECREASE */
/*     PRICE OF NODE BY DELPRC AND COMPUTE THE STEPSIZE TO */
/*     THE NEXT BREAKPOINT IN THE DUAL COST. */

L63:
		nxtbrk = input_1.large;

/*     LOOK AT ALL ARCS OUT OF NODE. */

		arc = blk3_2.fou[node - 1];
L64:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc == 0) {
			t1 = arraye_1.endn[arc - 1];
			t = arrayx_1.x[arc - 1];
			if (t > 0) {
			    arrayb_2.dfct[node - 1] -= t;
			    arrayb_2.dfct[t1 - 1] += t;
			    arrayu_1.u[arc - 1] = t;
			    arrayx_1.x[arc - 1] = 0;
			} else {
			    t = arrayu_1.u[arc - 1];
			}
			ddpos[node - 1] -= t;
			ddneg[t1 - 1] -= t;
		    }

/*     INCREASE THE REDUCED COST ON ALL OUTGOING ARCS. */

		    trc += delprc;
		    if (trc < 0 && trc > -nxtbrk) {
			nxtbrk = -trc;
		    } else if (trc == 0) {

/*     ARC GOES FROM ACTIVE TO BALANCED.  UPDATE THE */
/*     RATE OF DUAL ASCENT AT NODE AND AT ITS NEIGHBOR. */

			ddneg[node - 1] += arrayx_1.x[arc - 1];
			ddpos[arraye_1.endn[arc - 1] - 1] += arrayx_1.x[arc - 
				1];
		    }
		    arrayrc_1.rc[arc - 1] = trc;
		    arc = blk4_2.nxtou[arc - 1];
		    goto L64;
		}

/*     LOOK AT ALL ARCS INTO NODE. */

		arc = blk5_2.fin[node - 1];
L65:
		if (arc > 0) {
		    trc = arrayrc_1.rc[arc - 1];
		    if (trc == 0) {
			t1 = arrays_1.startn[arc - 1];
			t = arrayu_1.u[arc - 1];
			if (t > 0) {
			    arrayb_2.dfct[node - 1] -= t;
			    arrayb_2.dfct[t1 - 1] += t;
			    arrayx_1.x[arc - 1] = t;
			    arrayu_1.u[arc - 1] = 0;
			} else {
			    t = arrayx_1.x[arc - 1];
			}
			ddneg[t1 - 1] -= t;
			ddpos[node - 1] -= t;
		    }

/*     DECREASE THE REDUCED COST ON ALL INCOMING ARCS. */

		    trc -= delprc;
		    if (trc > 0 && trc < nxtbrk) {
			nxtbrk = trc;
		    } else if (trc == 0) {

/*     ARC GOES FROM INACTIVE TO BALANCED.  UPDATE THE */
/*     RATE OF DUAL ASCENT AT NODE AND AT ITS NEIGHBOR. */

			ddpos[arrays_1.startn[arc - 1] - 1] += arrayu_1.u[arc 
				- 1];
			ddneg[node - 1] += arrayu_1.u[arc - 1];
		    }
		    arrayrc_1.rc[arc - 1] = trc;
		    arc = blk6_2.nxtin[arc - 1];
		    goto L65;
		}

/*     IF PRICE OF NODE CAN BE DECREASED FURTHER WITHOUT DECREASING */
/*     THE DUAL COST (EVEN IF THE DUAL COST DOESN'T INCREASE), */
/*     RETURN TO DECREASE THE PRICE FURTHER. */

		if (ddneg[node - 1] <= 0 && nxtbrk < input_1.large) {
		    delprc = nxtbrk;
		    goto L63;
		}
	    }
L40:
	    ;
	}
/* L30: */
    }


L70:

/* --------------------------------------------------------------- */

/*     INITIALIZE TREE DATA STRUCTURE. */
    i__1 = input_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blk10_1.tfstou[i__ - 1] = 0;
	blk12_1.tfstin[i__ - 1] = 0;
/* L80: */
    }
    i__1 = input_1.na;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blk13_1.tnxtin[i__ - 1] = -1;
	blk11_1.tnxtou[i__ - 1] = -1;
	if (arrayrc_1.rc[i__ - 1] == 0) {
	    blk11_1.tnxtou[i__ - 1] = blk10_1.tfstou[arrays_1.startn[i__ - 1] 
		    - 1];
	    blk10_1.tfstou[arrays_1.startn[i__ - 1] - 1] = i__;
	    blk13_1.tnxtin[i__ - 1] = blk12_1.tfstin[arraye_1.endn[i__ - 1] - 
		    1];
	    blk12_1.tfstin[arraye_1.endn[i__ - 1] - 1] = i__;
	}
/* L81: */
    }

/*     INITIALIZE OTHER VARIABLES. */

L90:
    feasbl = TRUE_;
    output_1.iter = 0;
    output_1.nmultinode = 0;
    output_1.num_augm__ = 0;
    output_1.num_ascnt__ = 0;
    num_passes__ = 0;
    numnz = input_1.n;
    numnz_new__ = 0;
    switch__ = FALSE_;
    i__1 = input_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blk9_1.mark[i__ - 1] = FALSE_;
	blk8_1.scan[i__ - 1] = FALSE_;
/* L91: */
    }
    nlabel = 0;

/*     RELAX4 USES AN ADAPTIVE STRATEGY TO DECIDE WHETHER TO */
/*     CONTINUE THE SCANNING PROCESS AFTER A MULTINODE PRICE CHANGE. */
/*     THE THRESHOLD PARAMETER TP AND TS THAT CONTROL */
/*     THIS STRATEGY ARE SET IN THE NEXT TWO LINES. */

    tp = 10;
    ts = input_1.n / 15;

/*     INITIALIZE THE QUEUE OF NODES WITH NONZERO DEFICIT */

    i__1 = input_1.n - 1;
    for (node = 1; node <= i__1; ++node) {
	blk14_2.nxtqueue[node - 1] = node + 1;
/* L92: */
    }
    blk14_2.nxtqueue[input_1.n - 1] = 1;
    node = input_1.n;
    lastqueue = input_1.n;

/* --------------------------------------------------------------- */

/*     START THE RELAXATION ALGORITHM. */

L100:

/*     CODE FOR ADVANCING THE QUEUE OF NONZERO DEFICIT NODES */

    prevnode = node;
    node = blk14_2.nxtqueue[node - 1];
    defcit = arrayb_2.dfct[node - 1];
    if (node == lastqueue) {
	numnz = numnz_new__;
	numnz_new__ = 0;
	lastqueue = prevnode;
	++num_passes__;
    }

/*     CODE FOR DELETING A NODE FROM THE QUEUE */

    if (defcit == 0) {
	nxtnode = blk14_2.nxtqueue[node - 1];
	if (node == nxtnode) {
	    return 0;
	} else {
	    blk14_2.nxtqueue[prevnode - 1] = nxtnode;
	    blk14_2.nxtqueue[node - 1] = 0;
	    node = nxtnode;
	    goto L100;
	}
    } else {
	posit = defcit > 0;
    }

    ++output_1.iter;
    ++numnz_new__;

    if (posit) {

/*     ATTEMPT A SINGLE NODE ITERATION FROM NODE WITH POSITIVE DEFICIT */

	pchange = FALSE_;
	indef = defcit;
	delx = 0;
	nb = 0;

/*     CHECK OUTGOING (PROBABLY) BALANCED ARCS FROM NODE. */

	arc = blk10_1.tfstou[node - 1];
L4500:
	if (arc > 0) {
	    if (arrayrc_1.rc[arc - 1] == 0 && arrayx_1.x[arc - 1] > 0) {
		delx += arrayx_1.x[arc - 1];
		++nb;
		blk7_2.save[nb - 1] = arc;
	    }
	    arc = blk11_1.tnxtou[arc - 1];
	    goto L4500;
	}

/*     CHECK INCOMING ARCS. */

	arc = blk12_1.tfstin[node - 1];
L4501:
	if (arc > 0) {
	    if (arrayrc_1.rc[arc - 1] == 0 && arrayu_1.u[arc - 1] > 0) {
		delx += arrayu_1.u[arc - 1];
		++nb;
		blk7_2.save[nb - 1] = -arc;
	    }
	    arc = blk13_1.tnxtin[arc - 1];
	    goto L4501;
	}

/*     END OF INITIAL NODE SCAN. */

L4018:

/*     IF NO PRICE CHANGE IS POSSIBLE, EXIT. */

	if (delx > defcit) {
	    quit = defcit < indef;
	    goto L4016;
	}

/*     RELAX4 SEARCHES ALONG THE ASCENT DIRECTION FOR THE */
/*     BEST PRICE BY CHECKING THE SLOPE OF THE DUAL COST */
/*     AT SUCCESSIVE BREAK POINTS.  FIRST, WE */
/*     COMPUTE THE DISTANCE TO THE NEXT BREAK POINT. */

	delprc = input_1.large;
	arc = blk3_2.fou[node - 1];
L4502:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1];
	    if (rdcost < 0 && rdcost > -delprc) {
		delprc = -rdcost;
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L4502;
	}
	arc = blk5_2.fin[node - 1];
L4503:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1];
	    if (rdcost > 0 && rdcost < delprc) {
		delprc = rdcost;
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L4503;
	}

/*     CHECK IF PROBLEM IS INFEASIBLE. */

	if (delx < defcit && delprc == input_1.large) {

/*     THE DUAL COST CAN BE DECREASED WITHOUT BOUND. */

	    goto L4400;
	}

/*     SKIP FLOW ADJUSTEMT IF THERE IS NO FLOW TO MODIFY. */

	if (delx == 0) {
	    goto L4014;
	}

/*     ADJUST THE FLOW ON THE BALANCED ARCS INCIDENT TO NODE TO */
/*     MAINTAIN COMPLEMENTARY SLACKNESS AFTER THE PRICE CHANGE. */

	i__1 = nb;
	for (j = 1; j <= i__1; ++j) {
	    arc = blk7_2.save[j - 1];
	    if (arc > 0) {
		node2 = arraye_1.endn[arc - 1];
		t1 = arrayx_1.x[arc - 1];
		arrayb_2.dfct[node2 - 1] += t1;
		if (blk14_2.nxtqueue[node2 - 1] == 0) {
		    blk14_2.nxtqueue[prevnode - 1] = node2;
		    blk14_2.nxtqueue[node2 - 1] = node;
		    prevnode = node2;
		}
		arrayu_1.u[arc - 1] += t1;
		arrayx_1.x[arc - 1] = 0;
	    } else {
		narc = -arc;
		node2 = arrays_1.startn[narc - 1];
		t1 = arrayu_1.u[narc - 1];
		arrayb_2.dfct[node2 - 1] += t1;
		if (blk14_2.nxtqueue[node2 - 1] == 0) {
		    blk14_2.nxtqueue[prevnode - 1] = node2;
		    blk14_2.nxtqueue[node2 - 1] = node;
		    prevnode = node2;
		}
		arrayx_1.x[narc - 1] += t1;
		arrayu_1.u[narc - 1] = 0;
	    }
/* L4013: */
	}
	defcit -= delx;
L4014:
	if (delprc == input_1.large) {
	    quit = TRUE_;
	    goto L4019;
	}

/*     NODE CORRESPONDS TO A DUAL ASCENT DIRECTION.  DECREASE */
/*     THE PRICE OF NODE BY DELPRC AND COMPUTE THE STEPSIZE TO THE */
/*     NEXT BREAKPOINT IN THE DUAL COST. */

	nb = 0;
	pchange = TRUE_;
	dp = delprc;
	delprc = input_1.large;
	delx = 0;
	arc = blk3_2.fou[node - 1];
L4504:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1] + dp;
	    arrayrc_1.rc[arc - 1] = rdcost;
	    if (rdcost == 0) {
		++nb;
		blk7_2.save[nb - 1] = arc;
		delx += arrayx_1.x[arc - 1];
	    }
	    if (rdcost < 0 && rdcost > -delprc) {
		delprc = -rdcost;
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L4504;
	}
	arc = blk5_2.fin[node - 1];
L4505:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1] - dp;
	    arrayrc_1.rc[arc - 1] = rdcost;
	    if (rdcost == 0) {
		++nb;
		blk7_2.save[nb - 1] = -arc;
		delx += arrayu_1.u[arc - 1];
	    }
	    if (rdcost > 0 && rdcost < delprc) {
		delprc = rdcost;
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L4505;
	}

/*     RETURN TO CHECK IF ANOTHER PRICE CHANGE IS POSSIBLE. */

	goto L4018;

/*     PERFORM FLOW AUGMENTATION AT NODE. */

L4016:
	i__1 = nb;
	for (j = 1; j <= i__1; ++j) {
	    arc = blk7_2.save[j - 1];
	    if (arc > 0) {

/*     ARC IS AN OUTGOING ARC FROM NODE. */

		node2 = arraye_1.endn[arc - 1];
		t1 = arrayb_2.dfct[node2 - 1];
		if (t1 < 0) {

/*     DECREASE THE TOTAL DEFICIT BY DECREASING FLOW OF ARC. */

		    quit = TRUE_;
		    t2 = arrayx_1.x[arc - 1];
/* Computing MIN */
		    i__2 = defcit, i__3 = -t1, i__2 = min(i__2,i__3);
		    dx = min(i__2,t2);
		    defcit -= dx;
		    arrayb_2.dfct[node2 - 1] = t1 + dx;
		    if (blk14_2.nxtqueue[node2 - 1] == 0) {
			blk14_2.nxtqueue[prevnode - 1] = node2;
			blk14_2.nxtqueue[node2 - 1] = node;
			prevnode = node2;
		    }
		    arrayx_1.x[arc - 1] = t2 - dx;
		    arrayu_1.u[arc - 1] += dx;
		    if (defcit == 0) {
			goto L4019;
		    }
		}
	    } else {

/*     -ARC IS AN INCOMING ARC TO NODE. */

		narc = -arc;
		node2 = arrays_1.startn[narc - 1];
		t1 = arrayb_2.dfct[node2 - 1];
		if (t1 < 0) {

/*     DECREASE THE TOTAL DEFICIT BY INCREASING FLOW OF -ARC. */

		    quit = TRUE_;
		    t2 = arrayu_1.u[narc - 1];
/* Computing MIN */
		    i__2 = defcit, i__3 = -t1, i__2 = min(i__2,i__3);
		    dx = min(i__2,t2);
		    defcit -= dx;
		    arrayb_2.dfct[node2 - 1] = t1 + dx;
		    if (blk14_2.nxtqueue[node2 - 1] == 0) {
			blk14_2.nxtqueue[prevnode - 1] = node2;
			blk14_2.nxtqueue[node2 - 1] = node;
			prevnode = node2;
		    }
		    arrayx_1.x[narc - 1] += dx;
		    arrayu_1.u[narc - 1] = t2 - dx;
		    if (defcit == 0) {
			goto L4019;
		    }
		}
	    }
/* L4011: */
	}
L4019:
	arrayb_2.dfct[node - 1] = defcit;

/*     RECONSTRUCT THE LINKED LIST OF BALANCE ARCS INCIDENT TO THIS NODE. */
/*      FOR EACH ADJACENT NODE, WE ADD ANY NEWLY BLANCED ARCS */
/*      TO THE LIST, BUT DO NOT BOTHER REMOVING FORMERLY BALANCED ONES */
/*      (THEY WILL BE REMOVED THE NEXT TIME EACH ADJACENT NODE IS SCANNED). */

	if (pchange) {
	    arc = blk10_1.tfstou[node - 1];
	    blk10_1.tfstou[node - 1] = 0;
L4506:
	    if (arc > 0) {
		nxtarc = blk11_1.tnxtou[arc - 1];
		blk11_1.tnxtou[arc - 1] = -1;
		arc = nxtarc;
		goto L4506;
	    }
	    arc = blk12_1.tfstin[node - 1];
	    blk12_1.tfstin[node - 1] = 0;
L4507:
	    if (arc > 0) {
		nxtarc = blk13_1.tnxtin[arc - 1];
		blk13_1.tnxtin[arc - 1] = -1;
		arc = nxtarc;
		goto L4507;
	    }

/*     NOW ADD THE CURRENTLY BALANCED ARCS TO THE LIST FOR THIS NODE */
/*     (WHICH IS NOW EMPTY), AND THE APPROPRIATE ADJACENT ONES. */

	    i__1 = nb;
	    for (j = 1; j <= i__1; ++j) {
		arc = blk7_2.save[j - 1];
		if (arc <= 0) {
		    arc = -arc;
		}
		if (blk11_1.tnxtou[arc - 1] < 0) {
		    blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[arrays_1.startn[
			    arc - 1] - 1];
		    blk10_1.tfstou[arrays_1.startn[arc - 1] - 1] = arc;
		}
		if (blk13_1.tnxtin[arc - 1] < 0) {
		    blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[arraye_1.endn[
			    arc - 1] - 1];
		    blk12_1.tfstin[arraye_1.endn[arc - 1] - 1] = arc;
		}
/* L4508: */
	    }
	}

/*     END OF SINGLE NODE ITERATION FOR POSITIVE DEFICIT NODE. */

    } else {

/*     ATTEMPT A SINGLE NODE ITERATION FROM NODE WITH NEGATIVE DEFICIT */

	pchange = FALSE_;
	defcit = -defcit;
	indef = defcit;
	delx = 0;
	nb = 0;

	arc = blk12_1.tfstin[node - 1];
L4509:
	if (arc > 0) {
	    if (arrayrc_1.rc[arc - 1] == 0 && arrayx_1.x[arc - 1] > 0) {
		delx += arrayx_1.x[arc - 1];
		++nb;
		blk7_2.save[nb - 1] = arc;
	    }
	    arc = blk13_1.tnxtin[arc - 1];
	    goto L4509;
	}
	arc = blk10_1.tfstou[node - 1];
L4510:
	if (arc > 0) {
	    if (arrayrc_1.rc[arc - 1] == 0 && arrayu_1.u[arc - 1] > 0) {
		delx += arrayu_1.u[arc - 1];
		++nb;
		blk7_2.save[nb - 1] = -arc;
	    }
	    arc = blk11_1.tnxtou[arc - 1];
	    goto L4510;
	}

L4028:
	if (delx >= defcit) {
	    quit = defcit < indef;
	    goto L4026;
	}

/*     COMPUTE DISTANCE TO NEXT BREAKPOINT. */

	delprc = input_1.large;
	arc = blk5_2.fin[node - 1];
L4511:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1];
	    if (rdcost < 0 && rdcost > -delprc) {
		delprc = -rdcost;
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L4511;
	}
	arc = blk3_2.fou[node - 1];
L4512:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1];
	    if (rdcost > 0 && rdcost < delprc) {
		delprc = rdcost;
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L4512;
	}

/*     CHECK IF PROBLEM IS INFEASIBLE. */

	if (delx < defcit && delprc == input_1.large) {
	    goto L4400;
	}
	if (delx == 0) {
	    goto L4024;
	}

/*     FLOW AUGMENTATION IS POSSIBLE. */

	i__1 = nb;
	for (j = 1; j <= i__1; ++j) {
	    arc = blk7_2.save[j - 1];
	    if (arc > 0) {
		node2 = arrays_1.startn[arc - 1];
		t1 = arrayx_1.x[arc - 1];
		arrayb_2.dfct[node2 - 1] -= t1;
		if (blk14_2.nxtqueue[node2 - 1] == 0) {
		    blk14_2.nxtqueue[prevnode - 1] = node2;
		    blk14_2.nxtqueue[node2 - 1] = node;
		    prevnode = node2;
		}
		arrayu_1.u[arc - 1] += t1;
		arrayx_1.x[arc - 1] = 0;
	    } else {
		narc = -arc;
		node2 = arraye_1.endn[narc - 1];
		t1 = arrayu_1.u[narc - 1];
		arrayb_2.dfct[node2 - 1] -= t1;
		if (blk14_2.nxtqueue[node2 - 1] == 0) {
		    blk14_2.nxtqueue[prevnode - 1] = node2;
		    blk14_2.nxtqueue[node2 - 1] = node;
		    prevnode = node2;
		}
		arrayx_1.x[narc - 1] += t1;
		arrayu_1.u[narc - 1] = 0;
	    }
/* L4023: */
	}
	defcit -= delx;
L4024:
	if (delprc == input_1.large) {
	    quit = TRUE_;
	    goto L4029;
	}

/*     PRICE INCREASE AT NODE IS POSSIBLE. */

	nb = 0;
	pchange = TRUE_;
	dp = delprc;
	delprc = input_1.large;
	delx = 0;
	arc = blk5_2.fin[node - 1];
L4513:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1] + dp;
	    arrayrc_1.rc[arc - 1] = rdcost;
	    if (rdcost == 0) {
		++nb;
		blk7_2.save[nb - 1] = arc;
		delx += arrayx_1.x[arc - 1];
	    }
	    if (rdcost < 0 && rdcost > -delprc) {
		delprc = -rdcost;
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L4513;
	}
	arc = blk3_2.fou[node - 1];
L4514:
	if (arc > 0) {
	    rdcost = arrayrc_1.rc[arc - 1] - dp;
	    arrayrc_1.rc[arc - 1] = rdcost;
	    if (rdcost == 0) {
		++nb;
		blk7_2.save[nb - 1] = -arc;
		delx += arrayu_1.u[arc - 1];
	    }
	    if (rdcost > 0 && rdcost < delprc) {
		delprc = rdcost;
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L4514;
	}
	goto L4028;

/*     PERFORM FLOW AUGMENTATION AT NODE. */

L4026:
	i__1 = nb;
	for (j = 1; j <= i__1; ++j) {
	    arc = blk7_2.save[j - 1];
	    if (arc > 0) {

/*     ARC IS AN INCOMING ARC TO NODE. */

		node2 = arrays_1.startn[arc - 1];
		t1 = arrayb_2.dfct[node2 - 1];
		if (t1 > 0) {
		    quit = TRUE_;
		    t2 = arrayx_1.x[arc - 1];
/* Computing MIN */
		    i__2 = min(defcit,t1);
		    dx = min(i__2,t2);
		    defcit -= dx;
		    arrayb_2.dfct[node2 - 1] = t1 - dx;
		    if (blk14_2.nxtqueue[node2 - 1] == 0) {
			blk14_2.nxtqueue[prevnode - 1] = node2;
			blk14_2.nxtqueue[node2 - 1] = node;
			prevnode = node2;
		    }
		    arrayx_1.x[arc - 1] = t2 - dx;
		    arrayu_1.u[arc - 1] += dx;
		    if (defcit == 0) {
			goto L4029;
		    }
		}
	    } else {

/*     -ARC IS AN OUTGOING ARC FROM NODE. */

		narc = -arc;
		node2 = arraye_1.endn[narc - 1];
		t1 = arrayb_2.dfct[node2 - 1];
		if (t1 > 0) {
		    quit = TRUE_;
		    t2 = arrayu_1.u[narc - 1];
/* Computing MIN */
		    i__2 = min(defcit,t1);
		    dx = min(i__2,t2);
		    defcit -= dx;
		    arrayb_2.dfct[node2 - 1] = t1 - dx;
		    if (blk14_2.nxtqueue[node2 - 1] == 0) {
			blk14_2.nxtqueue[prevnode - 1] = node2;
			blk14_2.nxtqueue[node2 - 1] = node;
			prevnode = node2;
		    }
		    arrayx_1.x[narc - 1] += dx;
		    arrayu_1.u[narc - 1] = t2 - dx;
		    if (defcit == 0) {
			goto L4029;
		    }
		}
	    }
/* L4021: */
	}
L4029:
	arrayb_2.dfct[node - 1] = -defcit;

/*     RECONSTRUCT THE LIST OF BALANCED ARCS INCIDENT TO NODE. */

	if (pchange) {
	    arc = blk10_1.tfstou[node - 1];
	    blk10_1.tfstou[node - 1] = 0;
L4515:
	    if (arc > 0) {
		nxtarc = blk11_1.tnxtou[arc - 1];
		blk11_1.tnxtou[arc - 1] = -1;
		arc = nxtarc;
		goto L4515;
	    }
	    arc = blk12_1.tfstin[node - 1];
	    blk12_1.tfstin[node - 1] = 0;
L4516:
	    if (arc > 0) {
		nxtarc = blk13_1.tnxtin[arc - 1];
		blk13_1.tnxtin[arc - 1] = -1;
		arc = nxtarc;
		goto L4516;
	    }

/*     NOW ADD THE CURRENTLY BALANCED ARCS TO THE LIST FOR THIS NODE */
/*     (WHICH IS NOW EMPTY), AND THE APPROPRIATE ADJACENT ONES. */

	    i__1 = nb;
	    for (j = 1; j <= i__1; ++j) {
		arc = blk7_2.save[j - 1];
		if (arc <= 0) {
		    arc = -arc;
		}
		if (blk11_1.tnxtou[arc - 1] < 0) {
		    blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[arrays_1.startn[
			    arc - 1] - 1];
		    blk10_1.tfstou[arrays_1.startn[arc - 1] - 1] = arc;
		}
		if (blk13_1.tnxtin[arc - 1] < 0) {
		    blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[arraye_1.endn[
			    arc - 1] - 1];
		    blk12_1.tfstin[arraye_1.endn[arc - 1] - 1] = arc;
		}
/* L4517: */
	    }
	}

/*     END OF SINGLE NODE ITERATION FOR A NEGATIVE DEFICIT NODE. */

    }

    if (quit || num_passes__ <= 3) {
	goto L100;
    }

/*     DO A MULTINODE ITERATION FROM NODE. */

    ++output_1.nmultinode;

/*     IF NUMBER OF NONZERO DEFICIT NODES IS SMALL, CONTINUE */
/*     LABELING UNTIL A FLOW AUGMENTATION IS DONE. */

    switch__ = numnz < tp;

/*     UNMARK NODES LABELED EARLIER. */

    i__1 = nlabel;
    for (j = 1; j <= i__1; ++j) {
	node2 = blk1_3.label[j - 1];
	blk9_1.mark[node2 - 1] = FALSE_;
	blk8_1.scan[node2 - 1] = FALSE_;
/* L4090: */
    }

/*     INITIALIZE LABELING. */

    nlabel = 1;
    blk1_3.label[0] = node;
    blk9_1.mark[node - 1] = TRUE_;
    blk2_3.prdcsr[node - 1] = 0;

/*     SCAN STARTING NODE. */

    blk8_1.scan[node - 1] = TRUE_;
    nscan = 1;
    dm = arrayb_2.dfct[node - 1];
    delx = 0;
    i__1 = nb;
    for (j = 1; j <= i__1; ++j) {
	arc = blk7_2.save[j - 1];
	if (arc > 0) {
	    if (posit) {
		node2 = arraye_1.endn[arc - 1];
	    } else {
		node2 = arrays_1.startn[arc - 1];
	    }
	    if (! blk9_1.mark[node2 - 1]) {
		++nlabel;
		blk1_3.label[nlabel - 1] = node2;
		blk2_3.prdcsr[node2 - 1] = arc;
		blk9_1.mark[node2 - 1] = TRUE_;
		delx += arrayx_1.x[arc - 1];
	    }
	} else {
	    narc = -arc;
	    if (posit) {
		node2 = arrays_1.startn[narc - 1];
	    } else {
		node2 = arraye_1.endn[narc - 1];
	    }
	    if (! blk9_1.mark[node2 - 1]) {
		++nlabel;
		blk1_3.label[nlabel - 1] = node2;
		blk2_3.prdcsr[node2 - 1] = arc;
		blk9_1.mark[node2 - 1] = TRUE_;
		delx += arrayu_1.u[narc - 1];
	    }
	}
/* L4095: */
    }

/*     START SCANNING A LABELED BUT UNSCANNED NODE. */

L4120:
    ++nscan;

/*     CHECK TO SEE IF SWITCH NEEDS TO BE SET TO TRUE SO TO */
/*     CONTINUE SCANNING EVEN AFTER A PRICE CHANGE. */

    switch__ = switch__ || nscan > ts && numnz < ts;

/*     SCANNING WILL CONTINUE UNTIL EITHER AN OVERESTIMATE OF THE RESIDUAL */
/*     CAPACITY ACROSS THE CUT CORRESPONDING TO THE SCANNED SET OF NODES (CALLED */
/*     DELX) EXCEEDS THE ABSOLUTE VALUE OF THE TOTAL DEFICIT OF THE SCANNED */
/*     NODES (CALLED DM), OR ELSE AN AUGMENTING PATH IS FOUND.  ARCS THAT ARE */
/*     IN THE TREE BUT ARE NOT BALANCED ARE REMOVED AS PART OF THE SCANNING */
/*     PROCESS. */

    i__ = blk1_3.label[nscan - 1];
    blk8_1.scan[i__ - 1] = TRUE_;
    naugnod = 0;
    if (posit) {

/*     SCANNING NODE I IN CASE OF POSITIVE DEFICIT. */

	prvarc = 0;
	arc = blk10_1.tfstou[i__ - 1];
L4518:
	if (arc > 0) {

/*     ARC IS AN OUTGOING ARC FROM NODE. */

	    if (arrayrc_1.rc[arc - 1] == 0) {
		if (arrayx_1.x[arc - 1] > 0) {
		    node2 = arraye_1.endn[arc - 1];
		    if (! blk9_1.mark[node2 - 1]) {

/*     NODE2 IS NOT LABELED, SO ADD NODE2 TO THE LABELED SET. */

			blk2_3.prdcsr[node2 - 1] = arc;
			if (arrayb_2.dfct[node2 - 1] < 0) {
			    ++naugnod;
			    blk7_2.save[naugnod - 1] = node2;
			}
			++nlabel;
			blk1_3.label[nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
			delx += arrayx_1.x[arc - 1];
		    }
		}
		prvarc = arc;
		arc = blk11_1.tnxtou[arc - 1];
	    } else {
		tmparc = arc;
		arc = blk11_1.tnxtou[arc - 1];
		blk11_1.tnxtou[tmparc - 1] = -1;
		if (prvarc == 0) {
		    blk10_1.tfstou[i__ - 1] = arc;
		} else {
		    blk11_1.tnxtou[prvarc - 1] = arc;
		}
	    }
	    goto L4518;
	}
	prvarc = 0;
	arc = blk12_1.tfstin[i__ - 1];
L4519:
	if (arc > 0) {

/*     ARC IS AN INCOMING ARC INTO NODE. */

	    if (arrayrc_1.rc[arc - 1] == 0) {
		if (arrayu_1.u[arc - 1] > 0) {
		    node2 = arrays_1.startn[arc - 1];
		    if (! blk9_1.mark[node2 - 1]) {

/*     NODE2 IS NOT LABELED, SO ADD NODE2 TO THE LABELED SET. */

			blk2_3.prdcsr[node2 - 1] = -arc;
			if (arrayb_2.dfct[node2 - 1] < 0) {
			    ++naugnod;
			    blk7_2.save[naugnod - 1] = node2;
			}
			++nlabel;
			blk1_3.label[nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
			delx += arrayu_1.u[arc - 1];
		    }
		}
		prvarc = arc;
		arc = blk13_1.tnxtin[arc - 1];
	    } else {
		tmparc = arc;
		arc = blk13_1.tnxtin[arc - 1];
		blk13_1.tnxtin[tmparc - 1] = -1;
		if (prvarc == 0) {
		    blk12_1.tfstin[i__ - 1] = arc;
		} else {
		    blk13_1.tnxtin[prvarc - 1] = arc;
		}
	    }
	    goto L4519;
	}

/*     CORRECT THE RESIDUAL CAPACITY OF THE SCANNED NODE CUT. */

	arc = blk2_3.prdcsr[i__ - 1];
	if (arc > 0) {
	    delx -= arrayx_1.x[arc - 1];
	} else {
	    delx -= arrayu_1.u[-arc - 1];
	}

/*     END OF SCANNING OF NODE I FOR POSITIVE DEFICIT CASE. */

    } else {

/*     SCANNING NODE I FOR NEGATIVE DEFICIT CASE. */

	prvarc = 0;
	arc = blk12_1.tfstin[i__ - 1];
L4520:
	if (arc > 0) {
	    if (arrayrc_1.rc[arc - 1] == 0) {
		if (arrayx_1.x[arc - 1] > 0) {
		    node2 = arrays_1.startn[arc - 1];
		    if (! blk9_1.mark[node2 - 1]) {
			blk2_3.prdcsr[node2 - 1] = arc;
			if (arrayb_2.dfct[node2 - 1] > 0) {
			    ++naugnod;
			    blk7_2.save[naugnod - 1] = node2;
			}
			++nlabel;
			blk1_3.label[nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
			delx += arrayx_1.x[arc - 1];
		    }
		}
		prvarc = arc;
		arc = blk13_1.tnxtin[arc - 1];
	    } else {
		tmparc = arc;
		arc = blk13_1.tnxtin[arc - 1];
		blk13_1.tnxtin[tmparc - 1] = -1;
		if (prvarc == 0) {
		    blk12_1.tfstin[i__ - 1] = arc;
		} else {
		    blk13_1.tnxtin[prvarc - 1] = arc;
		}
	    }
	    goto L4520;
	}

	prvarc = 0;
	arc = blk10_1.tfstou[i__ - 1];
L4521:
	if (arc > 0) {
	    if (arrayrc_1.rc[arc - 1] == 0) {
		if (arrayu_1.u[arc - 1] > 0) {
		    node2 = arraye_1.endn[arc - 1];
		    if (! blk9_1.mark[node2 - 1]) {
			blk2_3.prdcsr[node2 - 1] = -arc;
			if (arrayb_2.dfct[node2 - 1] > 0) {
			    ++naugnod;
			    blk7_2.save[naugnod - 1] = node2;
			}
			++nlabel;
			blk1_3.label[nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
			delx += arrayu_1.u[arc - 1];
		    }
		}
		prvarc = arc;
		arc = blk11_1.tnxtou[arc - 1];
	    } else {
		tmparc = arc;
		arc = blk11_1.tnxtou[arc - 1];
		blk11_1.tnxtou[tmparc - 1] = -1;
		if (prvarc == 0) {
		    blk10_1.tfstou[i__ - 1] = arc;
		} else {
		    blk11_1.tnxtou[prvarc - 1] = arc;
		}
	    }
	    goto L4521;
	}

	arc = blk2_3.prdcsr[i__ - 1];
	if (arc > 0) {
	    delx -= arrayx_1.x[arc - 1];
	} else {
	    delx -= arrayu_1.u[-arc - 1];
	}
    }

/*     ADD DEFICIT OF NODE SCANNED TO DM. */

    dm += arrayb_2.dfct[i__ - 1];

/*     CHECK IF THE SET OF SCANNED NODES CORRESPOND */
/*     TO A DUAL ASCENT DIRECTION; IF YES, PERFORM A */
/*     PRICE ADJUSTMENT STEP, OTHERWISE CONTINUE LABELING. */

    if (nscan < nlabel) {
	if (switch__) {
	    goto L4210;
	}
	if (delx >= dm && delx >= -dm) {
	    goto L4210;
	}
    }

/*     TRY A PRICE CHANGE. */
/*     [NOTE THAT SINCE DELX-ABS(DM) IS AN OVERESTIMATE OF ASCENT SLOPE, WE */
/*     MAY OCCASIONALLY TRY A DIRECTION THAT IS NOT AN ASCENT DIRECTION. */
/*     IN THIS CASE, THE ASCNT ROUTINES RETURN WITH QUIT=.FALSE., */
/*     SO WE CONTINUE LABELING NODES. */

    if (posit) {
	ascnt1_(&dm, &delx, &nlabel, &feasbl, &switch__, &nscan, &node, &
		prevnode);
	++output_1.num_ascnt__;
    } else {
	ascnt2_(&dm, &delx, &nlabel, &feasbl, &switch__, &nscan, &node, &
		prevnode);
	++output_1.num_ascnt__;
    }
    if (! feasbl) {
	goto L4400;
    }
    if (! switch__) {
	goto L100;
    }

/*     STORE THOSE NEWLY LABELED NODES TO WHICH FLOW AUGMENTATION IS POSSIBLE. */

    naugnod = 0;
    i__1 = nlabel;
    for (j = nscan + 1; j <= i__1; ++j) {
	node2 = blk1_3.label[j - 1];
	if (posit && arrayb_2.dfct[node2 - 1] < 0) {
	    ++naugnod;
	    blk7_2.save[naugnod - 1] = node2;
	} else if (! posit && arrayb_2.dfct[node2 - 1] > 0) {
	    ++naugnod;
	    blk7_2.save[naugnod - 1] = node2;
	}
/* L530: */
    }

/*     CHECK IF FLOW AUGMENTATION IS POSSIBLE. */
/*     IF NOT, RETURN TO SCAN ANOTHER NODE. */

L4210:

    if (naugnod == 0) {
	goto L4120;
    }

    i__1 = naugnod;
    for (j = 1; j <= i__1; ++j) {
	++output_1.num_augm__;
	augnod = blk7_2.save[j - 1];
	if (posit) {

/*     DO THE AUGMENTATION FROM NODE WITH POSITIVE DEFICIT. */

	    dx = -arrayb_2.dfct[augnod - 1];
	    ib = augnod;
L1500:
	    if (ib != node) {
		arc = blk2_3.prdcsr[ib - 1];
		if (arc > 0) {
/* Computing MIN */
		    i__2 = dx, i__3 = arrayx_1.x[arc - 1];
		    dx = min(i__2,i__3);
		    ib = arrays_1.startn[arc - 1];
		} else {
/* Computing MIN */
		    i__2 = dx, i__3 = arrayu_1.u[-arc - 1];
		    dx = min(i__2,i__3);
		    ib = arraye_1.endn[-arc - 1];
		}
		goto L1500;
	    }
/* Computing MIN */
	    i__2 = dx, i__3 = arrayb_2.dfct[node - 1];
	    dx = min(i__2,i__3);
	    if (dx > 0) {

/*     INCREASE (DECREASE) THE FLOW OF ALL FORWARD (BACKWARD) */
/*     ARCS IN THE FLOW AUGMENTING PATH.  ADJUST NODE DEFICIT ACCORDINGLY. */

		if (blk14_2.nxtqueue[augnod - 1] == 0) {
		    blk14_2.nxtqueue[prevnode - 1] = augnod;
		    blk14_2.nxtqueue[augnod - 1] = node;
		    prevnode = augnod;
		}
		arrayb_2.dfct[augnod - 1] += dx;
		arrayb_2.dfct[node - 1] -= dx;
		ib = augnod;
L1501:
		if (ib != node) {
		    arc = blk2_3.prdcsr[ib - 1];
		    if (arc > 0) {
			arrayx_1.x[arc - 1] -= dx;
			arrayu_1.u[arc - 1] += dx;
			ib = arrays_1.startn[arc - 1];
		    } else {
			narc = -arc;
			arrayx_1.x[narc - 1] += dx;
			arrayu_1.u[narc - 1] -= dx;
			ib = arraye_1.endn[narc - 1];
		    }
		    goto L1501;
		}
	    }
	} else {

/*     DO THE AUGMENTATION FROM NODE WITH NEGATIVE DEFICIT. */

	    dx = arrayb_2.dfct[augnod - 1];
	    ib = augnod;
L1502:
	    if (ib != node) {
		arc = blk2_3.prdcsr[ib - 1];
		if (arc > 0) {
/* Computing MIN */
		    i__2 = dx, i__3 = arrayx_1.x[arc - 1];
		    dx = min(i__2,i__3);
		    ib = arraye_1.endn[arc - 1];
		} else {
/* Computing MIN */
		    i__2 = dx, i__3 = arrayu_1.u[-arc - 1];
		    dx = min(i__2,i__3);
		    ib = arrays_1.startn[-arc - 1];
		}
		goto L1502;
	    }
/* Computing MIN */
	    i__2 = dx, i__3 = -arrayb_2.dfct[node - 1];
	    dx = min(i__2,i__3);
	    if (dx > 0) {

/*     UPDATE THE FLOW AND DEFICITS. */

		if (blk14_2.nxtqueue[augnod - 1] == 0) {
		    blk14_2.nxtqueue[prevnode - 1] = augnod;
		    blk14_2.nxtqueue[augnod - 1] = node;
		    prevnode = augnod;
		}
		arrayb_2.dfct[augnod - 1] -= dx;
		arrayb_2.dfct[node - 1] += dx;
		ib = augnod;
L1503:
		if (ib != node) {
		    arc = blk2_3.prdcsr[ib - 1];
		    if (arc > 0) {
			arrayx_1.x[arc - 1] -= dx;
			arrayu_1.u[arc - 1] += dx;
			ib = arraye_1.endn[arc - 1];
		    } else {
			narc = -arc;
			arrayx_1.x[narc - 1] += dx;
			arrayu_1.u[narc - 1] -= dx;
			ib = arrays_1.startn[narc - 1];
		    }
		    goto L1503;
		}
	    }
	}
	if (arrayb_2.dfct[node - 1] == 0) {
	    goto L100;
	}
	if (arrayb_2.dfct[augnod - 1] != 0) {
	    switch__ = FALSE_;
	}
/* L4096: */
    }

/*     IF NODE STILL HAS NONZERO DEFICIT AND ALL NEWLY */
/*     LABELED NODES HAVE SAME SIGN FOR THEIR DEFICIT AS */
/*     NODE, WE CAN CONTINUE LABELING.  IN THIS CASE, CONTINUE */
/*     LABELING ONLY WHEN FLOW AUGMENTATION IS DONE */
/*     RELATIVELY INFREQUENTLY. */

    if (switch__ && output_1.iter > output_1.num_augm__ << 3) {
	goto L4120;
    }

/*     RETURN TO DO ANOTHER RELAXATION ITERATION. */

    goto L100;

/*     PROBLEM IS FOUND TO BE INFEASIBLE */

L4400:
    s_wsle(&io___99);
    do_lio(&c__9, &c__1, " PROBLEM IS FOUND TO BE INFEASIBLE.", (ftnlen)35);
    e_wsle();
    s_wsle(&io___100);
    do_lio(&c__9, &c__1, "PROGRAM ENDED; PRESS <CR> TO EXIT", (ftnlen)33);
    e_wsle();
    s_paus("", (ftnlen)0);
    s_stop("", (ftnlen)0);

    return 0;
} /* relax4_ */

#undef ddpos
#undef ddneg




/* Subroutine */ int auction_(void)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_paus(char *, ftnlen), s_stop(char *, ftnlen);

    /* Local variables */
    static integer seclevel, red_cost__, bstlevel, prevnode, i__, new_level__,
	     prevlevel, lastqueue, num_passes__, arc, end, nas, prd, eps, 
	    thresh_dfct__, node, pend, naug, incr, last, pass, term, flow, 
	    root, resid, pterm, start, secarc, factor, extarc, rdcost, nolist,
	     pstart, prevarc, pr_term__, mincost, maxcost, nxtnode;

    /* Fortran I/O blocks */
    static cilist io___127 = { 0, 6, 0, 0, 0 };
    static cilist io___128 = { 0, 6, 0, 0, 0 };
    static cilist io___129 = { 0, 6, 0, 0, 0 };



/* --------------------------------------------------------------- */

/*  PURPOSE - THIS SUBROUTINE USES A VERSION OF THE AUCTION */
/*     ALGORITHM FOR MIN COST NETWORK FLOW TO COMPUTE A */
/*     GOOD INITIAL FLOW AND PRICES FOR THE PROBLEM. */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */


/*  INPUT PARAMETERS */

/*     N         = NUMBER OF NODES */
/*     NA        = NUMBER OF ARCS */
/*     LARGE     = A VERY LARGE INTEGER TO REPRESENT INFINITY */
/*                 (SEE NOTE 3) */
/*     STARTN(I) = STARTING NODE FOR THE I-TH ARC,    I = 1,...,NA */
/*     ENDN(I)   = ENDING NODE FOR THE I-TH ARC,      I = 1,...,NA */
/*     FOU(I)    = FIRST ARC LEAVING I-TH NODE,       I = 1,...,N */
/*     NXTOU(I)  = NEXT ARC LEAVING THE STARTING NODE OF J-TH ARC, */
/*                                                    I = 1,...,NA */
/*     FIN(I)    = FIRST ARC ENTERING I-TH NODE,      I = 1,...,N */
/*     NXTIN(I)  = NEXT ARC ENTERING THE ENDING NODE OF J-TH ARC, */
/*                                                    I = 1,...,NA */


/*  UPDATED PARAMETERS */

/*     RC(J)     = REDUCED COST OF ARC J,             J = 1,...,NA */
/*     U(J)      = RESIDUAL CAPACITY OF ARC J, */
/*                                                    J = 1,...,NA */
/*     X(J)      = FLOW ON ARC J,                     J = 1,...,NA */
/*     DFCT(I)   = DEFICIT AT NODE I,                 I = 1,...,N */


/*  OUTPUT PARAMETERS */


/*  WORKING PARAMETERS */


/*     START INITIALIZATION USING AUCTION */

    naug = 0;
    pass = 0;
    thresh_dfct__ = 0;

/*     FACTOR DETERMINES BY HOW MUCH EPSILON IS REDUCED AT EACH MINIMIZATION */

    factor = 3;

/*     NUM_PASSES DETERMINES HOW MANY AUCTION SCALING PHASES ARE PERFORMED */

    num_passes__ = 1;
/*    SET ARC FLOWS TO SATISFY CS AND CALCULATE MAXCOST AND MINCOST */
    maxcost = -input_1.large;
    mincost = input_1.large;
    i__1 = input_1.na;
    for (arc = 1; arc <= i__1; ++arc) {
	start = arrays_1.startn[arc - 1];
	end = arraye_1.endn[arc - 1];
	rdcost = arrayrc_1.rc[arc - 1];
	if (maxcost < rdcost) {
	    maxcost = rdcost;
	}
	if (mincost > rdcost) {
	    mincost = rdcost;
	}
	if (rdcost < 0) {
	    arrayb_2.dfct[start - 1] += arrayu_1.u[arc - 1];
	    arrayb_2.dfct[end - 1] -= arrayu_1.u[arc - 1];
	    arrayx_1.x[arc - 1] = arrayu_1.u[arc - 1];
	    arrayu_1.u[arc - 1] = 0;
	} else {
	    arrayx_1.x[arc - 1] = 0;
	}
/* L49: */
    }

/*     SET INITIAL EPSILON */

    if (maxcost - mincost >= 8) {
	eps = (maxcost - mincost) / 8;
    } else {
	eps = 1;
    }

/*     SET INITIAL PRICES TO ZERO */

    i__1 = input_1.n;
    for (node = 1; node <= i__1; ++node) {
	blk1_4.p[node - 1] = 0;
/* L48: */
    }

/*     INITIALIZATION USING AUCTION/SHORTEST PATHS. */
/*     START OF THE FIRST SCALING PHASE. */

L100:
    ++pass;
    if (pass == num_passes__ || eps == 1) {
	cr_1.crash = 0;
    }
    nolist = 0;

/*     CONSTRUCT LIST OF POSITIVE SURPLUS NODES AND QUEUE OF NEGATIVE SURPLUS */
/*     NODES */

    i__1 = input_1.n;
    for (node = 1; node <= i__1; ++node) {
	blk2_3.prdcsr[node - 1] = 0;
	blk9_2.path_id__[node - 1] = FALSE_;
	blk15_2.extend_arc__[node - 1] = 0;
	blk16_2.sb_level__[node - 1] = -input_1.large;
	blk14_2.nxtqueue[node - 1] = node + 1;
	if (arrayb_2.dfct[node - 1] > 0) {
	    ++nolist;
	    blk7_2.save[nolist - 1] = node;
	}
/* L110: */
    }

    blk14_2.nxtqueue[input_1.n - 1] = 1;
    root = 1;
    prevnode = input_1.n;
    lastqueue = input_1.n;

/*     INITIALIZATION WITH DOWN ITERATIONS FOR NEGATIVE SURPLUS NODES */

    i__1 = nolist;
    for (i__ = 1; i__ <= i__1; ++i__) {
	node = blk7_2.save[i__ - 1];
	++output_1.nsp;

/*     BUILD THE LIST OF ARCS W/ ROOM FOR PUSHING FLOW */
/*     AND FIND PROPER PRICE FOR DOWN ITERATION */

	bstlevel = -input_1.large;
	blk10_2.fpushf[node - 1] = 0;
	arc = blk3_2.fou[node - 1];
L152:
	if (arc > 0) {
	    if (arrayu_1.u[arc - 1] > 0) {
		if (blk10_2.fpushf[node - 1] == 0) {
		    blk10_2.fpushf[node - 1] = arc;
		    blk11_2.nxtpushf[arc - 1] = 0;
		    last = arc;
		} else {
		    blk11_2.nxtpushf[last - 1] = arc;
		    blk11_2.nxtpushf[arc - 1] = 0;
		    last = arc;
		}
	    }
	    if (arrayx_1.x[arc - 1] > 0) {
		new_level__ = blk1_4.p[arraye_1.endn[arc - 1] - 1] + 
			arrayrc_1.rc[arc - 1];
		if (new_level__ > bstlevel) {
		    bstlevel = new_level__;
		    extarc = arc;
		}
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L152;
	}

	blk12_2.fpushb[node - 1] = 0;
	arc = blk5_2.fin[node - 1];
L154:
	if (arc > 0) {
	    if (arrayx_1.x[arc - 1] > 0) {
		if (blk12_2.fpushb[node - 1] == 0) {
		    blk12_2.fpushb[node - 1] = arc;
		    blk13_2.nxtpushb[arc - 1] = 0;
		    last = arc;
		} else {
		    blk13_2.nxtpushb[last - 1] = arc;
		    blk13_2.nxtpushb[arc - 1] = 0;
		    last = arc;
		}
	    }
	    if (arrayu_1.u[arc - 1] > 0) {
		new_level__ = blk1_4.p[arrays_1.startn[arc - 1] - 1] - 
			arrayrc_1.rc[arc - 1];
		if (new_level__ > bstlevel) {
		    bstlevel = new_level__;
		    extarc = -arc;
		}
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L154;
	}
	blk15_2.extend_arc__[node - 1] = extarc;
	blk1_4.p[node - 1] = bstlevel - eps;
/* L150: */
    }

/*     START THE AUGMENTATION CYCLES OF THE NEW SCALING PHASE. */

L200:
    if (arrayb_2.dfct[root - 1] >= thresh_dfct__) {
	goto L3000;
    }
    term = root;
    blk9_2.path_id__[root - 1] = TRUE_;

/*     MAIN FORWARD ALGORITHM WITH ROOT AS ORIGIN. */

L500:
/*     START OF A NEW FORWARD ITERATION */

    pterm = blk1_4.p[term - 1];
    extarc = blk15_2.extend_arc__[term - 1];
    if (extarc == 0) {

/*     BUILD THE LIST OF ARCS W/ ROOM FOR PUSHING FLOW */

	blk10_2.fpushf[term - 1] = 0;
	arc = blk3_2.fou[term - 1];
L502:
	if (arc > 0) {
	    if (arrayu_1.u[arc - 1] > 0) {
		if (blk10_2.fpushf[term - 1] == 0) {
		    blk10_2.fpushf[term - 1] = arc;
		    blk11_2.nxtpushf[arc - 1] = 0;
		    last = arc;
		} else {
		    blk11_2.nxtpushf[last - 1] = arc;
		    blk11_2.nxtpushf[arc - 1] = 0;
		    last = arc;
		}
	    }
	    arc = blk4_2.nxtou[arc - 1];
	    goto L502;
	}

	blk12_2.fpushb[term - 1] = 0;
	arc = blk5_2.fin[term - 1];
L504:
	if (arc > 0) {
	    if (arrayx_1.x[arc - 1] > 0) {
		if (blk12_2.fpushb[term - 1] == 0) {
		    blk12_2.fpushb[term - 1] = arc;
		    blk13_2.nxtpushb[arc - 1] = 0;
		    last = arc;
		} else {
		    blk13_2.nxtpushb[last - 1] = arc;
		    blk13_2.nxtpushb[arc - 1] = 0;
		    last = arc;
		}
	    }
	    arc = blk6_2.nxtin[arc - 1];
	    goto L504;
	}
	goto L600;
    }

/*     SPECULATIVE PATH EXTENSION ATTEMPT */
/*     NOTE: ARC>0 MEANS THAT ARC IS ORIENTED FROM THE ROOT TO THE DESTINATIONS */
/*     ARC<0 MEANS THAT ARC IS ORIENTED FROM THE DESTINATIONS TO THE ROOT */
/*     EXTARC=0 OR PRDARC=0, MEANS THE EXTENSION ARC OR THE PREDECESSOR ARC, */
/*     RESPECTIVELY, HAS NOT BEEN ESTABLISHED */

/* L510: */
    if (extarc > 0) {
	if (arrayu_1.u[extarc - 1] == 0) {
	    seclevel = blk16_2.sb_level__[term - 1];
	    goto L580;
	}
	end = arraye_1.endn[extarc - 1];
	bstlevel = blk1_4.p[end - 1] + arrayrc_1.rc[extarc - 1];
	if (pterm >= bstlevel) {
	    if (blk9_2.path_id__[end - 1]) {
		goto L1200;
	    }
	    term = end;
	    blk2_3.prdcsr[term - 1] = extarc;
	    blk9_2.path_id__[term - 1] = TRUE_;

/*     IF NEGATIVE SURPLUS NODE IS FOUND, DO AN AUGMENTATION */

	    if (arrayb_2.dfct[term - 1] > 0) {
		goto L2000;
	    }

/*     RETURN FOR ANOTHER ITERATION */

	    goto L500;
	}
    } else {
	extarc = -extarc;
	if (arrayx_1.x[extarc - 1] == 0) {
	    seclevel = blk16_2.sb_level__[term - 1];
	    goto L580;
	}
	start = arrays_1.startn[extarc - 1];
	bstlevel = blk1_4.p[start - 1] - arrayrc_1.rc[extarc - 1];
	if (pterm >= bstlevel) {
	    if (blk9_2.path_id__[start - 1]) {
		goto L1200;
	    }
	    term = start;
	    blk2_3.prdcsr[term - 1] = -extarc;
	    blk9_2.path_id__[term - 1] = TRUE_;

/*     IF NEGATIVE SURPLUS NODE IS FOUND, DO AN AUGMENTATION */

	    if (arrayb_2.dfct[term - 1] > 0) {
		goto L2000;
	    }

/*     RETURN FOR ANOTHER ITERATION */

	    goto L500;
	}
    }

/*     SECOND BEST LOGIC TEST APPLIED TO SAVE A FULL NODE SCAN */
/*     IF OLD BEST LEVEL CONTINUES TO BE BEST GO FOR ANOTHER CONTRACTION */

L550:
    seclevel = blk16_2.sb_level__[term - 1];
    if (bstlevel <= seclevel) {
	goto L800;
    }

/*     IF SECOND BEST CAN BE USED DO EITHER A CONTRACTION */
/*     OR START OVER WITH A SPECULATIVE EXTENSION */

L580:
    if (seclevel > -input_1.large) {
	extarc = blk17_2.sb_arc__[term - 1];
	if (extarc > 0) {
	    if (arrayu_1.u[extarc - 1] == 0) {
		goto L600;
	    }
	    bstlevel = blk1_4.p[arraye_1.endn[extarc - 1] - 1] + arrayrc_1.rc[
		    extarc - 1];
	} else {
	    if (arrayx_1.x[-extarc - 1] == 0) {
		goto L600;
	    }
	    bstlevel = blk1_4.p[arrays_1.startn[-extarc - 1] - 1] - 
		    arrayrc_1.rc[-extarc - 1];
	}
	if (bstlevel == seclevel) {
	    blk16_2.sb_level__[term - 1] = -input_1.large;
	    blk15_2.extend_arc__[term - 1] = extarc;
	    goto L800;
	}
    }

/*     EXTENSION/CONTRACTION ATTEMPT WAS UNSUCCESSFUL, SO SCAN TERMINAL NODE */

L600:
    ++output_1.nsp;
    bstlevel = input_1.large;
    seclevel = input_1.large;
    arc = blk10_2.fpushf[term - 1];
L700:
    if (arc > 0) {
	new_level__ = blk1_4.p[arraye_1.endn[arc - 1] - 1] + arrayrc_1.rc[arc 
		- 1];
	if (new_level__ < seclevel) {
	    if (new_level__ < bstlevel) {
		seclevel = bstlevel;
		bstlevel = new_level__;
		secarc = extarc;
		extarc = arc;
	    } else {
		seclevel = new_level__;
		secarc = arc;
	    }
	}
	arc = blk11_2.nxtpushf[arc - 1];
	goto L700;
    }
    arc = blk12_2.fpushb[term - 1];
L710:
    if (arc > 0) {
	new_level__ = blk1_4.p[arrays_1.startn[arc - 1] - 1] - arrayrc_1.rc[
		arc - 1];
	if (new_level__ < seclevel) {
	    if (new_level__ < bstlevel) {
		seclevel = bstlevel;
		bstlevel = new_level__;
		secarc = extarc;
		extarc = -arc;
	    } else {
		seclevel = new_level__;
		secarc = -arc;
	    }
	}
	arc = blk13_2.nxtpushb[arc - 1];
	goto L710;
    }
    blk16_2.sb_level__[term - 1] = seclevel;
    blk17_2.sb_arc__[term - 1] = secarc;
    blk15_2.extend_arc__[term - 1] = extarc;

/*     END OF NODE SCAN. */
/*     IF THE TERMINAL NODE IS THE ROOT, ADJUST ITS PRICE AND CHANGE ROOT */

L800:
    if (term == root) {
	blk1_4.p[term - 1] = bstlevel + eps;
	if (pterm >= input_1.large) {
	    s_wsle(&io___127);
	    do_lio(&c__9, &c__1, "NO PATH TO THE DESTINATION", (ftnlen)26);
	    e_wsle();
	    s_wsle(&io___128);
	    do_lio(&c__9, &c__1, " PROBLEM IS FOUND TO BE INFEASIBLE.", (
		    ftnlen)35);
	    e_wsle();
	    s_wsle(&io___129);
	    do_lio(&c__9, &c__1, "PROGRAM ENDED; PRESS <CR> TO EXIT", (ftnlen)
		    33);
	    e_wsle();
	    s_paus("", (ftnlen)0);
	    s_stop("", (ftnlen)0);
	}
	blk9_2.path_id__[root - 1] = FALSE_;
	prevnode = root;
	root = blk14_2.nxtqueue[root - 1];
	goto L200;
    }

/*     CHECK WHETHER EXTENSION OR CONTRACTION */

    prd = blk2_3.prdcsr[term - 1];
    if (prd > 0) {
	pr_term__ = arrays_1.startn[prd - 1];
	prevlevel = blk1_4.p[pr_term__ - 1] - arrayrc_1.rc[prd - 1];
    } else {
	pr_term__ = arraye_1.endn[-prd - 1];
	prevlevel = blk1_4.p[pr_term__ - 1] + arrayrc_1.rc[-prd - 1];
    }

    if (prevlevel > bstlevel) {

/*     PATH EXTENSION */

	if (prevlevel >= bstlevel + eps) {
	    blk1_4.p[term - 1] = bstlevel + eps;
	} else {
	    blk1_4.p[term - 1] = prevlevel;
	}
	if (extarc > 0) {
	    end = arraye_1.endn[extarc - 1];
	    if (blk9_2.path_id__[end - 1]) {
		goto L1200;
	    }
	    term = end;
	} else {
	    start = arrays_1.startn[-extarc - 1];
	    if (blk9_2.path_id__[start - 1]) {
		goto L1200;
	    }
	    term = start;
	}
	blk2_3.prdcsr[term - 1] = extarc;
	blk9_2.path_id__[term - 1] = TRUE_;

/*     IF NEGATIVE SURPLUS NODE IS FOUND, DO AN AUGMENTATION */

	if (arrayb_2.dfct[term - 1] > 0) {
	    goto L2000;
	}

/*     RETURN FOR ANOTHER ITERATION */

	goto L500;
    } else {

/*     PATH CONTRACTION. */

	blk1_4.p[term - 1] = bstlevel + eps;
	blk9_2.path_id__[term - 1] = FALSE_;
	term = pr_term__;
	if (pr_term__ != root) {
	    if (bstlevel <= pterm + eps) {
		goto L2000;
	    }
	}
	pterm = blk1_4.p[term - 1];
	extarc = prd;
	if (prd > 0) {
	    bstlevel = bstlevel + eps + arrayrc_1.rc[prd - 1];
	} else {
	    bstlevel = bstlevel + eps - arrayrc_1.rc[-prd - 1];
	}

/*     DO A SECOND BEST TEST AND IF THAT FAILS, DO A FULL NODE SCAN */

	goto L550;
    }

/*     A CYCLE IS ABOUT TO FORM; DO A RETREAT SEQUENCE. */

L1200:

    node = term;
L1600:
    if (node != root) {
	blk9_2.path_id__[node - 1] = FALSE_;
	prd = blk2_3.prdcsr[node - 1];
	if (prd > 0) {
	    pr_term__ = arrays_1.startn[prd - 1];
	    if (blk1_4.p[pr_term__ - 1] == blk1_4.p[node - 1] + arrayrc_1.rc[
		    prd - 1] + eps) {
		node = pr_term__;
		goto L1600;
	    }
	} else {
	    pr_term__ = arraye_1.endn[-prd - 1];
	    if (blk1_4.p[pr_term__ - 1] == blk1_4.p[node - 1] - arrayrc_1.rc[
		    -prd - 1] + eps) {
		node = pr_term__;
		goto L1600;
	    }
	}

/*     DO A FULL SCAN AND PRICE RISE AT PR_TERM */

	++output_1.nsp;
	bstlevel = input_1.large;
	seclevel = input_1.large;
	arc = blk10_2.fpushf[pr_term__ - 1];
L1700:
	if (arc > 0) {
	    new_level__ = blk1_4.p[arraye_1.endn[arc - 1] - 1] + arrayrc_1.rc[
		    arc - 1];
	    if (new_level__ < seclevel) {
		if (new_level__ < bstlevel) {
		    seclevel = bstlevel;
		    bstlevel = new_level__;
		    secarc = extarc;
		    extarc = arc;
		} else {
		    seclevel = new_level__;
		    secarc = arc;
		}
	    }
	    arc = blk11_2.nxtpushf[arc - 1];
	    goto L1700;
	}

	arc = blk12_2.fpushb[pr_term__ - 1];
L1710:
	if (arc > 0) {
	    new_level__ = blk1_4.p[arrays_1.startn[arc - 1] - 1] - 
		    arrayrc_1.rc[arc - 1];
	    if (new_level__ < seclevel) {
		if (new_level__ < bstlevel) {
		    seclevel = bstlevel;
		    bstlevel = new_level__;
		    secarc = extarc;
		    extarc = -arc;
		} else {
		    seclevel = new_level__;
		    secarc = -arc;
		}
	    }
	    arc = blk13_2.nxtpushb[arc - 1];
	    goto L1710;
	}
	blk16_2.sb_level__[pr_term__ - 1] = seclevel;
	blk17_2.sb_arc__[pr_term__ - 1] = secarc;
	blk15_2.extend_arc__[pr_term__ - 1] = extarc;
	blk1_4.p[pr_term__ - 1] = bstlevel + eps;
	if (pr_term__ == root) {
	    prevnode = root;
	    blk9_2.path_id__[root - 1] = FALSE_;
	    root = blk14_2.nxtqueue[root - 1];
	    goto L200;
	}
	blk9_2.path_id__[pr_term__ - 1] = FALSE_;
	prd = blk2_3.prdcsr[pr_term__ - 1];
	if (prd > 0) {
	    term = arrays_1.startn[prd - 1];
	} else {
	    term = arraye_1.endn[-prd - 1];
	}
	if (term == root) {
	    prevnode = root;
	    blk9_2.path_id__[root - 1] = FALSE_;
	    root = blk14_2.nxtqueue[root - 1];
	    goto L200;
	} else {
	    goto L2000;
	}
    }

/*     END OF AUCTION/SHORTEST PATH ROUTINE. */
/*     DO AUGMENTATION FROM ROOT AND CORRECT THE PUSH LISTS */

L2000:
    incr = -arrayb_2.dfct[root - 1];
    node = root;
L2050:
    extarc = blk15_2.extend_arc__[node - 1];
    blk9_2.path_id__[node - 1] = FALSE_;
    if (extarc > 0) {
	node = arraye_1.endn[extarc - 1];
	if (incr > arrayu_1.u[extarc - 1]) {
	    incr = arrayu_1.u[extarc - 1];
	}
    } else {
	node = arrays_1.startn[-extarc - 1];
	if (incr > arrayx_1.x[-extarc - 1]) {
	    incr = arrayx_1.x[-extarc - 1];
	}
    }
    if (node != term) {
	goto L2050;
    }
    blk9_2.path_id__[term - 1] = FALSE_;
    if (arrayb_2.dfct[term - 1] > 0) {
	if (incr > arrayb_2.dfct[term - 1]) {
	    incr = arrayb_2.dfct[term - 1];
	}
    }

    node = root;
L2100:
    extarc = blk15_2.extend_arc__[node - 1];
    if (extarc > 0) {
	end = arraye_1.endn[extarc - 1];

/*     ADD ARC TO THE REDUCED GRAPH */

	if (arrayx_1.x[extarc - 1] == 0) {
	    blk13_2.nxtpushb[extarc - 1] = blk12_2.fpushb[end - 1];
	    blk12_2.fpushb[end - 1] = extarc;
	    new_level__ = blk1_4.p[node - 1] - arrayrc_1.rc[extarc - 1];
	    if (blk16_2.sb_level__[end - 1] > new_level__) {
		blk16_2.sb_level__[end - 1] = new_level__;
		blk17_2.sb_arc__[end - 1] = -extarc;
	    }
	}
	arrayx_1.x[extarc - 1] += incr;
	arrayu_1.u[extarc - 1] -= incr;

/*    REMOVE ARC FROM THE REDUCED GRAPH */

	if (arrayu_1.u[extarc - 1] == 0) {
	    ++nas;
	    arc = blk10_2.fpushf[node - 1];
	    if (arc == extarc) {
		blk10_2.fpushf[node - 1] = blk11_2.nxtpushf[arc - 1];
	    } else {
		prevarc = arc;
		arc = blk11_2.nxtpushf[arc - 1];
L2200:
		if (arc > 0) {
		    if (arc == extarc) {
			blk11_2.nxtpushf[prevarc - 1] = blk11_2.nxtpushf[arc 
				- 1];
			goto L2250;
		    }
		    prevarc = arc;
		    arc = blk11_2.nxtpushf[arc - 1];
		    goto L2200;
		}
	    }
	}
L2250:
	node = end;
    } else {
	extarc = -extarc;
	start = arrays_1.startn[extarc - 1];

/*    ADD ARC TO THE REDUCED GRAPH */

	if (arrayu_1.u[extarc - 1] == 0) {
	    blk11_2.nxtpushf[extarc - 1] = blk10_2.fpushf[start - 1];
	    blk10_2.fpushf[start - 1] = extarc;
	    new_level__ = blk1_4.p[node - 1] + arrayrc_1.rc[extarc - 1];
	    if (blk16_2.sb_level__[start - 1] > new_level__) {
		blk16_2.sb_level__[start - 1] = new_level__;
		blk17_2.sb_arc__[start - 1] = extarc;
	    }
	}
	arrayu_1.u[extarc - 1] += incr;
	arrayx_1.x[extarc - 1] -= incr;

/*    REMOVE ARC FROM THE REDUCED GRAPH */

	if (arrayx_1.x[extarc - 1] == 0) {
	    ++nas;
	    arc = blk12_2.fpushb[node - 1];
	    if (arc == extarc) {
		blk12_2.fpushb[node - 1] = blk13_2.nxtpushb[arc - 1];
	    } else {
		prevarc = arc;
		arc = blk13_2.nxtpushb[arc - 1];
L2300:
		if (arc > 0) {
		    if (arc == extarc) {
			blk13_2.nxtpushb[prevarc - 1] = blk13_2.nxtpushb[arc 
				- 1];
			goto L2350;
		    }
		    prevarc = arc;
		    arc = blk13_2.nxtpushb[arc - 1];
		    goto L2300;
		}
	    }
	}
L2350:
	node = start;
    }
    if (node != term) {
	goto L2100;
    }
    arrayb_2.dfct[term - 1] -= incr;
    arrayb_2.dfct[root - 1] += incr;

/*     INSERT TERM IN THE QUEUE IF IT HAS A LARGE ENOUGH SURPLUS */

    if (arrayb_2.dfct[term - 1] < thresh_dfct__) {
	if (blk14_2.nxtqueue[term - 1] == 0) {
	    nxtnode = blk14_2.nxtqueue[root - 1];
	    if (blk1_4.p[term - 1] >= blk1_4.p[nxtnode - 1] && root != 
		    nxtnode) {
		blk14_2.nxtqueue[root - 1] = term;
		blk14_2.nxtqueue[term - 1] = nxtnode;
	    } else {
		blk14_2.nxtqueue[prevnode - 1] = term;
		blk14_2.nxtqueue[term - 1] = root;
		prevnode = term;
	    }
	}
    }

/*     IF ROOT HAS A LARGE ENOUGH SURPLUS, KEEP IT */
/*     IN THE QUEUE AND RETURN FOR ANOTHER ITERATION */

    if (arrayb_2.dfct[root - 1] < thresh_dfct__) {
	prevnode = root;
	root = blk14_2.nxtqueue[root - 1];
	goto L200;
    }

/*     END OF AUGMENTATION CYCLE */

L3000:

/*     CHECK FOR TERMINATION OF SCALING PHASE. IF SCALING PHASE IS */
/*     NOT FINISHED, ADVANCE THE QUEUE AND RETURN TO TAKE ANOTHER NODE. */

    nxtnode = blk14_2.nxtqueue[root - 1];
    if (root != nxtnode) {
	blk14_2.nxtqueue[root - 1] = 0;
	blk14_2.nxtqueue[prevnode - 1] = nxtnode;
	root = nxtnode;
	goto L200;
    }

/*     END OF SUBPROBLEM (SCALING PHASE). */

/* L3600: */

/*     REDUCE EPSILON. */

    eps /= factor;
    if (eps < 1) {
	eps = 1;
    }
    thresh_dfct__ /= factor;
    if (eps == 1) {
	thresh_dfct__ = 0;
    }

/*     IF ANOTHER AUCTION SCALING PHASE REMAINS, RESET THE FLOWS & THE PUSH LISTS */
/*     ELSE RESET ARC FLOWS TO SATISFY CS AND COMPUTE REDUCED COSTS */

    if (cr_1.crash == 1) {
	i__1 = input_1.na;
	for (arc = 1; arc <= i__1; ++arc) {
	    start = arrays_1.startn[arc - 1];
	    end = arraye_1.endn[arc - 1];
	    pstart = blk1_4.p[start - 1];
	    pend = blk1_4.p[end - 1];
	    if (pstart > pend + eps + arrayrc_1.rc[arc - 1]) {
		resid = arrayu_1.u[arc - 1];
		if (resid > 0) {
		    arrayb_2.dfct[start - 1] += resid;
		    arrayb_2.dfct[end - 1] -= resid;
		    arrayx_1.x[arc - 1] += resid;
		    arrayu_1.u[arc - 1] = 0;
		}
	    } else {
		if (pstart < pend - eps + arrayrc_1.rc[arc - 1]) {
		    flow = arrayx_1.x[arc - 1];
		    if (flow > 0) {
			arrayb_2.dfct[start - 1] -= flow;
			arrayb_2.dfct[end - 1] += flow;
			arrayx_1.x[arc - 1] = 0;
			arrayu_1.u[arc - 1] += flow;
		    }
		}
	    }
/* L3800: */
	}

/*     RETURN FOR ANOTHER PHASE */

/* L3850: */
	goto L100;
    } else {
	cr_1.crash = 1;
	i__1 = input_1.na;
	for (arc = 1; arc <= i__1; ++arc) {
	    start = arrays_1.startn[arc - 1];
	    end = arraye_1.endn[arc - 1];
	    red_cost__ = arrayrc_1.rc[arc - 1] + blk1_4.p[end - 1] - blk1_4.p[
		    start - 1];
	    if (red_cost__ < 0) {
		resid = arrayu_1.u[arc - 1];
		if (resid > 0) {
		    arrayb_2.dfct[start - 1] += resid;
		    arrayb_2.dfct[end - 1] -= resid;
		    arrayx_1.x[arc - 1] += resid;
		    arrayu_1.u[arc - 1] = 0;
		}
	    } else {
		if (red_cost__ > 0) {
		    flow = arrayx_1.x[arc - 1];
		    if (flow > 0) {
			arrayb_2.dfct[start - 1] -= flow;
			arrayb_2.dfct[end - 1] += flow;
			arrayx_1.x[arc - 1] = 0;
			arrayu_1.u[arc - 1] += flow;
		    }
		}
	    }
	    arrayrc_1.rc[arc - 1] = red_cost__;
/* L3900: */
	}
    }
    return 0;
} /* auction_ */



/* Subroutine */ int printflows_(integer *node)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static integer arc;

    /* Fortran I/O blocks */
    static cilist io___142 = { 0, 6, 0, 0, 0 };
    static cilist io___143 = { 0, 6, 0, 0, 0 };
    static cilist io___144 = { 0, 6, 0, 0, 0 };
    static cilist io___146 = { 0, 6, 0, 0, 0 };
    static cilist io___147 = { 0, 6, 0, 0, 0 };
    static cilist io___148 = { 0, 6, 0, 0, 0 };
    static cilist io___149 = { 0, 6, 0, 0, 0 };
    static cilist io___150 = { 0, 6, 0, 0, 0 };
    static cilist io___151 = { 0, 6, 0, 0, 0 };
    static cilist io___152 = { 0, 6, 0, 0, 0 };



/* --------------------------------------------------------------- */

/*  PURPOSE - THIS ROUTINE PRINTS THE DEFICIT AND THE FLOWS */
/*     OF ARCS INCIDENT TO NODE.  IT IS USED FOR DIAGNOSTIC */
/*     PURPOSES IN CASE OF AN INFEASIBLE PROBLEM HERE. */
/*     IT CAN BE USED ALSO FOR MORE GENERAL DIAGNOSTIC */
/*     PURPOSES. */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */




/* --------------------------------------------------------------- */

    s_wsle(&io___142);
    do_lio(&c__9, &c__1, "DEFICIT (I.E., NET FLOW OUT) OF NODE =", (ftnlen)38)
	    ;
    do_lio(&c__3, &c__1, (char *)&arrayb_2.dfct[*node - 1], (ftnlen)sizeof(
	    integer));
    e_wsle();
    s_wsle(&io___143);
    do_lio(&c__9, &c__1, "FLOWS AND CAPACITIES OF INCIDENT ARCS OF NODE", (
	    ftnlen)45);
    do_lio(&c__3, &c__1, (char *)&(*node), (ftnlen)sizeof(integer));
    e_wsle();

/*     CHECK ALL ARCS LEAVING NODE */

    if (blk3_2.fou[*node - 1] == 0) {
	s_wsle(&io___144);
	do_lio(&c__9, &c__1, "NO OUTGOING ARCS", (ftnlen)16);
	e_wsle();
    } else {
	arc = blk3_2.fou[*node - 1];
L5:
	if (arc > 0) {
	    s_wsle(&io___146);
	    do_lio(&c__9, &c__1, "ARC", (ftnlen)3);
	    do_lio(&c__3, &c__1, (char *)&arc, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, "  BETWEEN NODES", (ftnlen)15);
	    do_lio(&c__3, &c__1, (char *)&(*node), (ftnlen)sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&arraye_1.endn[arc - 1], (ftnlen)
		    sizeof(integer));
	    e_wsle();
	    s_wsle(&io___147);
	    do_lio(&c__9, &c__1, "FLOW =", (ftnlen)6);
	    do_lio(&c__3, &c__1, (char *)&arrayx_1.x[arc - 1], (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    s_wsle(&io___148);
	    do_lio(&c__9, &c__1, "RESIDUAL CAPACITY =", (ftnlen)19);
	    do_lio(&c__3, &c__1, (char *)&arrayu_1.u[arc - 1], (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    arc = blk4_2.nxtou[arc - 1];
	    goto L5;
	}
    }

/*     CHECK ALL ARCS INCOMING TO NODE */

    if (blk5_2.fin[*node - 1] == 0) {
	s_wsle(&io___149);
	do_lio(&c__9, &c__1, "NO INCOMING ARCS", (ftnlen)16);
	e_wsle();
    } else {
	arc = blk5_2.fin[*node - 1];
L10:
	if (arc > 0) {
	    s_wsle(&io___150);
	    do_lio(&c__9, &c__1, "ARC", (ftnlen)3);
	    do_lio(&c__3, &c__1, (char *)&arc, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, "  BETWEEN NODES", (ftnlen)15);
	    do_lio(&c__3, &c__1, (char *)&arrays_1.startn[arc - 1], (ftnlen)
		    sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&(*node), (ftnlen)sizeof(integer));
	    e_wsle();
	    s_wsle(&io___151);
	    do_lio(&c__9, &c__1, "FLOW =", (ftnlen)6);
	    do_lio(&c__3, &c__1, (char *)&arrayx_1.x[arc - 1], (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    s_wsle(&io___152);
	    do_lio(&c__9, &c__1, "RESIDUAL CAPACITY =", (ftnlen)19);
	    do_lio(&c__3, &c__1, (char *)&arrayu_1.u[arc - 1], (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    arc = blk6_2.nxtin[arc - 1];
	    goto L10;
	}
    }

    return 0;
} /* printflows_ */



/* Subroutine */ int ascnt1_(integer *dm, integer *delx, integer *nlabel, 
	logical1 *feasbl, logical1 *switch__, integer *nscan, integer *
	curnode, integer *prevnode)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, t1, t2, t3, nb, arc, dlx, node, node2, nsave, 
	    delprc, rdcost;


/* --------------------------------------------------------------- */

/*  PURPOSE - THIS SUBROUTINE PERFORMS THE MULTI-NODE PRICE */
/*     ADJUSTMENT STEP FOR THE CASE WHERE THE SCANNED NODES */
/*     HAVE POSITIVE DEFICIT.  IT FIRST CHECKS IF DECREASING */
/*     THE PRICE OF THE SCANNED NODES INCREASES THE DUAL COST. */
/*     IF YES, THEN IT DECREASES THE PRICE OF ALL SCANNED NODES. */
/*     THERE ARE TWO POSSIBILITIES FOR PRICE DECREASE: */
/*     IF SWITCH=.TRUE., THEN THE SET OF SCANNED NODES */
/*     CORRESPONDS TO AN ELEMENTARY DIRECTION OF MAXIMAL */
/*     RATE OF ASCENT, IN WHICH CASE THE PRICE OF ALL SCANNED */
/*     NODES ARE DECREASED UNTIL THE NEXT BREAKPOINT IN THE */
/*     DUAL COST IS ENCOUNTERED.  AT THIS POINT, SOME ARC */
/*     BECOMES BALANCED AND MORE NODE(S) ARE ADDED TO THE */
/*     LABELED SET AND THE SUBROUTINE IS EXITED. */
/*     IF SWITCH=.FALSE., THEN THE PRICE OF ALL SCANNED NODES */
/*     ARE DECREASED UNTIL THE RATE OF ASCENT BECOMES */
/*     NEGATIVE (THIS CORRESPONDS TO THE PRICE ADJUSTMENT */
/*     STEP IN WHICH BOTH THE LINE SEARCH AND THE DEGENERATE */
/*     ASCENT ITERATION ARE IMPLEMENTED). */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */


/*  INPUT PARAMETERS */

/*     DM        = TOTAL DEFICIT OF SCANNED NODES */
/*     SWITCH    = .TRUE. IF LABELING IS TO CONTINUE AFTER PRICE CHANGE */
/*     NSCAN     = NUMBER OF SCANNED NODES */
/*     CURNODE   = MOST RECENTLY SCANNED NODE */
/*     N         = NUMBER OF NODES */
/*     NA        = NUMBER OF ARCS */
/*     LARGE     = A VERY LARGE INTEGER TO REPRESENT INFINITY */
/*                 (SEE NOTE 3) */
/*     STARTN(I) = STARTING NODE FOR THE I-TH ARC,    I = 1,...,NA */
/*     ENDN(I)   = ENDING NODE FOR THE I-TH ARC,      I = 1,...,NA */
/*     FOU(I)    = FIRST ARC LEAVING I-TH NODE,       I = 1,...,N */
/*     NXTOU(I)  = NEXT ARC LEAVING THE STARTING NODE OF J-TH ARC, */
/*                                                    I = 1,...,NA */
/*     FIN(I)    = FIRST ARC ENTERING I-TH NODE,      I = 1,...,N */
/*     NXTIN(I)  = NEXT ARC ENTERING THE ENDING NODE OF J-TH ARC, */
/*                                                    I = 1,...,NA */


/*  UPDATED PARAMETERS */

/*     DELX      = A LOWER ESTIMATE OF THE TOTAL FLOW ON BALANCED ARCS */
/*                 IN THE SCANNED-NODES CUT */
/*     NLABEL    = NUMBER OF LABELED NODES */
/*     FEASBL    = .FALSE. IF PROBLEM IS FOUND TO BE INFEASIBLE */
/*     PREVNODE  = THE NODE BEFORE CURNODE IN QUEUE */
/*     RC(J)     = REDUCED COST OF ARC J,             J = 1,...,NA */
/*     U(J)      = RESIDUAL CAPACITY OF ARC J, */
/*                                                    J = 1,...,NA */
/*     X(J)      = FLOW ON ARC J,                     J = 1,...,NA */
/*     DFCT(I)   = DEFICIT AT NODE I,                 I = 1,...,N */
/*     LABEL(K)  = K-TH NODE LABELED,                 K = 1,NLABEL */
/*     PRDCSR(I) = PREDECESSOR OF NODE I IN TREE OF LABELED NODES */
/*                 (O IF I IS UNLABELED),             I = 1,...,N */
/*     TFSTOU(I) = FIRST BALANCED ARC OUT OF NODE I,  I = 1,...,N */
/*     TNXTOU(J) = NEXT BALANCED ARC OUT OF THE STARTING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     TFSTIN(I) = FIRST BALANCED ARC INTO NODE I,  I = 1,...,N */
/*     TNXTIN(J) = NEXT BALANCED ARC INTO THE ENDING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     NXTQUEUE(I) = NODE FOLLOWING NODE I IN THE FIFO QUEUE */
/*                   (0 IF NODE IS NOT IN THE QUEUE), I = 1,...,N */
/*     SCAN(I)   = .TRUE. IF NODE I IS SCANNED,       I = 1,...,N */
/*     MARK(I)   = .TRUE. IF NODE I IS LABELED,       I = 1,...,N */


/*  WORKING PARAMETERS */


/*     STORE THE ARCS BETWEEN THE SET OF SCANNED NODES AND */
/*     ITS COMPLEMENT IN SAVE AND COMPUTE DELPRC, THE STEPSIZE */
/*     TO THE NEXT BREAKPOINT IN THE DUAL COST IN THE DIRECTION */
/*     OF DECREASING PRICES OF THE SCANNED NODES. */
/*     [THE ARCS ARE STORED INTO SAVE BY LOOKING AT THE ARCS */
/*     INCIDENT TO EITHER THE SET OF SCANNED NODES OR ITS */
/*     COMPLEMENT, DEPENDING ON WHETHER NSCAN>N/2 OR NOT. */
/*     THIS IMPROVES THE EFFICIENCY OF STORING.] */

    delprc = input_1.large;
    dlx = 0;
    nsave = 0;
    if (*nscan <= input_1.n / 2) {
	i__1 = *nscan;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    node = blk1_3.label[i__ - 1];
	    arc = blk3_2.fou[node - 1];
L500:
	    if (arc > 0) {

/*     ARC POINTS FROM SCANNED NODE TO AN UNSCANNED NODE. */

		node2 = arraye_1.endn[arc - 1];
		if (! blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node2 - 1] != arc) {
			dlx += arrayx_1.x[arc - 1];
		    }
		    if (rdcost < 0 && rdcost > -delprc) {
			delprc = -rdcost;
		    }
		}
		arc = blk4_2.nxtou[arc - 1];
		goto L500;
	    }
	    arc = blk5_2.fin[node - 1];
L501:
	    if (arc > 0) {

/*     ARC POINTS FROM UNSCANNED NODE TO SCANNED NODE. */

		node2 = arrays_1.startn[arc - 1];
		if (! blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = -arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node2 - 1] != -arc) {
			dlx += arrayu_1.u[arc - 1];
		    }
		    if (rdcost > 0 && rdcost < delprc) {
			delprc = rdcost;
		    }
		}
		arc = blk6_2.nxtin[arc - 1];
		goto L501;
	    }
/* L1: */
	}
    } else {
	i__1 = input_1.n;
	for (node = 1; node <= i__1; ++node) {
	    if (blk8_1.scan[node - 1]) {
		goto L2;
	    }
	    arc = blk5_2.fin[node - 1];
L502:
	    if (arc > 0) {
		node2 = arrays_1.startn[arc - 1];
		if (blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node - 1] != arc) {
			dlx += arrayx_1.x[arc - 1];
		    }
		    if (rdcost < 0 && rdcost > -delprc) {
			delprc = -rdcost;
		    }
		}
		arc = blk6_2.nxtin[arc - 1];
		goto L502;
	    }
	    arc = blk3_2.fou[node - 1];
L503:
	    if (arc > 0) {
		node2 = arraye_1.endn[arc - 1];
		if (blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = -arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node - 1] != -arc) {
			dlx += arrayu_1.u[arc - 1];
		    }
		    if (rdcost > 0 && rdcost < delprc) {
			delprc = rdcost;
		    }
		}
		arc = blk4_2.nxtou[arc - 1];
		goto L503;
	    }
L2:
	    ;
	}
    }

/*     CHECK IF THE SET OF SCANNED NODES TRULY CORRESPONDS */
/*     TO A DUAL ASCENT DIRECTION.  [HERE DELX+DLX IS THE EXACT */
/*     SUM OF THE FLOW ON ARCS FROM THE SCANNED SET TO THE */
/*     UNSCANNED SET PLUS THE (CAPACITY - FLOW) ON ARCS FROM */
/*     THE UNSCANNED SET TO THE SCANNED SET.] */
/*     IF THIS WERE NOT THE CASE, SET SWITCH TO .TRUE. */
/*     AND EXIT SUBROUTINE. */

    if (! (*switch__) && *delx + dlx >= *dm) {
	*switch__ = TRUE_;
	return 0;
    }
    *delx += dlx;

/*     CHECK THAT THE PROBLEM IS FEASIBLE. */

L4:
    if (delprc == input_1.large) {

/*     WE CAN INCREASE THE DUAL COST WITHOUT BOUND, SO */
/*     THE PRIMAL PROBLEM IS INFEASIBLE. */

	*feasbl = FALSE_;
	return 0;
    }

/*     DECREASE THE PRICES OF THE SCANNED NODES, ADD MORE */
/*     NODES TO THE LABELED SET AND CHECK IF A NEWLY LABELED NODE */
/*     HAS NEGATIVE DEFICIT. */

    if (*switch__) {
	i__1 = nsave;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    arc = blk7_2.save[i__ - 1];
	    if (arc > 0) {
		arrayrc_1.rc[arc - 1] += delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    node2 = arraye_1.endn[arc - 1];
		    if (blk11_1.tnxtou[arc - 1] < 0) {
			blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[
				arrays_1.startn[arc - 1] - 1];
			blk10_1.tfstou[arrays_1.startn[arc - 1] - 1] = arc;
		    }
		    if (blk13_1.tnxtin[arc - 1] < 0) {
			blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[node2 - 1];
			blk12_1.tfstin[node2 - 1] = arc;
		    }
		    if (! blk9_1.mark[node2 - 1]) {
			blk2_3.prdcsr[node2 - 1] = arc;
			++(*nlabel);
			blk1_3.label[*nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
		    }
		}
	    } else {
		arc = -arc;
		arrayrc_1.rc[arc - 1] -= delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    node2 = arrays_1.startn[arc - 1];
		    if (blk11_1.tnxtou[arc - 1] < 0) {
			blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[node2 - 1];
			blk10_1.tfstou[node2 - 1] = arc;
		    }
		    if (blk13_1.tnxtin[arc - 1] < 0) {
			blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[
				arraye_1.endn[arc - 1] - 1];
			blk12_1.tfstin[arraye_1.endn[arc - 1] - 1] = arc;
		    }
		    if (! blk9_1.mark[node2 - 1]) {
			blk2_3.prdcsr[node2 - 1] = -arc;
			++(*nlabel);
			blk1_3.label[*nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
		    }
		}
	    }
/* L7: */
	}
	return 0;
    } else {

/*     DECREASE THE PRICES OF THE SCANNED NODES BY DELPRC. */
/*     ADJUST FLOW TO MAINTAIN COMPLEMENTARY SLACKNESS WITH */
/*     THE PRICES. */

	nb = 0;
	i__1 = nsave;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    arc = blk7_2.save[i__ - 1];
	    if (arc > 0) {
		t1 = arrayrc_1.rc[arc - 1];
		if (t1 == 0) {
		    t2 = arrayx_1.x[arc - 1];
		    t3 = arrays_1.startn[arc - 1];
		    arrayb_2.dfct[t3 - 1] -= t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    t3 = arraye_1.endn[arc - 1];
		    arrayb_2.dfct[t3 - 1] += t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    arrayu_1.u[arc - 1] += t2;
		    arrayx_1.x[arc - 1] = 0;
		}
		arrayrc_1.rc[arc - 1] = t1 + delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    *delx += arrayx_1.x[arc - 1];
		    ++nb;
		    blk2_3.prdcsr[nb - 1] = arc;
		}
	    } else {
		arc = -arc;
		t1 = arrayrc_1.rc[arc - 1];
		if (t1 == 0) {
		    t2 = arrayu_1.u[arc - 1];
		    t3 = arrays_1.startn[arc - 1];
		    arrayb_2.dfct[t3 - 1] += t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    t3 = arraye_1.endn[arc - 1];
		    arrayb_2.dfct[t3 - 1] -= t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    arrayx_1.x[arc - 1] += t2;
		    arrayu_1.u[arc - 1] = 0;
		}
		arrayrc_1.rc[arc - 1] = t1 - delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    *delx += arrayu_1.u[arc - 1];
		    ++nb;
		    blk2_3.prdcsr[nb - 1] = arc;
		}
	    }
/* L6: */
	}
    }

    if (*delx <= *dm) {

/*     THE SET OF SCANNED NODES STILL CORRESPONDS TO A */
/*     DUAL (POSSIBLY DEGENERATE) ASCENT DIRECTON.  COMPUTE */
/*     THE STEPSIZE DELPRC TO THE NEXT BREAKPOINT IN THE */
/*     DUAL COST. */

	delprc = input_1.large;
	i__1 = nsave;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    arc = blk7_2.save[i__ - 1];
	    if (arc > 0) {
		rdcost = arrayrc_1.rc[arc - 1];
		if (rdcost < 0 && rdcost > -delprc) {
		    delprc = -rdcost;
		}
	    } else {
		arc = -arc;
		rdcost = arrayrc_1.rc[arc - 1];
		if (rdcost > 0 && rdcost < delprc) {
		    delprc = rdcost;
		}
	    }
/* L10: */
	}
	if (delprc != input_1.large || *delx < *dm) {
	    goto L4;
	}
    }

/*     ADD NEW BALANCED ARCS TO THE SUPERSET OF BALANCED ARCS. */

    i__1 = nb;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arc = blk2_3.prdcsr[i__ - 1];
	if (blk13_1.tnxtin[arc - 1] == -1) {
	    j = arraye_1.endn[arc - 1];
	    blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[j - 1];
	    blk12_1.tfstin[j - 1] = arc;
	}
	if (blk11_1.tnxtou[arc - 1] == -1) {
	    j = arrays_1.startn[arc - 1];
	    blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[j - 1];
	    blk10_1.tfstou[j - 1] = arc;
	}
/* L9: */
    }
    return 0;
} /* ascnt1_ */



/* Subroutine */ int ascnt2_(integer *dm, integer *delx, integer *nlabel, 
	logical1 *feasbl, logical1 *switch__, integer *nscan, integer *
	curnode, integer *prevnode)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, t1, t2, t3, nb, arc, dlx, node, node2, nsave, 
	    delprc, rdcost;


/* --------------------------------------------------------------- */

/*  PURPOSE - THIS ROUTINE IS ANALOGOUS TO ASCNT BUT FOR */
/*     THE CASE WHERE THE SCANNED NODES HAVE NEGATIVE DEFICIT. */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */



/*     STORE THE ARCS BETWEEN THE SET OF SCANNED NODES AND */
/*     ITS COMPLEMENT IN SAVE AND COMPUTE DELPRC, THE STEPSIZE */
/*     TO THE NEXT BREAKPOINT IN THE DUAL COST IN THE DIRECTION */
/*     OF INCREASING PRICES OF THE SCANNED NODES. */

    delprc = input_1.large;
    dlx = 0;
    nsave = 0;
    if (*nscan <= input_1.n / 2) {
	i__1 = *nscan;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    node = blk1_3.label[i__ - 1];
	    arc = blk5_2.fin[node - 1];
L500:
	    if (arc > 0) {
		node2 = arrays_1.startn[arc - 1];
		if (! blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node2 - 1] != arc) {
			dlx += arrayx_1.x[arc - 1];
		    }
		    if (rdcost < 0 && rdcost > -delprc) {
			delprc = -rdcost;
		    }
		}
		arc = blk6_2.nxtin[arc - 1];
		goto L500;
	    }
	    arc = blk3_2.fou[node - 1];
L501:
	    if (arc > 0) {
		node2 = arraye_1.endn[arc - 1];
		if (! blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = -arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node2 - 1] != -arc) {
			dlx += arrayu_1.u[arc - 1];
		    }
		    if (rdcost > 0 && rdcost < delprc) {
			delprc = rdcost;
		    }
		}
		arc = blk4_2.nxtou[arc - 1];
		goto L501;
	    }
/* L1: */
	}
    } else {
	i__1 = input_1.n;
	for (node = 1; node <= i__1; ++node) {
	    if (blk8_1.scan[node - 1]) {
		goto L2;
	    }
	    arc = blk3_2.fou[node - 1];
L502:
	    if (arc > 0) {
		node2 = arraye_1.endn[arc - 1];
		if (blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node - 1] != arc) {
			dlx += arrayx_1.x[arc - 1];
		    }
		    if (rdcost < 0 && rdcost > -delprc) {
			delprc = -rdcost;
		    }
		}
		arc = blk4_2.nxtou[arc - 1];
		goto L502;
	    }
	    arc = blk5_2.fin[node - 1];
L503:
	    if (arc > 0) {
		node2 = arrays_1.startn[arc - 1];
		if (blk8_1.scan[node2 - 1]) {
		    ++nsave;
		    blk7_2.save[nsave - 1] = -arc;
		    rdcost = arrayrc_1.rc[arc - 1];
		    if (rdcost == 0 && blk2_3.prdcsr[node - 1] != -arc) {
			dlx += arrayu_1.u[arc - 1];
		    }
		    if (rdcost > 0 && rdcost < delprc) {
			delprc = rdcost;
		    }
		}
		arc = blk6_2.nxtin[arc - 1];
		goto L503;
	    }
L2:
	    ;
	}
    }

    if (! (*switch__) && *delx + dlx >= -(*dm)) {
	*switch__ = TRUE_;
	return 0;
    }
    *delx += dlx;

/*     CHECK THAT THE PROBLEM IS FEASIBLE. */

L4:
    if (delprc == input_1.large) {
	*feasbl = FALSE_;
	return 0;
    }

/*     INCREASE THE PRICES OF THE SCANNED NODES, ADD MORE */
/*     NODES TO THE LABELED SET AND CHECK IF A NEWLY LABELED NODE */
/*     HAS POSITIVE DEFICIT. */

    if (*switch__) {
	i__1 = nsave;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    arc = blk7_2.save[i__ - 1];
	    if (arc > 0) {
		arrayrc_1.rc[arc - 1] += delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    node2 = arrays_1.startn[arc - 1];
		    if (blk11_1.tnxtou[arc - 1] < 0) {
			blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[node2 - 1];
			blk10_1.tfstou[node2 - 1] = arc;
		    }
		    if (blk13_1.tnxtin[arc - 1] < 0) {
			blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[
				arraye_1.endn[arc - 1] - 1];
			blk12_1.tfstin[arraye_1.endn[arc - 1] - 1] = arc;
		    }
		    if (! blk9_1.mark[node2 - 1]) {
			blk2_3.prdcsr[node2 - 1] = arc;
			++(*nlabel);
			blk1_3.label[*nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
		    }
		}
	    } else {
		arc = -arc;
		arrayrc_1.rc[arc - 1] -= delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    node2 = arraye_1.endn[arc - 1];
		    if (blk11_1.tnxtou[arc - 1] < 0) {
			blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[
				arrays_1.startn[arc - 1] - 1];
			blk10_1.tfstou[arrays_1.startn[arc - 1] - 1] = arc;
		    }
		    if (blk13_1.tnxtin[arc - 1] < 0) {
			blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[node2 - 1];
			blk12_1.tfstin[node2 - 1] = arc;
		    }
		    if (! blk9_1.mark[node2 - 1]) {
			blk2_3.prdcsr[node2 - 1] = -arc;
			++(*nlabel);
			blk1_3.label[*nlabel - 1] = node2;
			blk9_1.mark[node2 - 1] = TRUE_;
		    }
		}
	    }
/* L7: */
	}
	return 0;
    } else {
	nb = 0;
	i__1 = nsave;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    arc = blk7_2.save[i__ - 1];
	    if (arc > 0) {
		t1 = arrayrc_1.rc[arc - 1];
		if (t1 == 0) {
		    t2 = arrayx_1.x[arc - 1];
		    t3 = arrays_1.startn[arc - 1];
		    arrayb_2.dfct[t3 - 1] -= t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    t3 = arraye_1.endn[arc - 1];
		    arrayb_2.dfct[t3 - 1] += t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    arrayu_1.u[arc - 1] += t2;
		    arrayx_1.x[arc - 1] = 0;
		}
		arrayrc_1.rc[arc - 1] = t1 + delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    *delx += arrayx_1.x[arc - 1];
		    ++nb;
		    blk2_3.prdcsr[nb - 1] = arc;
		}
	    } else {
		arc = -arc;
		t1 = arrayrc_1.rc[arc - 1];
		if (t1 == 0) {
		    t2 = arrayu_1.u[arc - 1];
		    t3 = arrays_1.startn[arc - 1];
		    arrayb_2.dfct[t3 - 1] += t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    t3 = arraye_1.endn[arc - 1];
		    arrayb_2.dfct[t3 - 1] -= t2;
		    if (blk14_2.nxtqueue[t3 - 1] == 0) {
			blk14_2.nxtqueue[*prevnode - 1] = t3;
			blk14_2.nxtqueue[t3 - 1] = *curnode;
			*prevnode = t3;
		    }
		    arrayx_1.x[arc - 1] += t2;
		    arrayu_1.u[arc - 1] = 0;
		}
		arrayrc_1.rc[arc - 1] = t1 - delprc;
		if (arrayrc_1.rc[arc - 1] == 0) {
		    *delx += arrayu_1.u[arc - 1];
		    ++nb;
		    blk2_3.prdcsr[nb - 1] = arc;
		}
	    }
/* L6: */
	}
    }

    if (*delx <= -(*dm)) {
	delprc = input_1.large;
	i__1 = nsave;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    arc = blk7_2.save[i__ - 1];
	    if (arc > 0) {
		rdcost = arrayrc_1.rc[arc - 1];
		if (rdcost < 0 && rdcost > -delprc) {
		    delprc = -rdcost;
		}
	    } else {
		arc = -arc;
		rdcost = arrayrc_1.rc[arc - 1];
		if (rdcost > 0 && rdcost < delprc) {
		    delprc = rdcost;
		}
	    }
/* L10: */
	}
	if (delprc != input_1.large || *delx < -(*dm)) {
	    goto L4;
	}
    }

/*     ADD NEW BALANCED ARCS TO THE SUPERSET OF BALANCED ARCS. */

    i__1 = nb;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arc = blk2_3.prdcsr[i__ - 1];
	if (blk13_1.tnxtin[arc - 1] == -1) {
	    j = arraye_1.endn[arc - 1];
	    blk13_1.tnxtin[arc - 1] = blk12_1.tfstin[j - 1];
	    blk12_1.tfstin[j - 1] = arc;
	}
	if (blk11_1.tnxtou[arc - 1] == -1) {
	    j = arrays_1.startn[arc - 1];
	    blk11_1.tnxtou[arc - 1] = blk10_1.tfstou[j - 1];
	    blk10_1.tfstou[j - 1] = arc;
	}
/* L9: */
    }
    return 0;
} /* ascnt2_ */



#if 0
/* Subroutine */ int senstv_(void)
{
    /* Format strings */
    static char fmt_30[] = "(\002 INPUT 0 TO SOLVE THE MODIFIED PROBLEM\002)";
    static char fmt_40[] = "(\002       1 TO CHANGE NODE FLOW SUPPLY\002)";
    static char fmt_50[] = "(\002       2 TO CHANGE ARC FLOW UPPER BOUND\002)"
	    ;
    static char fmt_60[] = "(\002       3 TO CHANGE ARC COST\002)";
    static char fmt_70[] = "(\002       4 TO DELETE AN ARC\002)";
    static char fmt_80[] = "(\002       5 TO ADD AN ARC\002)";
    static char fmt_90[] = "(\002       6 TO DELETE LAST ARC\002,i8,\002 ADD"
	    "ED\002)";
    static char fmt_100[] = "(\002       7 TO RESTORE LAST ARC\002,i8,\002 D"
	    "ELETED\002)";
    static char fmt_105[] = "(\002       8 TO QUIT PROGRAM\002)";
    static char fmt_120[] = "(\002 INPUT NODE # WHERE FLOW SUPPLY IS INCREAS"
	    "ED\002)";
    static char fmt_130[] = "(\002 INPUT AMOUNT OF INCREASE (<0 VALUE ALLOWE"
	    "D)\002)";
    static char fmt_150[] = "(\002 INPUT NODE NO. WHERE FLOW SUPPLY IS DECRE"
	    "ASED\002)";
    static char fmt_170[] = "(\002 INPUT ARC NO. AND THE INCREASE IN UPPER B"
	    "OUND\002)";
    static char fmt_180[] = "(\002 FLOW UPPER BOUND IS NOW < 0\002)";
    static char fmt_200[] = "(\002 INPUT ARC NO. & INCREASE IN COST\002)";
    static char fmt_220[] = "(\002 INPUT ARC NO. FOR DELETION\002)";
    static char fmt_280[] = "(\002 INPUT HEAD & TAIL NODES OF NEW ARC\002,i8)"
	    ;
    static char fmt_300[] = "(\002 INPUT COST & FLOW UPPER BD\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen),
	     s_rsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, ic, ih, du, it, iu, del, arc, sel, arc1, arc2, aarc, 
	    delc, darc, iarc, node, node2, delub;
    extern /* Subroutine */ int addtr_(integer *);
    static integer nscan;
    static logical1 addarc, delarc;
    static integer nlabel, delsup;

    /* Fortran I/O blocks */
    static cilist io___180 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___181 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___182 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___183 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___184 = { 0, 6, 0, fmt_70, 0 };
    static cilist io___185 = { 0, 6, 0, fmt_80, 0 };
    static cilist io___187 = { 0, 6, 0, fmt_90, 0 };
    static cilist io___190 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___192 = { 0, 6, 0, fmt_105, 0 };
    static cilist io___193 = { 0, 5, 0, 0, 0 };
    static cilist io___195 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___196 = { 0, 5, 0, 0, 0 };
    static cilist io___198 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___199 = { 0, 5, 0, 0, 0 };
    static cilist io___201 = { 0, 6, 0, fmt_150, 0 };
    static cilist io___202 = { 0, 5, 0, 0, 0 };
    static cilist io___203 = { 0, 6, 0, fmt_170, 0 };
    static cilist io___204 = { 0, 5, 0, 0, 0 };
    static cilist io___207 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___209 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___210 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___211 = { 0, 6, 0, fmt_200, 0 };
    static cilist io___212 = { 0, 5, 0, 0, 0 };
    static cilist io___214 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___215 = { 0, 5, 0, 0, 0 };
    static cilist io___223 = { 0, 6, 0, fmt_280, 0 };
    static cilist io___224 = { 0, 5, 0, 0, 0 };
    static cilist io___225 = { 0, 6, 0, fmt_300, 0 };
    static cilist io___226 = { 0, 5, 0, 0, 0 };



/* --------------------------------------------------------------- */

/*  PURPOSE - THIS SUBROUTINE ALLOWS THE USER TO INTERACTIVELY */
/*     EITHER CHANGE NODE SUPPLY, OR CHANGE FLOW UPPER BOUND */
/*     OF AN EXISTING ARC, OR CHANGE COST OF AN EXISTING ARC, */
/*     OR DELETE AN EXISTING ARC, OR ADD AN ARC. */
/*     [NOTE: IF THE OPERATING SYSTEM RESETS ALL LOCAL VARIABLES */
/*     TO SOME DEFAULT VALUE EACH TIME THIS SUBROUTINE IS CALLED, */
/*     THEN THE USER MUST MAKE THE FOLLOWING CURRENTLY LOCAL */
/*     VARIABLES: */
/*           DELARC, DARC, DU, ADDARC, AARC */
/*     GLOBAL (BY EITHER PUTTING THEM IN A COMMON BLOCK OR */
/*     PASSING THEM THROUGH THE CALLING PARAMETER).] */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */


/*  INPUT PARAMETERS */

/*     N         = NUMBER OF NODES */
/*     NA        = NUMBER OF ARCS */
/*     LARGE     = A VERY LARGE INTEGER TO REPRESENT INFINITY */
/*     STARTN(J) = STARTING NODE FOR ARC J,           J = 1,...,NA */
/*     ENDN(J)   = ENDING NODE FOR ARC J,             J = 1,...,NA */
/*     FOU(I)    = FIRST ARC OUT OF NODE I,           I = 1,...,N */
/*     NXTOU(J)  = NEXT ARC OUT OF THE STARTING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     FIN(I)    = FIRST ARC INTO NODE I,             I = 1,...,N */
/*     NXTIN(J)  = NEXT ARC INTO THE ENDING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     REPEAT    = .TRUE. IF CAP(J)=X(J)+U(J), J=1,...,NA, ON INPUT */
/*                 (.FALSE. OTHERWISE) */


/*  UPDATED PARAMETERS */

/*     C(J)      = COST OF ARC J,                     J = 1,...,NA */
/*     CAP(J)    = CAPACITY OF ARC J,                 J = 1,...,NA */
/*     RC(J)     = REDUCED COST OF ARC J,             J = 1,...,NA */
/*     X(J)      = FLOW ON ARC J,                     J = 1,...,NA */
/*     U(J)      = CAP(J) - X(J) ON OUTPUT,           J = 1,...,NA */
/*     DFCT(I)   = DEMAND AT NODE I ON INPUT */
/*                 AND ZERO ON OUTPUT,                I = 1,...,N */
/*     TFSTOU(I) = FIRST BALANCED ARC OUT OF NODE I,  I = 1,...,N */
/*     TNXTOU(J) = NEXT BALANCED ARC OUT OF THE STARTING NODE OF ARC J, */
/*                                                    J = 1,...,NA */
/*     TFSTIN(I) = FIRST BALANCED ARC INTO NODE I,  I = 1,...,N */
/*     TNXTIN(J) = NEXT BALANCED ARC INTO THE ENDING NODE OF ARC J, */
/*                                                    J = 1,...,NA */


/*  WORKING PARAMETERS */


    if (! blkr_1.repeat) {

/*     RESTORE THE ARC CAPACITY TO THAT OF THE ORIGINAL PROBLEM */
/*     [RECALL THAT, IN SOLVING THE ORIGINAL PROBLEM, RELAX4 */
/*     MAY HAVE DECREASED THE ARC CAPACITIES DURING */
/*     INITIALIZATION PHASE I.]  THEN UPDATE FLOW AND THE */
/*     NODE DEFICITS TO MATCH THIS "NEW" CAPACITY. */

	i__1 = input_1.na;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (arrayrc_1.rc[i__ - 1] < 0) {
		arrayb_2.dfct[arrays_1.startn[i__ - 1] - 1] = arrayb_2.dfct[
			arrays_1.startn[i__ - 1] - 1] + blkcap_1.cap[i__ - 1] 
			- arrayx_1.x[i__ - 1];
		arrayb_2.dfct[arraye_1.endn[i__ - 1] - 1] = arrayb_2.dfct[
			arraye_1.endn[i__ - 1] - 1] - blkcap_1.cap[i__ - 1] + 
			arrayx_1.x[i__ - 1];
		arrayx_1.x[i__ - 1] = blkcap_1.cap[i__ - 1];
	    } else {
		arrayu_1.u[i__ - 1] = blkcap_1.cap[i__ - 1] - arrayx_1.x[i__ 
			- 1];
	    }
/* L10: */
	}
	blkr_1.repeat = TRUE_;
    }
L20:
    s_wsfe(&io___180);
    e_wsfe();
    s_wsfe(&io___181);
    e_wsfe();
    s_wsfe(&io___182);
    e_wsfe();
    s_wsfe(&io___183);
    e_wsfe();
    s_wsfe(&io___184);
    e_wsfe();
    s_wsfe(&io___185);
    e_wsfe();
    if (addarc) {
	s_wsfe(&io___187);
	do_fio(&c__1, (char *)&aarc, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (delarc) {
	s_wsfe(&io___190);
	do_fio(&c__1, (char *)&darc, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    s_wsfe(&io___192);
    e_wsfe();
    s_rsle(&io___193);
    do_lio(&c__3, &c__1, (char *)&sel, (ftnlen)sizeof(integer));
    e_rsle();
    if (sel == 8) {
	s_stop("", (ftnlen)0);
    } else if (sel == 0) {
	return 0;
    } else if (sel == 1) {

/*     CHANGE NODE FLOW SUPPLY. */

L110:
	s_wsfe(&io___195);
	e_wsfe();
	s_rsle(&io___196);
	do_lio(&c__3, &c__1, (char *)&node, (ftnlen)sizeof(integer));
	e_rsle();
	if (node <= 0 || node > input_1.n) {
	    goto L110;
	}
	s_wsfe(&io___198);
	e_wsfe();
	s_rsle(&io___199);
	do_lio(&c__3, &c__1, (char *)&delsup, (ftnlen)sizeof(integer));
	e_rsle();
	arrayb_2.dfct[node - 1] -= delsup;
L140:
	s_wsfe(&io___201);
	e_wsfe();
	s_rsle(&io___202);
	do_lio(&c__3, &c__1, (char *)&node, (ftnlen)sizeof(integer));
	e_rsle();
	if (node <= 0 || node > input_1.n) {
	    goto L140;
	}
	arrayb_2.dfct[node - 1] += delsup;
    } else if (sel == 2) {

/*     CHANGE ARC FLOW CAPACITY. */
/*     [NOTE: U IS THE RESIDUAL CAPACITY, I.E., U = CAPACITY - X.] */

L160:
	s_wsfe(&io___203);
	e_wsfe();
	s_rsle(&io___204);
	do_lio(&c__3, &c__1, (char *)&arc, (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&delub, (ftnlen)sizeof(integer));
	e_rsle();
	if (arc <= 0 || arc > input_1.na) {
	    goto L160;
	}
	if (arrayrc_1.rc[arc - 1] < 0) {

/*     ARC IS ACTIVE, SO MAINTAIN FLOW AT (NEW) CAPACITY. */

	    arrayb_2.dfct[arrays_1.startn[arc - 1] - 1] += delub;
	    arrayb_2.dfct[arraye_1.endn[arc - 1] - 1] -= delub;
	    arrayx_1.x[arc - 1] += delub;
	    if (arrayx_1.x[arc - 1] < 0) {
		s_wsfe(&io___207);
		e_wsfe();
	    }
	} else if (arrayrc_1.rc[arc - 1] == 0) {
	    if (arrayu_1.u[arc - 1] >= -delub) {
		arrayu_1.u[arc - 1] += delub;
	    } else {

/*     NEW CAPACITY IS LESS THAN CURRENT FLOW, SO DECREASE */
/*     FLOW TO NEW CAPACITY. */

		del = -delub - arrayu_1.u[arc - 1];
		arrayb_2.dfct[arrays_1.startn[arc - 1] - 1] -= del;
		arrayb_2.dfct[arraye_1.endn[arc - 1] - 1] += del;
		arrayx_1.x[arc - 1] -= del;
		if (arrayx_1.x[arc - 1] < 0) {
		    s_wsfe(&io___209);
		    e_wsfe();
		}
		arrayu_1.u[arc - 1] = 0;
	    }
	} else {
	    arrayu_1.u[arc - 1] += delub;
	    if (arrayu_1.u[arc - 1] < 0) {
		s_wsfe(&io___210);
		e_wsfe();
	    }
	}
    } else if (sel == 3) {

/*     CHANGE ARC COST. */

L190:
	s_wsfe(&io___211);
	e_wsfe();
	s_rsle(&io___212);
	do_lio(&c__3, &c__1, (char *)&arc, (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&delc, (ftnlen)sizeof(integer));
	e_rsle();
	if (arc <= 0 || arc > input_1.na) {
	    goto L190;
	}
	if (arrayrc_1.rc[arc - 1] >= 0 && arrayrc_1.rc[arc - 1] + delc < 0) {

/*     ARC BECOMES ACTIVE, SO INCREASE FLOW TO CAPACITY. */

	    arrayb_2.dfct[arrays_1.startn[arc - 1] - 1] += arrayu_1.u[arc - 1]
		    ;
	    arrayb_2.dfct[arraye_1.endn[arc - 1] - 1] -= arrayu_1.u[arc - 1];
	    arrayx_1.x[arc - 1] = arrayu_1.u[arc - 1] + arrayx_1.x[arc - 1];
	    arrayu_1.u[arc - 1] = 0;
	} else if (arrayrc_1.rc[arc - 1] <= 0 && arrayrc_1.rc[arc - 1] + delc 
		> 0) {

/*     ARC BECOMES INACTIVE, SO DECREASE FLOW TO ZERO. */

	    arrayb_2.dfct[arrays_1.startn[arc - 1] - 1] -= arrayx_1.x[arc - 1]
		    ;
	    arrayb_2.dfct[arraye_1.endn[arc - 1] - 1] += arrayx_1.x[arc - 1];
	    arrayu_1.u[arc - 1] += arrayx_1.x[arc - 1];
	    arrayx_1.x[arc - 1] = 0;
	}
	arrayrc_1.rc[arc - 1] += delc;
	arrayc_1.c__[arc - 1] += delc;

/*    IF ARC BECOMES BALANCED, CHECK TO ADD ARC TO TFSTOU, TFSTIN,.... */

	if (arrayrc_1.rc[arc - 1] == 0 && delc != 0) {
	    addtr_(&arc);
	}

    } else if (sel == 4 || sel == 6) {

/*     DELETE AN ARC. */

	if (sel == 6) {
	    if (! addarc) {
		goto L20;
	    }
	    addarc = FALSE_;
	    arc = aarc;
	} else {
L210:
	    s_wsfe(&io___214);
	    e_wsfe();
	    s_rsle(&io___215);
	    do_lio(&c__3, &c__1, (char *)&arc, (ftnlen)sizeof(integer));
	    e_rsle();
	    if (arc <= 0 || arc > input_1.na) {
		goto L210;
	    }
	    delarc = TRUE_;
	    darc = arc;
	    du = arrayu_1.u[arc - 1] + arrayx_1.x[arc - 1];
	}

/*     REMOVE ARC FROM THE ARRAY FIN, FOU, NXTIN, NXTOU. */

	arc1 = blk3_2.fou[arrays_1.startn[arc - 1] - 1];
	if (arc1 == arc) {
	    blk3_2.fou[arrays_1.startn[arc - 1] - 1] = blk4_2.nxtou[arc1 - 1];
	} else {
L230:
	    arc2 = blk4_2.nxtou[arc1 - 1];
	    if (arc2 == arc) {
		blk4_2.nxtou[arc1 - 1] = blk4_2.nxtou[arc2 - 1];
		goto L240;
	    }
	    arc1 = arc2;
	    if (blk4_2.nxtou[arc1 - 1] > 0) {
		goto L230;
	    }
	}
L240:
	arc1 = blk5_2.fin[arraye_1.endn[arc - 1] - 1];
	if (arc1 == arc) {
	    blk5_2.fin[arraye_1.endn[arc - 1] - 1] = blk6_2.nxtin[arc1 - 1];
	} else {
L250:
	    arc2 = blk6_2.nxtin[arc1 - 1];
	    if (arc2 == arc) {
		blk6_2.nxtin[arc1 - 1] = blk6_2.nxtin[arc2 - 1];
		goto L260;
	    }
	    arc1 = arc2;
	    if (blk6_2.nxtin[arc1 - 1] > 0) {
		goto L250;
	    }
	}

/*     REMOVE ARC FROM THE ARRAY TFSTIN, TFSTOU, TNXTIN, TNXTOU. */

L260:
	arc1 = blk10_1.tfstou[arrays_1.startn[arc - 1] - 1];
	if (arc1 == 0) {
	    goto L262;
	}
	if (arc1 == arc) {
	    blk10_1.tfstou[arrays_1.startn[arc - 1] - 1] = blk11_1.tnxtou[
		    arc1 - 1];
	} else {
L261:
	    arc2 = blk11_1.tnxtou[arc1 - 1];
	    if (arc2 == arc) {
		blk11_1.tnxtou[arc1 - 1] = blk11_1.tnxtou[arc2 - 1];
		goto L262;
	    }
	    arc1 = arc2;
	    if (blk11_1.tnxtou[arc1 - 1] > 0) {
		goto L261;
	    }
	}
L262:
	arc1 = blk12_1.tfstin[arraye_1.endn[arc - 1] - 1];
	if (arc1 == 0) {
	    goto L264;
	}
	if (arc1 == arc) {
	    blk12_1.tfstin[arraye_1.endn[arc - 1] - 1] = blk13_1.tnxtin[arc1 
		    - 1];
	} else {
L263:
	    arc2 = blk13_1.tnxtin[arc1 - 1];
	    if (arc2 == arc) {
		blk13_1.tnxtin[arc1 - 1] = blk13_1.tnxtin[arc2 - 1];
		goto L264;
	    }
	    arc1 = arc2;
	    if (blk13_1.tnxtin[arc1 - 1] > 0) {
		goto L263;
	    }
	}
L264:
	blk11_1.tnxtou[arc - 1] = -1;
	blk13_1.tnxtin[arc - 1] = -1;

/*     REMOVE FLOW OF ARC FROM NETWORK BY SETTING ITS FLOW */
/*     AND CAPACITY TO 0. */

	arrayb_2.dfct[arrays_1.startn[arc - 1] - 1] -= arrayx_1.x[arc - 1];
	arrayb_2.dfct[arraye_1.endn[arc - 1] - 1] += arrayx_1.x[arc - 1];
	arrayx_1.x[arc - 1] = 0;
	arrayu_1.u[arc - 1] = 0;
    } else if (sel == 5 || sel == 7) {
	if (sel == 7) {
	    if (! delarc) {
		goto L20;
	    }
	    iarc = darc;
	    ih = arrays_1.startn[iarc - 1];
	    it = arraye_1.endn[iarc - 1];
	    delarc = FALSE_;
	    iu = du;
	} else {
L270:
	    s_wsfe(&io___223);
	    i__1 = input_1.na + 1;
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_rsle(&io___224);
	    do_lio(&c__3, &c__1, (char *)&ih, (ftnlen)sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&it, (ftnlen)sizeof(integer));
	    e_rsle();
	    if (ih <= 0 || ih > input_1.n || it <= 0 || it > input_1.n) {
		goto L270;
	    }
L290:
	    s_wsfe(&io___225);
	    e_wsfe();
	    s_rsle(&io___226);
	    do_lio(&c__3, &c__1, (char *)&ic, (ftnlen)sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&iu, (ftnlen)sizeof(integer));
	    e_rsle();
	    if (iu < 0) {
		goto L290;
	    }
	    addarc = TRUE_;
	    aarc = input_1.na + 1;
	    ++input_1.na;
	    arrayc_1.c__[input_1.na - 1] = ic;
	    arrays_1.startn[input_1.na - 1] = ih;
	    arraye_1.endn[input_1.na - 1] = it;
	    iarc = input_1.na;
	}

/*     DETERMINE THE DUAL PRICES AT IH AND IT: */
/*     FIRST SET THE PRICE AT IH TO ZERO AND THEN CONSTRUCT THE */
/*     PRICE AT OTHER NODES BY BREADTH-FIRST SEARCH AND USING */
/*     THE FACT THAT */
/*     RC(ARC) = C(ARC) - PRICE(STARTN(ARC)) + PRICE(ENDN(ARC)). */
/*     THE NETWORK (GIVEN BY FOU, NXTOU, FIN, NXTIN) NEED NOT BE CONNECTED. */

	nscan = 0;
	nlabel = 1;
	blk1_3.label[0] = ih;
	blk2_4.price[ih - 1] = 0;
	i__1 = input_1.n;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L310: */
	    blk9_1.mark[i__ - 1] = FALSE_;
	}
	blk9_1.mark[ih - 1] = TRUE_;
L320:
	if (nlabel > nscan) {
	    ++nscan;
	    node = blk1_3.label[nscan - 1];
	    arc = blk3_2.fou[node - 1];
L330:
	    if (arc > 0) {
		node2 = arraye_1.endn[arc - 1];
		if (! blk9_1.mark[node2 - 1]) {
		    blk9_1.mark[node2 - 1] = TRUE_;
		    blk2_4.price[node2 - 1] = arrayrc_1.rc[arc - 1] - 
			    arrayc_1.c__[arc - 1] + blk2_4.price[node - 1];
		    if (node2 == it) {
			goto L370;
		    }
		    ++nlabel;
		    blk1_3.label[nlabel - 1] = node2;
		}
		arc = blk4_2.nxtou[arc - 1];
		goto L330;
	    }
	    arc = blk5_2.fin[node - 1];
L340:
	    if (arc > 0) {
		node2 = arrays_1.startn[arc - 1];
		if (! blk9_1.mark[node2 - 1]) {
		    blk9_1.mark[node2 - 1] = TRUE_;
		    blk2_4.price[node2 - 1] = arrayc_1.c__[arc - 1] - 
			    arrayrc_1.rc[arc - 1] + blk2_4.price[node - 1];
		    if (node2 == it) {
			goto L370;
		    }
		    ++nlabel;
		    blk1_3.label[nlabel - 1] = node2;
		}
		arc = blk6_2.nxtin[arc - 1];
		goto L340;
	    }
	    goto L320;
	}
	blk2_4.price[it - 1] = -arrayc_1.c__[iarc - 1];

/*     COMPUTE REDUCED COST OF THE NEW ARC AND UPDATE FLOW AND DEFICIT */
/*     ACCORDINGLY. */

L370:
	arrayrc_1.rc[iarc - 1] = arrayc_1.c__[iarc - 1] + blk2_4.price[it - 1]
		;
	if (arrayrc_1.rc[iarc - 1] < 0) {
	    arrayb_2.dfct[ih - 1] += iu;
	    arrayb_2.dfct[it - 1] -= iu;
	    arrayx_1.x[iarc - 1] = iu;
	    arrayu_1.u[iarc - 1] = 0;
	} else {
	    arrayx_1.x[iarc - 1] = 0;
	    arrayu_1.u[iarc - 1] = iu;
	}
	blk4_2.nxtou[iarc - 1] = blk3_2.fou[ih - 1];
	blk3_2.fou[ih - 1] = iarc;
	blk6_2.nxtin[iarc - 1] = blk5_2.fin[it - 1];
	blk5_2.fin[it - 1] = iarc;
	if (arrayrc_1.rc[iarc - 1] == 0) {
	    blk11_1.tnxtou[iarc - 1] = blk10_1.tfstou[ih - 1];
	    blk10_1.tfstou[ih - 1] = iarc;
	    blk13_1.tnxtin[iarc - 1] = blk12_1.tfstin[it - 1];
	    blk12_1.tfstin[it - 1] = iarc;
	}
    }
    goto L20;
} /* senstv_ */
#endif



/* Subroutine */ int addtr_(integer *arc)
{
    static integer arc1, node;


/* --------------------------------------------------------------- */

/*  PURPOSE - THIS SUBROUTINE CHECKS IF ARC IS IN THE ARRAYS TFSTOU, TNXTOU, */
/*     TFSTIN, TNXTIN AND, IF NOT, ADDS ARC TO THEM. */

/* --------------------------------------------------------------- */

/*     MAXNN = DIMENSION OF NODE-LENGTH ARRAYS */
/*     MAXNA = DIMENSION OF ARC-LENGTH ARRAYS */



    node = arrays_1.startn[*arc - 1];
    arc1 = blk10_1.tfstou[node - 1];
L10:
    if (arc1 > 0) {
	if (arc1 == *arc) {
	    goto L20;
	}
	arc1 = blk11_1.tnxtou[arc1 - 1];
	goto L10;
    }
    blk11_1.tnxtou[*arc - 1] = blk10_1.tfstou[node - 1];
    blk10_1.tfstou[node - 1] = *arc;
L20:
    node = arraye_1.endn[*arc - 1];
    arc1 = blk12_1.tfstin[node - 1];
L30:
    if (arc1 > 0) {
	if (arc1 == *arc) {
	    return 0;
	}
	arc1 = blk13_1.tnxtin[arc1 - 1];
	goto L30;
    }
    blk13_1.tnxtin[*arc - 1] = blk12_1.tfstin[node - 1];
    blk12_1.tfstin[node - 1] = *arc;
    return 0;
} /* addtr_ */


#if 0
/* Main program alias */ int main_ () { MAIN__ (); return 0; }
#endif

int run_relax4(integer num_nodes, integer num_arcs,
    integer start_node[],
    integer end_node[],
    integer cost[],
    integer capacity[],
    integer demand[],
    integer flows[], integer use_auction_init)
{
  integer i;

  /* Set pointers into output data. */
  input_1.n = num_nodes;
  input_1.na = num_arcs;
  arrays_1.startn = start_node;
  arraye_1.endn = end_node;
  arrayc_1.c__ = cost;
  arrayu_1.u = capacity;
  arrayb_1.b = demand;
  arrayx_1.x = flows;

  /*
  printf("demand[0] = %ld\n", demand[0]);
  printf("demand[1] = %ld\n", demand[1]);
  printf("b[0] = %ld\n", arrayb_1.b[0]);
  printf("b[1] = %ld\n", arrayb_1.b[1]);
  printf("dfct[0] = %ld\n", arrayb_2.dfct[0]);
  printf("dfct[1] = %ld\n", arrayb_2.dfct[1]);
  */

  /* need to be malloc'd:
   *
   *arrayrc_1.rc
   * */

  /* Note 3: INT_MAX / 4 is recommended, which looks about right*/
  input_1.large = 500000000;

  /* CHECK DATA IS WITHIN RANGE OF MACHINE */
  /*danger_thresh__ = input_1.large / 10;*/
  /* I have cut this bit for now... */

  /* CONSTRUCT LINKED LISTS FOR THE PROBLEM */
  inidat_();

  /* INITIALIZE DUAL PRICES */
  /* (DEFAULT: ALL DUAL PRICES = 0, SO REDUCED COST IS SET EQUAL TO COST) */
  for (i = 1; i <= num_arcs; ++i) {
    /* L60: */
    arrayrc_1.rc[i - 1] = arrayc_1.c__[i - 1];
  }

  /*     SPECIFY THAT WE ARE SOLVING THE PROBLEM FROM SCRATCH */
  blkr_1.repeat = FALSE_;

  /* --------------------------------------------------------------- */

  /* SET CRASH EQUAL TO 1 TO ACTIVATE AN AUCTION/SHORTEST PATH SUBROUTINE FOR */
  /* GETTING THE INITIAL PRICE-FLOW PAIR. THIS IS RECOMMENDED FOR DIFFICULT */
  /* PROBLEMS WHERE THE DEFAULT INITIALIZATION YIELDS LONG SOLUTION TIMES. */
  cr_1.crash = use_auction_init ? 1 : 0;

  /* CALL RELAX4 TO SOLVE THE PROBLEM */
  relax4_();

  /* CHECK CORRECTNESS OF OUTPUT PARAMETERS */
  /* TODO do this somewhere (separate method) */

  /*     DISPLAY RELAX4 STATISTICS */
  if (cr_1.crash == 1) {
    printf("NUMBER OF AUCTION/SHORTEST PATH ITERATIONS = %ld\n", output_1.nsp);
  }
  printf("NUMBER OF ITERATIONS = %ld\n", output_1.iter);
  printf("NUMBER OF MULTINODE ITERATIONS = %ld\n", output_1.nmultinode);
  printf("NUMBER OF MULTINODE ASCENT STEPS = %ld\n", output_1.num_ascnt__);
  printf("NUMBER OF REGULAR AUGMENTATIONS = %ld\n", output_1.num_augm__);

  return 0;
}

