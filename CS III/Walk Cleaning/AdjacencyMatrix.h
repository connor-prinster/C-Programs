#pragma once

#include <iostream>
#include <vector>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	AdjacencyMatrix(int n);	//standard constructor that is size "n"
	~AdjacencyMatrix();	//destructor that might not be necessary as there are no pointers? 
	void addEdge(int origin, int destination);	//creates an edge based on the origin and destination, pretty standard
	void printMatrix();	//simple print method
	std::vector< std::vector<int> > adjacencyMatrix;	//vector of vectors so it can be resized as runtime. Arrays are also a pain in the butt

private:
	int nVar;
};

