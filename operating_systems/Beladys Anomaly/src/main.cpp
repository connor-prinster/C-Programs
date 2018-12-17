#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>

#include "tuple.hpp"

const int SEQUENCE_SIZE = 1000;
const unsigned int PAGE_MIN = 1;
const unsigned int PAGE_MAX = 250;
const unsigned int NUM_PAGES = 100;
const unsigned int MAX_FRAME = 100;

void print(FaultTuple smaller, FaultTuple larger);
std::vector<unsigned int> genRandom();
void checkForAnomalies(std::vector<std::vector<FaultTuple>>);
bool isAnomaly(FaultTuple first, FaultTuple second);

int main(int argc, char *argv[]) {
	//auto initTime = std::chrono::high_resolution_clock::now(); //for timing

	std::cout << "Length of memory reference string: " << SEQUENCE_SIZE << std::endl;
	std::cout << "Frames of physical memory: " << NUM_PAGES << std::endl << std::endl;

	//fill up 'pages' with 100 randomly generated vectors
	std::vector<std::vector<unsigned int>> pages;
	for (int i = 0; i < NUM_PAGES; i++) {
		pages.push_back(genRandom());	//push the 100 random sequences back
	}

	std::vector<std::vector<FaultTuple>> faultContainer;	//set up a vector for holding faults
	for (int i = 0; i < NUM_PAGES; i++) {
		std::vector<FaultTuple> faultLine;	//set up a line of faults to put in main vector
		for (int j = 1; j < (MAX_FRAME + 1); /* because it starts at 1 */ j++) {
			faultLine.push_back(FaultTuple(j, 0, i));	//a fault to line of faults
		}
		faultContainer.push_back(faultLine);	//push the line of faults into the bigger table
	}

	/*
		i = 0-99th sequence
		j = fault holder with 0-99th frame size
		k = 0-999th spot in the sequence
	*/
	for (int i = 0; i < NUM_PAGES; i++) {
		int val = 1;
		for (int j = 0; j < NUM_PAGES; j++) {
			//=============================
			//=============================
			FaultTuple fault = faultContainer[i][j];	//get the fault out of the group
			std::vector<unsigned int> sequence = pages[i];	//get the sequence out
			unsigned int frameSize = fault.getFrameSize();	//get the frame size of the fault
			int arr[251];	//initialize an array with possibilities 1-250
			for (int z = 0; z < 250; z++) {
				arr[z] = 0;
			}
			//std::fill(arr, 250, 0);
			std::queue<int> queue;	//need a queue

			for (int k = 0; k < SEQUENCE_SIZE; k++) {
				int tempVal = sequence[k];	//temp value is the kth random number
				if (queue.empty()) { //if queue is empty
					fault.increaseFaultCount();
					arr[tempVal] = 1;	//set it as a part of the 
					queue.push(tempVal);	//push it into the queue
				}
				else { //if queue is not empty
					int front = queue.front();
					if (arr[tempVal] != 1) { //doesn't exist in the queue
						//pageFaults++;	//INCREASE PAGE FAULTS
						fault.increaseFaultCount();
						arr[front] = 0;	//assign the arr[front] a false
						arr[tempVal] = 1;	//assign arr[tempVal] a true
						if (queue.size() == frameSize) { //if queue is full
							queue.pop();	//pop the first one off
							//queue.push(tempVal);	//push the new one in the back
						}
						else if (queue.size() < frameSize) { //if queue isn't full
							//queue.push(tempVal);
						}
						queue.push(tempVal);
					}
				}
			}
			faultContainer[i][j] = fault;
			//std::cout << faultContainer[i][j].getFaultCount() << std::endl;	//purely for testing and debugging
		}
	}

	checkForAnomalies(faultContainer);

	//auto finalTime = std::chrono::high_resolution_clock::now();	//timing
	//std::chrono::duration<double> dur = finalTime - initTime;	//timing
	//std::cout << dur.count();	//timing
	//std::cin.get();	//debugging stuffz
}

bool isAnomaly(FaultTuple first, FaultTuple second) {
	if (first.getFaultCount() < second.getFaultCount()) {
		return true;
		//return false;	//if first is less than second, correct so will return false
	}
	return false;
	//return true;	//if second is less than first, error, return true;
}

void checkForAnomalies(std::vector<std::vector<FaultTuple>> faultContainer) {
	/*
		i is the different sequences
		j is the different frame sizes
	*/
	int anomCount = 0;
	for (int i = 0; i < NUM_PAGES; i++) {
		for (int j = 0; j < NUM_PAGES - 1; j++) {
			FaultTuple first = faultContainer[i][j];
			FaultTuple second = faultContainer[i][j + 1];
			if (isAnomaly(first, second)) {
				anomCount++;
				std::cout << "Anomaly Discovered!\n";
				print(first, second);
			}
		}
	}
	std::cout << "Anomaly detected " << anomCount << " times." << std::endl;
}

int countFaults(std::vector<unsigned int> sequence, unsigned int frameSize) {
	int pageFaults = 0;
	int arr[251];
	std::queue<int> queue;

	for (int k = 0; k < SEQUENCE_SIZE; k++) {
		int tempVal = sequence[k];
		if (queue.empty()) { //if queue is empty
			pageFaults++;	//is a fault
			arr[tempVal] = 1;	//set it as a part of the 
			queue.push(tempVal);	//push it into the queue
		}
		else { //if queue is not empty
			int front = queue.front();
			if (arr[tempVal] != 1) { //doesn't exist in the queue
				pageFaults++;	//INCREASE PAGE FAULTS
				arr[front] = 0;	//assign the arr[front] a false
				arr[tempVal] = 1;	//assign arr[tempVal] a true
				if (queue.size() == frameSize) { //if queue is full
					queue.pop();	//pop the first one off
					queue.push(tempVal);
				}
				else if (queue.size() < frameSize) { //if queue isn't full
					queue.push(tempVal);
				}
			}
		}
	}
	return pageFaults;
}

//not sure how this works exactly, but it returns a .length() == 1000 random vector
std::vector<unsigned int> genRandom() {
	std::random_device rd;
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<unsigned int> dist{ PAGE_MIN, PAGE_MAX };

	std::vector<unsigned int> sequence;
	sequence.resize(SEQUENCE_SIZE);
	std::generate(sequence.begin(), sequence.end(), [&]() { return dist(engine); });

	return sequence;
}

//just good for printing
void print(FaultTuple smaller, FaultTuple larger) {
	std::cout << "   Anomaly Discovered\n";
	std::cout << "   Sequence: " << smaller.getSequence() << std::endl;
	//smaller
	std::cout << "   Page Faults:" << smaller.getFaultCount() << " @ Frame Size: " << smaller.getFrameSize() << std::endl;
	//larger
	std::cout << "   Page Faults:" << larger.getFaultCount() << " @ Frame Size: " << larger.getFrameSize() << std::endl << std::endl;
}