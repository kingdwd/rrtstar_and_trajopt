% cartpole_QP_solver - a fast interior point code generated by FORCES
%
%   OUTPUT = cartpole_QP_solver(PARAMS) solves a multistage problem
%   subject to the parameters supplied in the following struct:
%       PARAMS.f1 - column vector of length 14
%       PARAMS.lb1 - column vector of length 14
%       PARAMS.ub1 - column vector of length 6
%       PARAMS.C1 - matrix of size [9 x 14]
%       PARAMS.e1 - column vector of length 9
%       PARAMS.f2 - column vector of length 14
%       PARAMS.lb2 - column vector of length 14
%       PARAMS.ub2 - column vector of length 6
%       PARAMS.C2 - matrix of size [5 x 14]
%       PARAMS.e2 - column vector of length 5
%       PARAMS.f3 - column vector of length 14
%       PARAMS.lb3 - column vector of length 14
%       PARAMS.ub3 - column vector of length 6
%       PARAMS.C3 - matrix of size [5 x 14]
%       PARAMS.e3 - column vector of length 5
%       PARAMS.f4 - column vector of length 14
%       PARAMS.lb4 - column vector of length 14
%       PARAMS.ub4 - column vector of length 6
%       PARAMS.C4 - matrix of size [5 x 14]
%       PARAMS.e4 - column vector of length 5
%       PARAMS.f5 - column vector of length 14
%       PARAMS.lb5 - column vector of length 14
%       PARAMS.ub5 - column vector of length 6
%       PARAMS.C5 - matrix of size [5 x 14]
%       PARAMS.e5 - column vector of length 5
%       PARAMS.f6 - column vector of length 14
%       PARAMS.lb6 - column vector of length 14
%       PARAMS.ub6 - column vector of length 6
%       PARAMS.C6 - matrix of size [5 x 14]
%       PARAMS.e6 - column vector of length 5
%       PARAMS.f7 - column vector of length 14
%       PARAMS.lb7 - column vector of length 14
%       PARAMS.ub7 - column vector of length 6
%       PARAMS.C7 - matrix of size [5 x 14]
%       PARAMS.e7 - column vector of length 5
%       PARAMS.f8 - column vector of length 14
%       PARAMS.lb8 - column vector of length 14
%       PARAMS.ub8 - column vector of length 6
%       PARAMS.C8 - matrix of size [5 x 14]
%       PARAMS.e8 - column vector of length 5
%       PARAMS.f9 - column vector of length 14
%       PARAMS.lb9 - column vector of length 14
%       PARAMS.ub9 - column vector of length 6
%       PARAMS.C9 - matrix of size [5 x 14]
%       PARAMS.e9 - column vector of length 5
%       PARAMS.f10 - column vector of length 14
%       PARAMS.lb10 - column vector of length 14
%       PARAMS.ub10 - column vector of length 6
%       PARAMS.C10 - matrix of size [5 x 14]
%       PARAMS.e10 - column vector of length 5
%       PARAMS.f11 - column vector of length 14
%       PARAMS.lb11 - column vector of length 14
%       PARAMS.ub11 - column vector of length 6
%       PARAMS.C11 - matrix of size [5 x 14]
%       PARAMS.e11 - column vector of length 5
%       PARAMS.lb12 - column vector of length 5
%       PARAMS.ub12 - column vector of length 5
%
%   OUTPUT returns the values of the last iteration of the solver where
%       OUTPUT.z1 - column vector of size 6
%       OUTPUT.z2 - column vector of size 6
%       OUTPUT.z3 - column vector of size 6
%       OUTPUT.z4 - column vector of size 6
%       OUTPUT.z5 - column vector of size 6
%       OUTPUT.z6 - column vector of size 6
%       OUTPUT.z7 - column vector of size 6
%       OUTPUT.z8 - column vector of size 6
%       OUTPUT.z9 - column vector of size 6
%       OUTPUT.z10 - column vector of size 6
%       OUTPUT.z11 - column vector of size 6
%       OUTPUT.z12 - column vector of size 5
%
%   [OUTPUT, EXITFLAG] = cartpole_QP_solver(PARAMS) returns additionally
%   the integer EXITFLAG indicating the state of the solution with 
%       1 - Optimal solution has been found (subject to desired accuracy)
%       0 - Maximum number of interior point iterations reached
%      -7 - Line search could not progress
%
%   [OUTPUT, EXITFLAG, INFO] = cartpole_QP_solver(PARAMS) returns 
%   additional information about the last iterate:
%       INFO.it        - number of iterations that lead to this result
%       INFO.res_eq    - max. equality constraint residual
%       INFO.res_ineq  - max. inequality constraint residual
%       INFO.pobj      - primal objective
%       INFO.dobj      - dual objective
%       INFO.dgap      - duality gap := pobj - dobj
%       INFO.rdgap     - relative duality gap := |dgap / pobj|
%       INFO.mu        - duality measure
%       INFO.sigma     - centering parameter
%       INFO.lsit_aff  - iterations of affine line search
%       INFO.lsit_cc   - iterations of line search (combined direction)
%       INFO.step_aff  - step size (affine direction)
%       INFO.step_cc   - step size (centering direction)
%       INFO.solvetime - Time needed for solve (wall clock time)
%
% See also LICENSE
