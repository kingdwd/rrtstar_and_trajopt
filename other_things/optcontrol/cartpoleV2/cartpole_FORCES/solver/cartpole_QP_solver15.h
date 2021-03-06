/*
FORCES - Fast interior point code generation for multistage problems.
Copyright (C) 2011-14 Alexander Domahidi [domahidi@control.ee.ethz.ch],
Automatic Control Laboratory, ETH Zurich.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __cartpole_QP_solver_H__
#define __cartpole_QP_solver_H__


/* DATA TYPE ------------------------------------------------------------*/
typedef double cartpole_QP_solver_FLOAT;


/* SOLVER SETTINGS ------------------------------------------------------*/
/* print level */
#ifndef cartpole_QP_solver_SET_PRINTLEVEL
#define cartpole_QP_solver_SET_PRINTLEVEL    (0)
#endif

/* timing */
#ifndef cartpole_QP_solver_SET_TIMING
#define cartpole_QP_solver_SET_TIMING    (1)
#endif

/* Numeric Warnings */
/* #define PRINTNUMERICALWARNINGS */

/* maximum number of iterations  */
#define cartpole_QP_solver_SET_MAXIT         (50)	

/* scaling factor of line search (affine direction) */
#define cartpole_QP_solver_SET_LS_SCALE_AFF  (0.9)      

/* scaling factor of line search (combined direction) */
#define cartpole_QP_solver_SET_LS_SCALE      (0.95)  

/* minimum required step size in each iteration */
#define cartpole_QP_solver_SET_LS_MINSTEP    (1E-08)

/* maximum step size (combined direction) */
#define cartpole_QP_solver_SET_LS_MAXSTEP    (0.995)

/* desired relative duality gap */
#define cartpole_QP_solver_SET_ACC_RDGAP     (0.0001)

/* desired maximum residual on equality constraints */
#define cartpole_QP_solver_SET_ACC_RESEQ     (1E-06)

/* desired maximum residual on inequality constraints */
#define cartpole_QP_solver_SET_ACC_RESINEQ   (1E-06)

/* desired maximum violation of complementarity */
#define cartpole_QP_solver_SET_ACC_KKTCOMPL  (1E-06)


/* RETURN CODES----------------------------------------------------------*/
/* solver has converged within desired accuracy */
#define cartpole_QP_solver_OPTIMAL      (1)

/* maximum number of iterations has been reached */
#define cartpole_QP_solver_MAXITREACHED (0)

/* no progress in line search possible */
#define cartpole_QP_solver_NOPROGRESS   (-7)




/* PARAMETERS -----------------------------------------------------------*/
/* fill this with data before calling the solver! */
typedef struct cartpole_QP_solver_params
{
    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f1[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb1[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub1[6];

    /* matrix of size [9 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C1[126];

    /* vector of size 9 */
    cartpole_QP_solver_FLOAT e1[9];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f2[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb2[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub2[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C2[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e2[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f3[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb3[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub3[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C3[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e3[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f4[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb4[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub4[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C4[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e4[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f5[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb5[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub5[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C5[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e5[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f6[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb6[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub6[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C6[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e6[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f7[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb7[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub7[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C7[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e7[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f8[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb8[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub8[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C8[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e8[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f9[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb9[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub9[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C9[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e9[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f10[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb10[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub10[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C10[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e10[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f11[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb11[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub11[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C11[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e11[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f12[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb12[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub12[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C12[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e12[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f13[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb13[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub13[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C13[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e13[5];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT f14[14];

    /* vector of size 14 */
    cartpole_QP_solver_FLOAT lb14[14];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT ub14[6];

    /* matrix of size [5 x 14] (column major format) */
    cartpole_QP_solver_FLOAT C14[70];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT e14[5];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT lb15[5];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT ub15[5];

} cartpole_QP_solver_params;


/* OUTPUTS --------------------------------------------------------------*/
/* the desired variables are put here by the solver */
typedef struct cartpole_QP_solver_output
{
    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z1[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z2[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z3[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z4[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z5[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z6[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z7[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z8[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z9[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z10[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z11[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z12[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z13[6];

    /* vector of size 6 */
    cartpole_QP_solver_FLOAT z14[6];

    /* vector of size 5 */
    cartpole_QP_solver_FLOAT z15[5];

} cartpole_QP_solver_output;


/* SOLVER INFO ----------------------------------------------------------*/
/* diagnostic data from last interior point step */
typedef struct cartpole_QP_solver_info
{
    /* iteration number */
    int it;
	
    /* inf-norm of equality constraint residuals */
    cartpole_QP_solver_FLOAT res_eq;
	
    /* inf-norm of inequality constraint residuals */
    cartpole_QP_solver_FLOAT res_ineq;

    /* primal objective */
    cartpole_QP_solver_FLOAT pobj;	
	
    /* dual objective */
    cartpole_QP_solver_FLOAT dobj;	

    /* duality gap := pobj - dobj */
    cartpole_QP_solver_FLOAT dgap;		
	
    /* relative duality gap := |dgap / pobj | */
    cartpole_QP_solver_FLOAT rdgap;		

    /* duality measure */
    cartpole_QP_solver_FLOAT mu;

	/* duality measure (after affine step) */
    cartpole_QP_solver_FLOAT mu_aff;
	
    /* centering parameter */
    cartpole_QP_solver_FLOAT sigma;
	
    /* number of backtracking line search steps (affine direction) */
    int lsit_aff;
    
    /* number of backtracking line search steps (combined direction) */
    int lsit_cc;
    
    /* step size (affine direction) */
    cartpole_QP_solver_FLOAT step_aff;
    
    /* step size (combined direction) */
    cartpole_QP_solver_FLOAT step_cc;    

	/* solvertime */
	cartpole_QP_solver_FLOAT solvetime;   

} cartpole_QP_solver_info;


/* SOLVER FUNCTION DEFINITION -------------------------------------------*/
/* examine exitflag before using the result! */
int cartpole_QP_solver_solve(cartpole_QP_solver_params* params, cartpole_QP_solver_output* output, cartpole_QP_solver_info* info);


#endif