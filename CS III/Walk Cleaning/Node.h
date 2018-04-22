#pragma once

#include <string>

class Node
{
public:
	Node();
	~Node();

	std::string title;
	int titleInt;
	int numberOfConnectionsIn;
	int numberOfConnectionsOut;
};

