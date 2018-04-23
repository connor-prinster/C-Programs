#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "edge1.h"
//#include "Node.h"

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	AdjacencyMatrix(std::string filename);

	int numConnections;	//total number of edges in the graph
	int numNodes;	//number of uniquely named nodes (a, b, ...)
	std::string m_filename;

	void addEdge(int origin, int destination); //fills in the spot in the array (x, y) with (origin, destination)
	void printMatrix();	//simple print method
	void fillFromFile();

	std::vector< std::vector<int> > matrix;	//the actual adjacency vector
	//std::vector< Node * > vectorOfNodes;	//vector of nodes
	//std::vector< Edge * > vectorOfEdges; //vector of edges
};

