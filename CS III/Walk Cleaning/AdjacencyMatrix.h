#pragma once

#include <iostream>
#include <vector>

#include "edge1.h"
#include "Node.h"

class AdjacencyMatrix
{
public:
	AdjacencyMatrix(int n);

	int numConnections;	//total number of edges in the graph
	int numNodes;	//number of uniquely named nodes (a, b, ...)

	void addEdge(int origin, int destination); //fills in the spot in the array (x, y) with (origin, destination)
	void printMatrix();	//simple print methodint numNodes;

	std::vector< std::vector<int> > matrix;

private:
	std::vector<Edge *> adjEdgeVector;
};

