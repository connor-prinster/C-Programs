#pragma once

#include <vector>
#include <iostream>

#include "EdgeNode.h"

class UnionFind
{
public:
	//methods
	bool Union(int root1, int root2, std::vector<EdgeNode*> v);	//unions two objects
	int find(int x, std::vector<EdgeNode*> v);	//finds a value
	std::vector<int> checkUpVec;
};

