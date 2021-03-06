#ifndef BITSTAR_H_
#define BITSTAR_H_

#include <eigen3/Eigen/Eigen>
using namespace Eigen;
#include <set>

#define INFTY 1e10

class Node {
public:
	VectorXd state;
	double cost; // Cost of edge connecting to parent
//	double h_hat;
//	double g_hat;
//	double f_hat;
	bool inV;
	bool old;
	Node* parent; // Parent node
	std::set<Node* > children; // A vector of pointers to children nodes
};

class Edge {
public:

	double heuristic_cost;
	Node* v;
	Node* x;
	// Edge is represented by (v, x)
	// Invariant: v is in the vertex set V, x in in the set X_sample

	Edge(Node* v_, Node* x_) { v = v_; x = x_; heuristic_cost = 0; }
};

class SetupObject {
public:
	int max_iters;
	int dimension;
	VectorXd initial_state;
	VectorXd goal_region;
	double gamma; // Set to be at least side length of state space
	bool randomize;
	// API: Each column is a rectangular obstacle represented by a 4d vector.
	// The vector is comprised of: [x_center; x_size; y_center; y_size]
	MatrixXd obstacles;

	double x_min;
	double x_max;

	int batch_size;
};

#endif /* BITSTAR_H_ */
