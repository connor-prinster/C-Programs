#pragma once

#include <string>
#include <iostream>

class EdgeNode
{
public:
	//constructor
	EdgeNode(std::string name, int self) : parentIdx(-1), nameForFun(name), selfVal(self), rank(0) {};	//constructor used by the Graph.* files

	//methods
	void toString();	//just a standard toString function that might not be used. It's more for debugging use than anything.

	//object parameters
	int parentIdx;	//the "parent" node's int representation
	int selfVal;	//This EdgeNodes integer representation
	int rank;	//this is a rough estimate of rank
	std::string nameForFun;	//the name of the person. More for fun than anything.
};

