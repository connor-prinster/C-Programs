#pragma once
#include <iostream>
#include <vector>

class FaultTuple
{
public:
	FaultTuple();
	FaultTuple(int fs, int fc, int s);
	~FaultTuple();

	void print();
	int getFaultCount();
	void setFault(int);
	void increaseFaultCount();
	unsigned int getFrameSize();
	int getSequence();

private:
	int faultCount;
	unsigned int frameSize;
	int sequence;
};