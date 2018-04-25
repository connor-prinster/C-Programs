#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename)
{
	//std::cout << "Generating the graph for " << filename << std::endl;
	m_filename = filename;	//the filename is now hardcoded in the EulerGraph object
	generateAdjacencyMatrix();	//generates it's custom m_matrix
	if (m_adjacencyMatrix.m_isEuler)	//if it's Euler, computeTour()
	{
		computeTour();
		printTour();
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
	//std::cout << "Going through the tour\n";
	m_adjacencyMatrix.printMatrix();
}

void EulerGraph::computeCycleFromSpecificNode(int startingNode)
{
	int cycleCount = 0;	//what to name the m_cycleID of the edge
	int vectorIndexWhileCounter = 2;	//will increase throughout the while() loop

	Edge * originalEdge = checkOutEdgeAtIndex(0);//the first cycle has got to be started at the first node, it's just easier
	Edge * firstEdge = checkOutEdgeAtIndex(0); //so the firstEdge can be incremented w/out originalEdge being changed
	Edge * nextEdge = checkOutEdgeAtIndex(1);	//initialized to the second edge for comparison
}

Edge * EulerGraph::checkOutEdgeAtIndex(unsigned int index)
{
	if (index == m_adjacencyMatrix.m_vectorOfEdges.size())	//don't want to overstep the vector, so we'll check it now
	{
		return NULL;	//return null otherwise so we can check it in computeCycleSpeicificNode()
	}
	return m_adjacencyMatrix.m_vectorOfEdges[index];	//should be able to return a valid pointer
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

void EulerGraph::printTour()
{
	std::cout << "The Euler tour for " << m_filename << " is: ";
	for (unsigned int i = 0; i < m_tourPath.size(); i++)
	{
		char tempChar = m_tourPath[i] + 'A';	//since the value in the array is stored as an int, convert it to a char for print
		std::cout << tempChar << " -> ";	//print the char followed by a arrow to the console
	}
	std::cout << std::endl;
	std::cout << "=================================\n---------------------------------\n=================================\n";
	std::cout << std::endl;	//after the line of char's is printed out go to the second line
}