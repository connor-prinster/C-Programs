#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename)
{
	//std::cout << "Generating the graph for " << filename << std::endl;
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
	computeTour();
	printAllEdges();
	printTour();
}

void EulerGraph::printAllEdges()
{
	std::cout << "List of Edges Contained in This Graph\n";
	std::cout << "-------------------------------------\n";
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
	std::vector< Edge * > tempEdgeVector;
	Edge * originalFirstNode = NULL;	//not-to-be-changed value
	Edge * firstNode = NULL;	//will be a copy of originalFirstNode but can be changed
	Edge * followingNode = NULL;	//will be the edge following the firstNode
	while (!edgesAreAllUsed())	//while at least one of the edges has not been used, this'll run through
	{
		int indexToRetrieveFrom = 0;	//start at the beginning
		while (isThisEdgeUsed(indexToRetrieveFrom) && indexToRetrieveFrom < m_adjacencyMatrix.m_vectorOfEdges.size())	//check if the edge at the index is unused, if so, move on, otherwise keep increasing index && check that the index isn't too high
		{
			indexToRetrieveFrom++;
		}
	}
}

bool EulerGraph::containsEdgeValuesWanted(int desiredValue, int index)
{	
	//if the desiredValue is either equal to the m_toNode OR m_fromNode, return true
	if (desiredValue == checkOutEdgeAtIndex(index)->m_toNode || desiredValue == checkOutEdgeAtIndex(index)->m_toNode)
		return true;
	else	//the value isn't there at all, return false;
		return false;
}

bool EulerGraph::isThisEdgeUsed(int index)
{
	if (index >= m_adjacencyMatrix.m_vectorOfEdges.size())
		return true;
	if (m_adjacencyMatrix.m_vectorOfEdges[index]->m_containedInCycle)	//if it's in a cycle, return true
		return true;
	else	//else the edge at this index must not be connected so return false
		return false;
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
	std::cout << "=================================\n---------------------------------\n=================================\n";
	std::cout << std::endl;	//after the line of char's is printed out go to the second line
}