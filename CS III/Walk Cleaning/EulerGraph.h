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
	EulerGraph(std::string filename);

	std::string m_filename;	//just easy access for the original filename;

	void generateAdjacencyMatrix();
	void computeTour(std::ostream & passFout);

private:
	AdjacencyMatrix adjacencyMatrix; //no one else needs to access this, so we're keeping it private just for kicks and giggles
};

