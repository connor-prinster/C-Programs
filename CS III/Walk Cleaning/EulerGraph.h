#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "AdjacencyMatrix.h"

class EulerGraph
{
public:
	EulerGraph(std::string filename);	//custom constructor

private:
	AdjacencyMatrix m_adjacencyMatrix; //this m_adjacencyMatrix is first built completely generic but will then be filled with custom data in generateAdjacencyMatrix()

	void printAllGraphData();
	void computeTour();	//the meat of the assignment
	void computeCycleFromSpecificNode(int startingNode);
	void generateAdjacencyMatrix();	//the 'm_adjacencyMatrix' object is customized from the specific file passed
	void printTour();	//print out the m_tourPath vector
	bool isThisEdgeUsed(int index);	//check if the edge is used
	bool edgesAreAllUsed();	//check if ALL the edges are used
	bool containsEdgeValuesWanted(int desiredValue, int index);	//see if the edge has the values you want
	void printAllEdges();	//print out all the edges and their values

	Edge * checkOutEdgeAtIndex(int index);	//pull out the edge stored at index
	std::string m_filename;	//just easy access for the original filename;
	std::vector<int> m_tourPath;	//final tour path
	std::vector< std::vector<char> > m_vectorOfCycles;	//each subvector is a subcycle
};