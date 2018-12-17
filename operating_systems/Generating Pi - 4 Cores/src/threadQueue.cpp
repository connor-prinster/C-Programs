#include "threadQueue.hpp"

ThreadQueue::ThreadQueue() { }

ThreadQueue::~ThreadQueue() { }

void ThreadQueue::fillMapIndex() {
	mu.lock();	// start lock
	ThreadTask temp;
	temp = q.front();	// read front value
	q.pop();	// kill front value
	temp.setValue(computePiDigit(temp.getIndex())); //
	map.insert(temp);
	mu.unlock();
}

bool ThreadQueue::isEmpty() {
	int currSize = initSize;
	decrementCtr();
	if (currSize > 0)
		return false;
	else
		return true;
}

void ThreadQueue::printMap() {
	map.getMapVal();
	map.print();
}

void ThreadQueue::initializeQueue(int size) {
	initSize = size;
	for (int i = 0; i < size; i++) {
		/* for the size passed in, make a
		queue of tasks for that size */
		q.push(ThreadTask(i + 1));
	}
}

void ThreadQueue::decrementCtr() {
	initSize--;
}

int ThreadQueue::returnCtr() {
	return initSize;
}