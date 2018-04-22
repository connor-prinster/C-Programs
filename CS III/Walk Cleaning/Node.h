#pragma once

#include <string>

class Node
{
public:
	Node(std::string title);

	std::string title;
	int titleInt;
	int numberOfConnectionsIn;
	int numberOfConnectionsOut;
};

