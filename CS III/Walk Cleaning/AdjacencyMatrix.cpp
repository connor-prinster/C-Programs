#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int n)
{
	//resizes to make sure that everything is the correct size before filling it.
	matrix.resize(n);
	for (int i = 0; i < n; i++)
	{
		matrix[i].resize(n);
	}

	//fills array with 0's
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void AdjacencyMatrix::addEdge(int origin, int destination)
{
	matrix[origin][destination] = 1;	//says that the edge at (x, y) actually exists
}

void AdjacencyMatrix::printMatrix()
{
	std::cout << " //======================================\\  \n";		//just a typical header that I personally think makes things more readable
	std::cout << "||   Current State of Adjacency Matrix:   || \n";
	std::cout << " \\======================================//  \n";
	for (int i = 0; i < matrix.size(); i++)	//prints the outer vector
	{	
		for (int j = 0; j < matrix[i].size(); j++)		//prints the inner vector
		{
			std::cout << matrix[i][j] << " ";	//will printMatrix completely horizontally with a space between bits of data
		}
		std::cout << std::endl;	//finishes the line with a std::endl;
	}
	std::cout << "=====================================" << std::endl;	//signifies the end of the printMatrix();
}