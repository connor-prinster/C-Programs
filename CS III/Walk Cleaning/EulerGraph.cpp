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
}

void EulerGraph::computeTour()
{
	std::cout << "Going through the tour\n";
	m_adjacencyMatrix.printMatrix();
}

void EulerGraph::computeCycles()
{
	while (!edgesAreAllUsed())	//while all the edges aren't used, keep going through this method
	{

	}
}

bool EulerGraph::edgesAreAllUsed()
{
	for (unsigned int i = 0; i < m_adjacencyMatrix.m_vectorOfEdges.size(); i++)	//run through all edges in the adjacencyMatrix
	{
		if (!m_adjacencyMatrix.m_vectorOfEdges[i]->m_used)	//if even one edge is not used, return false
		{
			return false;
		}
	}
	return true;	//if we make it here then all the edges are used and return true
}