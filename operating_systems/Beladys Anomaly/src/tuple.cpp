#include "tuple.hpp"

FaultTuple::FaultTuple() { 
	frameSize = 0;
	faultCount = 0;
	sequence = 0;
}
FaultTuple::~FaultTuple() { }

FaultTuple::FaultTuple(int fs, int fc, int s) {
	frameSize = fs;
	faultCount = fc;
	sequence = s;
}

void FaultTuple::print() {
	std::cout << "Page Faults: " << faultCount << " @ Frame Size: " << frameSize << std::endl;
}

int FaultTuple::getFaultCount() {
	return faultCount;
}

void FaultTuple::increaseFaultCount() {
	faultCount++;
}

unsigned int FaultTuple::getFrameSize() {
	return frameSize;
}

int FaultTuple::getSequence() {
	return sequence;
}

void FaultTuple::setFault(int newCount) {
	faultCount = newCount;
}

