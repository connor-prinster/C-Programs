#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename)
{
	std::cout << "Generating the graph for " << filename << std::endl;
	m_filename = filename;	//the filename is now hardcoded in the EulerGraph object
	generateAdjacencyMatrix();
}

void EulerGraph::generateAdjacencyMatrix()
{
	adjacencyMatrix = AdjacencyMatrix(m_filename);
}

void EulerGraph::computeTour(std::ostream & passFout)
{

}