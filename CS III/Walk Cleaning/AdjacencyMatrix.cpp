#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(std::string filename)
{
	m_filename = filename;	//easy to just have this listed
	fillFromFile();
}

void AdjacencyMatrix::fillFromFile()
{
	std::ifstream fin(m_filename);
	fin >> this->numNodes >> this->numConnections;	//the first line in the text file is "nodes connections"

	//-----------------------------------------------//
	//     resizing the outer and inner matrices     //
	//-----------------------------------------------//
	matrix.resize(numNodes);	//outer matrix
	for (int i = 0; i < numNodes; i++)
	{
		matrix[i].resize(numNodes);	//all the inner ones
	}

	//--------------------------------------//
	//     Filling in the vectorOfNodes     //
	//--------------------------------------//
	while (!fin.eof())
	{
		char originNode;
		char endNode;
		fin >> originNode >> endNode;

		int intFromCharOrigin = originNode - 'A';
		int intFromCharEnd = endNode - 'A';

		//new Edge(intFromCharOrigin, intFromCharEnd);

		//vectorOfEdges.push_back(new Edge(intFromCharOrigin, intFromCharEnd));
	}
	fin.close();
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
	for (unsigned int i = 0; i < matrix.size(); i++)	//prints the outer vector
	{	
		for (unsigned int j = 0; j < matrix[i].size(); j++)		//prints the inner vector
		{
			std::cout << matrix[i][j] << " ";	//will printMatrix completely horizontally with a space between bits of data
		}
		std::cout << std::endl;	//finishes the line with a std::endl;
	}
	std::cout << "=====================================" << std::endl;	//signifies the end of the printMatrix();
}