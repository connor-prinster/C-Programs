#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "AdjacencyMatrix.h"
#include "edge1.h"

using namespace std;

class EulerGraph
{
public:
	EulerGraph(std::string filename, std::ostream & passFout);

	std::string originFilename;	//just easy access for the original filename;
	std::vector<Node *> vectorOfNodes;	//lists all the Nodes in the graph 
	std::vector<Edge *> vectorOfEdges;	//lists all the Edges in the graph
	void generateAdjacencyMatrix(std::string filename);
	
	void computeTour(std::ostream & passFout);

private:
	AdjacencyMatrix adjacencyMatrix; //no one else needs to access this, so we're keeping it private just for kicks and giggles
};

