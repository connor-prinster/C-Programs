#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename)
{
	//std::cout << "Generating the graph for " << filename << std::endl;
	m_filename = filename;	//the filename is now hardcoded in the EulerGraph object
	generateAdjacencyMatrix();	//generates it's custom m_matrix
	if (m_adjacencyMatrix.m_isEuler)	//if it's Euler, computeTour()
	{
		computeTour();
	}
	else	//otherwise, don't compute the tour and cout instead
	{
		std::cout << "No Euler Tour Available\n";
	}
}

void EulerGraph::generateAdjacencyMatrix()
{
	m_adjacencyMatrix = AdjacencyMatrix(m_filename);	//uses the custom constructor to individualize the m_adjacencyMatrix object
	//m_adjacencyMatrix.printMatrix();
}

void EulerGraph::computeTour()
{
	std::cout << "Going through the tour\n";
}