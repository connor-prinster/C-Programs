#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <mutex>

#include "threadTask.hpp"
#include "map.hpp"
#include "computePi.hpp"

class ThreadQueue {
public:
	ThreadQueue();
	~ThreadQueue();

	void fillMapIndex(); //(un)locked method dealing with top value
	bool isEmpty(); //(un)locked method for checking size
	void initializeQueue(int size); //creates queue of size *size*
	void printMap();
	void decrementCtr();
	int returnCtr();

private:
	std::mutex mu;	//private mutex, self-explanatory
	std::queue<ThreadTask> q; //queue of tasks needed to be done
	PiMap map;
	int initSize;
	int counter;
};
