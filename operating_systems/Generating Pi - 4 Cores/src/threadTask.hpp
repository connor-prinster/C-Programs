#pragma once

#include <iostream>
#include <queue>

class ThreadTask {
public:
	ThreadTask();
	ThreadTask(int passIndex);
	~ThreadTask();
	void setIndex(int setIndex);
	int getIndex();
	void setValue(int passValue);
	int getValue();

private:
	int index;
	int value;
};