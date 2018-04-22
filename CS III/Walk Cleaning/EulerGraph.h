#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "AdjacencyMatrix.h"

using namespace std;

class EulerGraph
{
public:
	EulerGraph(std::string filename, std::ostream & passFout);

	bool verifyEuler();	//returns a true if it should continue, false if it should stop and move onto the next one
	void generateAdjacencyMatrix();	//generates its adjacency matrix
	void computeTour(std::ostream & passFout);	//does what the program needs

private:
	AdjacencyMatrix adjacencyMatrix; //no one else needs to access this, so we're keeping it private just for kicks and giggles
};

