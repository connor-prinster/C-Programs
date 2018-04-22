#include "EulerGraph.h"

EulerGraph::EulerGraph(std::string filename, std::ostream & passFout)
{
	std::cout << "Generating the graph for " << filename << std::endl;
}

void EulerGraph::computeTour(std::ostream & passFout)
{

}


void EulerGraph::generateAdjacencyMatrix(std::string filename)
{
	std::ifstream fin(filename);
	int numNodes;
	int numConnections;
	fin >> numNodes >> numConnections;
	adjacencyMatrix.numNodes = numNodes;
	adjacencyMatrix.numConnections = numConnections;

	while (!fin.eof())
	{
		char fromNodeChar;
		char toNodeChar;
		fin >> fromNodeChar >> toNodeChar;

		int fromNodeFinal = fromNodeChar;	//char to int is apparently super easy?
		int toNodeFinal = toNodeChar;
		adjacencyMatrix.addEdge(fromNodeFinal, toNodeFinal);	//takes to a public method that pushes back the edgeVector
	}
}
