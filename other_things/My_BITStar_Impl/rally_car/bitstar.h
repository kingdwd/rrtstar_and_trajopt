#ifndef BITSTAR_H_
#define BITSTAR_H_

#include <eigen3/Eigen/Eigen>
using namespace Eigen;
#include <set>

#define INFTY 1e10

#include "../../optcontrol/rally_car/rally_car_sqp.hpp"

class Node {
public:
	VectorXd state;
	double cost;
//	double h_hat;
//	double g_hat;
//	double f_hat;
	bool inV;
	bool old;
	Node* parent; // Parent node

	// This represents the edge from the parent state to this state. Only one. Yes, I know it's hacky.
	// But I didn't want to store a bunch of paths from the parent to it's children
	StdVectorX states;
	StdVectorU controls;

	std::set<Node* > children; // A vector of pointers to children nodes
};

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

class SetupObject {
public:
	int max_time;
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
	double y_min;
	double y_max;
	double xdot_min;
	double xdot_max;
	double ydot_min;
	double ydot_max;
	double theta_min;
	double theta_max;
	double thetadot_min;
	double thetadot_max;
	double wf_min;
	double wf_max;
	double wr_min;
	double wr_max;

	double sta_min;
	double sta_max;
	double tf_min;
	double tf_max;
	double tf_min;
	double tf_max;

	int batch_size;
};

#endif /* BITSTAR_H_ */