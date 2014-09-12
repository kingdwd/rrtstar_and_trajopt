#ifndef BITSTAR_H_
#define BITSTAR_H_

#include <eigen3/Eigen/Eigen>
using namespace Eigen;
#include <set>

#define INFTY 1e10

#include "../../double_integrator_FORCES/SQP/without_CD/double_integrator_noCD_sqp.hpp"

class Node {
public:
	VectorXd state;
	double cost;
	double h_hat;
	double g_hat;
	double f_hat;
	bool inV;
	Node* parent; // Parent node

	// This represents the edge from the parent state to this state. Only one. Yes, I know it's hacky.
	// But I didn't want to store a bunch of paths from the parent to it's children
	StdVectorX states;
	StdVectorU controls;

	std::set<Node* > children; // A vector of pointers to children nodes
};

// Cost of node from root of tree
inline double g_T(Node* x) {
	//if (!inSet(x, V)) {
	//	return INFTY;
	//}
	if (x->inV)
		return x->cost;
	else
		return INFTY;
}

class Edge {
public:

	double heuristic_cost;
	Node* v;
	Node* x;
	// Edge is represented by (v, x)
	// Invariant: v is in the vertex set V, x in in the set X_sample

	// This represents the edge from the parent state to this state. Only one. Yes, I know it's hacky.
	// But I didn't want to store a bunch of paths from the parent to it's children
	// Even more hacky: this is a temp holder lol
	StdVectorX states;
	StdVectorU controls;

	Edge(Node* v_, Node* x_) { v = v_; x = x_; heuristic_cost = 0; }
};

struct cmpEdge {
    bool operator()(Edge* a, Edge* b) {
    	//return a < b;

    	double cost_a = g_T(a->v) + a->heuristic_cost + (a->x->h_hat);
    	double cost_b = g_T(b->v) + b->heuristic_cost + (b->x->h_hat);
    	//std::cout << "cost_a: " << cost_a << " cost_b: " << cost_b << std::endl;
    	if (cost_a == cost_b) {
    		return false;
    	} else
    		return (cost_a < cost_b);
    }
};

class SetupObject {
public:
	int max_iters;
	int dimension;
	VectorXd initial_state;
	VectorXd goal_state;
	double gamma; // Set to be at least side length of state space
	bool randomize;
	// API: Each column is a rectangular obstacle represented by a 4d vector.
	// The vector is comprised of: [x_center; x_size; y_center; y_size]
	MatrixXd obstacles;

	double x_min;
	double x_max;
	double v_min;
	double v_max;
	double u_min;
	double u_max;
};

#endif /* BITSTAR_H_ */