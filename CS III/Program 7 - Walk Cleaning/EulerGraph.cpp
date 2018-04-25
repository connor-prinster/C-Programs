#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename)
{
	m_filename = filename;	//the filename is now hardcoded in the EulerGraph object
	generateAdjacencyMatrix();	//generates it's custom m_matrix
	if (m_adjacencyMatrix.m_isEuler)	//if it's Euler, computeTour()
	{
		printAllGraphData();
	}
	else	//otherwise, don't compute the tour and cout instead
	{
		std::cout << "No Euler Tour Available\n";
	}
}

void EulerGraph::printAllGraphData()
{
	std::cout << "  Generating Data for " << m_filename << std::endl;
	std::cout << "||==============================||\n";
	std::cout << "|| This is a proper Euler graph ||\n";
	std::cout << "||==============================||\n";
	computeTour();
	printAllEdges();
	printTour();
}

void EulerGraph::printAllEdges()
{
	std::cout << "|---------------------------------------|\n";
	std::cout << "| List of Edges Contained in This Graph |\n";
	std::cout << "|---------------------------------------|\n";
	std::cout << "There are " << m_adjacencyMatrix.m_numNodes << " nodes and " << m_adjacencyMatrix.m_numConnections << " connections\n";
	for (unsigned int i = 0; i < m_adjacencyMatrix.m_vectorOfEdges.size(); i++)
	{
		std::cout << m_adjacencyMatrix.m_vectorOfEdges[i]->toString() << std::endl;
	}
	std::cout << std::endl;
}

void EulerGraph::generateAdjacencyMatrix()
{
	m_adjacencyMatrix = AdjacencyMatrix(m_filename);	//uses the custom constructor to individualize the m_adjacencyMatrix object
}

void EulerGraph::computeTour()
{
	m_adjacencyMatrix.printMatrix();
}

void EulerGraph::computeCycleFromSpecificNode(int startingNode)
{
	Edge * originalEdge = checkOutEdgeAtIndex(0);
	Edge * beginningEdge = NULL;
	Edge * endingEdge = NULL;

	int beginningEdgeIdx = beginningEdge->m_fromNode;
	int endingEdgeIdx = beginningEdge->m_fromNode;
}

Edge * EulerGraph::checkOutEdgeAtIndex(int index)
{
	return m_adjacencyMatrix.m_vectorOfEdges[index];	//return edge at given index
}

bool EulerGraph::edgesAreAllUsed()
{
	for (unsigned int i = 0; i < m_adjacencyMatrix.m_vectorOfEdges.size(); i++)	//run through all edges in the adjacencyMatrix
	{
		if (!m_adjacencyMatrix.m_vectorOfEdges[i]->m_containedInCycle)	//if even one edge is not used, return false
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
	std::cout << "==================================================================\n------------------------------------------------------------------\n==================================================================\n";
	std::cout << std::endl;	//after the line of char's is printed out go to the second line
}