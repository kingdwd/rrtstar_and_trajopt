% double_integrator_QP_solver_CD - a fast interior point code generated by FORCES
%
%   OUTPUT = double_integrator_QP_solver_CD(PARAMS) solves a multistage problem
%   subject to the parameters supplied in the following struct:
%       PARAMS.f1 - column vector of length 20
%       PARAMS.lb1 - column vector of length 7
%       PARAMS.ub1 - column vector of length 6
%       PARAMS.A1 - matrix of size [14 x 20]
%       PARAMS.b1 - column vector of length 14
%       PARAMS.f2 - column vector of length 20
%       PARAMS.lb2 - column vector of length 4
%       PARAMS.ub2 - column vector of length 4
%       PARAMS.A2 - matrix of size [28 x 20]
%       PARAMS.b2 - column vector of length 28
%       PARAMS.f3 - column vector of length 20
%       PARAMS.lb3 - column vector of length 4
%       PARAMS.ub3 - column vector of length 4
%       PARAMS.A3 - matrix of size [28 x 20]
%       PARAMS.b3 - column vector of length 28
%       PARAMS.f4 - column vector of length 20
%       PARAMS.lb4 - column vector of length 4
%       PARAMS.ub4 - column vector of length 4
%       PARAMS.A4 - matrix of size [28 x 20]
%       PARAMS.b4 - column vector of length 28
%       PARAMS.f5 - column vector of length 20
%       PARAMS.lb5 - column vector of length 4
%       PARAMS.ub5 - column vector of length 4
%       PARAMS.A5 - matrix of size [28 x 20]
%       PARAMS.b5 - column vector of length 28
%       PARAMS.f6 - column vector of length 20
%       PARAMS.lb6 - column vector of length 4
%       PARAMS.ub6 - column vector of length 4
%       PARAMS.A6 - matrix of size [28 x 20]
%       PARAMS.b6 - column vector of length 28
%       PARAMS.f7 - column vector of length 20
%       PARAMS.lb7 - column vector of length 4
%       PARAMS.ub7 - column vector of length 4
%       PARAMS.A7 - matrix of size [28 x 20]
%       PARAMS.b7 - column vector of length 28
%       PARAMS.f8 - column vector of length 20
%       PARAMS.lb8 - column vector of length 4
%       PARAMS.ub8 - column vector of length 4
%       PARAMS.A8 - matrix of size [28 x 20]
%       PARAMS.b8 - column vector of length 28
%       PARAMS.f9 - column vector of length 20
%       PARAMS.lb9 - column vector of length 4
%       PARAMS.ub9 - column vector of length 4
%       PARAMS.A9 - matrix of size [28 x 20]
%       PARAMS.b9 - column vector of length 28
%       PARAMS.f10 - column vector of length 20
%       PARAMS.lb10 - column vector of length 4
%       PARAMS.ub10 - column vector of length 4
%       PARAMS.A10 - matrix of size [28 x 20]
%       PARAMS.b10 - column vector of length 28
%       PARAMS.f11 - column vector of length 18
%       PARAMS.lb11 - column vector of length 4
%       PARAMS.ub11 - column vector of length 4
%       PARAMS.A11 - matrix of size [28 x 18]
%       PARAMS.b11 - column vector of length 28
%       PARAMS.f12 - column vector of length 4
%       PARAMS.lb12 - column vector of length 4
%       PARAMS.ub12 - column vector of length 4
%
%   OUTPUT returns the values of the last iteration of the solver where
%       OUTPUT.z1 - column vector of size 7
%       OUTPUT.z2 - column vector of size 7
%       OUTPUT.z3 - column vector of size 7
%       OUTPUT.z4 - column vector of size 7
%       OUTPUT.z5 - column vector of size 7
%       OUTPUT.z6 - column vector of size 7
%       OUTPUT.z7 - column vector of size 7
%       OUTPUT.z8 - column vector of size 7
%       OUTPUT.z9 - column vector of size 7
%       OUTPUT.z10 - column vector of size 7
%       OUTPUT.z11 - column vector of size 7
%       OUTPUT.z12 - column vector of size 4
%
%   [OUTPUT, EXITFLAG] = double_integrator_QP_solver_CD(PARAMS) returns additionally
%   the integer EXITFLAG indicating the state of the solution with 
%       1 - Optimal solution has been found (subject to desired accuracy)
%       0 - Maximum number of interior point iterations reached
%      -7 - Line search could not progress
%
%   [OUTPUT, EXITFLAG, INFO] = double_integrator_QP_solver_CD(PARAMS) returns 
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
