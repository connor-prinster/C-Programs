#include "threadTask.hpp"

ThreadTask::ThreadTask() { }

ThreadTask::ThreadTask(int passIndex) {
	index = passIndex;
	value = -1;
}

ThreadTask::~ThreadTask() { }

void ThreadTask::setIndex(int setIndex) {
	index = setIndex;
}

int ThreadTask::getIndex() {
	return index;
}

void ThreadTask::setValue(int passValue) {
	value = passValue;
}

int ThreadTask::getValue() {
	return value;
}
