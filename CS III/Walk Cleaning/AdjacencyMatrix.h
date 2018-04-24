#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "edge1.h"

class AdjacencyMatrix
{
public:
	AdjacencyMatrix() {}	//standard constructor
	AdjacencyMatrix(std::string filename);	//custom constructor

	void addEdge(int origin, int destination); //fills in the spot in the array (x, y) with (origin, destination)
	void printMatrix();	//simple print method
	void fillFromFile();	//from the file listed in the custom constructor this will fill the AdjacencyMatrix object with its data
	bool isEuler();

	int m_numConnections;	//total number of edges in the graph
	int m_numNodes;	//number of uniquely named nodes (a, b, ...)
	bool m_isEuler;	//checks that the graph is Euler, as far as I know all the graphs in here are, but just for any other graphs inputted
	std::string m_filename;	//to *technically* hardcode the filename
	std::vector< std::vector<int> > m_matrix;	//the actual adjacency vector
	std::vector< Edge * > m_vectorOfEdges; //vector of edges
};

