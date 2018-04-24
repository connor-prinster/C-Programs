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

	std::string m_filename;	//just easy access for the original filename;

	void generateAdjacencyMatrix();	//the 'm_adjacencyMatrix' object is customized from the specific file passed
	void computeTour();

private:
	AdjacencyMatrix m_adjacencyMatrix; //this m_adjacencyMatrix is first built completely generic but will then be filled with custom data in generateAdjacencyMatrix()
	std::vector<int> m_tourPath;
};

