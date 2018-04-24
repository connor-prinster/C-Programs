#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(std::string filename)	//custom constructor that builds from the filename
{
	m_filename = filename;	//easy to just have this hardcoded
	fillFromFile();
	m_isEuler = isEuler();
}

bool AdjacencyMatrix::isEuler()
{
	for (unsigned int i = 0; i < matrix.size(); i++)	//check rows
	{
		int toCheckIfEven = 0;	//initialize value
		for (unsigned int j = 0; j < matrix[i].size(); j++)	//check cols
		{
			toCheckIfEven += matrix[i][j];	//since every value in the matrix is either one or zero, adding them together will either be meaningless or increment by one
		}
		if (toCheckIfEven % 2 != 0)	//if the sum is not even that means the matrix column has an uneven number of connections
			return false;		//return false if not even
		toCheckIfEven = 0;
	}
	return true;
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
		char originNode;	//the first char in the file
		char endNode;	//the second char in the file
		fin >> originNode >> endNode;	//fills the above two variables so an edge can be made
		Edge * tempEdge = new Edge(originNode, endNode);
		tempEdge->set(originNode, endNode);
		vectorOfEdges.push_back(tempEdge);	//filling the vector with all the edges from the file
		addEdge(originNode, endNode);
	}
	fin.close();	//closes the fin object
}

void AdjacencyMatrix::addEdge(int origin, int destination)
{
	origin -= 'A';
	destination -= 'A';
	matrix[origin][destination] = 1;	//says that the edge at (x, y) actually exists
	matrix[destination][origin] = 1;	//also state that (y, x) is also technically a connection as it's undirected
	origin += 'A';
	destination -= 'A';
}

void AdjacencyMatrix::printMatrix()
{
	std::cout << "//======================================\\  \n";		//just a typical header that I personally think makes things more readable
	std::cout << "||   Current State of Adjacency Matrix: || \n";
	std::cout << "\\======================================//  \n";
	for (unsigned int i = 0; i < matrix.size(); i++)	//prints the outer vector
	{	
		for (unsigned int j = 0; j < matrix[i].size(); j++)		//prints the inner vector
		{
			std::cout << matrix[i][j] << " ";	//will printMatrix completely horizontally with a space between bits of data
		}
		std::cout << std::endl;	//finishes the line with a std::endl;
	}
	std::cout << "==========================================\n" << std::endl;	//signifies the end of the printMatrix();
}