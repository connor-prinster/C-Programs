#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "AdjacencyMatrix.h"
//#include "edge1.h"

class EulerGraph
{
public:
	EulerGraph(std::string filename);	//custom constructor

private:
	AdjacencyMatrix m_adjacencyMatrix; //this m_adjacencyMatrix is first built completely generic but will then be filled with custom data in generateAdjacencyMatrix()
	void computeTour();	//the meat of the assignment
	void computeCycleFromSpecificNode(int startingNode);
	bool edgesAreAllUsed();
	void generateAdjacencyMatrix();	//the 'm_adjacencyMatrix' object is customized from the specific file passed
	void printTour();
	Edge * checkOutEdgeAtIndex(unsigned int index);
	//int getOtherEndpointFromMatrix(int oneNode);
	std::string m_filename;	//just easy access for the original filename;
	std::vector<int> m_tourPath;	//final tour path
	std::vector< std::vector<char> > m_vectorOfCycles;	//each subvector is a subcycle
};