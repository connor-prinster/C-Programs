#pragma once

#include <iostream>
#include <unordered_map>
#include <mutex>
#include <vector>
#include <string>

#include "threadTask.hpp"

class PiMap
{
public:
	PiMap();
	~PiMap();
	void insert(ThreadTask);
	void getMapVal();
	void incrementCtr();
	int getCtr();
	bool pleaseStop();
	void print();
	char getPiVal(int idx);

private:
	std::unordered_map<int, int> piPairs;
	std::mutex mu;
	std::vector<int> piVals;
	int mapCtr = 1;
};