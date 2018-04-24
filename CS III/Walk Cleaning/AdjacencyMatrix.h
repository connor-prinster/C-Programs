#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "edge1.h"

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();	//standar constructor
	AdjacencyMatrix(std::string filename);	//custom constructor

	int numConnections;	//total number of edges in the graph
	int numNodes;	//number of uniquely named nodes (a, b, ...)
	std::string m_filename;

	void addEdge(int origin, int destination); //fills in the spot in the array (x, y) with (origin, destination)
	void printMatrix();	//simple print method
	void fillFromFile();	//from the file listed in the custom constructor this will fill the AdjacencyMatrix object with its data

	std::vector< std::vector<int> > matrix;	//the actual adjacency vector
	std::vector< Edge * > vectorOfEdges; //vector of edges
};

