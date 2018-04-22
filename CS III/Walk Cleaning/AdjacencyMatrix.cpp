#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix()
{

}

AdjacencyMatrix::AdjacencyMatrix(int n)
{
	
}

void AdjacencyMatrix::addEdge(int origin, int destination)
{
	
}

void AdjacencyMatrix::printMatrix()
{
	std::cout << " //======================================\\  \n";		//just a typical header that I personally think makes things more readable
	std::cout << "||   Current State of Adjacency Matrix:   || \n";
	std::cout << " \\======================================//  \n";
	for (int i = 0; i < adjacencyMatrix.size(); i++)	//prints the outer vector
	{	
		for (int j = 0; j < adjacencyMatrix[i].size(); j++)		//prints the inner vector
		{
			std::cout << adjacencyMatrix[i][j] << " ";	//will printMatrix completely horizontally with a space between bits of data
		}
		std::cout << std::endl;	//finishes the line with a std::endl;
	}
	std::cout << "=====================================" << std::endl;	//signifies the end of the printMatrix();
}


AdjacencyMatrix::~AdjacencyMatrix()
{
}
