#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>

#include "UnionFind.h"
#include "EdgeNode.h"

class Graph
{
public:
	//constructors/destructors
	Graph();
	~Graph();

	//public object parameters
	int MEMBER_COUNT = 1000;	//will be MEMBER_COUNT objects in the Graph object
	std::vector<EdgeNode*> edgeVec;	//vector of EdgeNode pointers

	//public methods
	void performAllUnions();
	bool isAllConnected();
	void toString();
	void toStringComplex();
	void incrementSuccessfulUnionCount();	//setter for successfulUnions
	void incrementFindCount();	//setter for numFinds
	void incrementDayCount();	//setter for numDays

private:
	//private methods
	std::vector<EdgeNode*> fillEdgeVector();	//fill edgeVec with EdgeNode pointers
	
	//private object parameters
	void fillNameVec();	//method to fil the name vec
	std::vector<std::string> nameVec;	//vector of names
	int numDays;	//keeps track of days passed
	int successfulUnions;	//keeps track of successful unions
	int numFinds;	//keeps track of how many times find() was called
};

