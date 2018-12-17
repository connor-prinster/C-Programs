#include "map.hpp"

PiMap::PiMap() { }

PiMap::~PiMap() { }

void PiMap::insert(ThreadTask tt) {
	piPairs.insert(std::make_pair(tt.getIndex(), tt.getValue()));
}

void PiMap::getMapVal() {
	while (!pleaseStop()) {
		mu.lock();
		std::unordered_map<int, int>::const_iterator got = piPairs.find(getCtr());
		incrementCtr();
		if (got == piPairs.end() || got->second < 0) {
			//piVals.push_back(-1);	//an error
			return;
		}
		else {
			//piPairs.erase(got->first); //delete key
			piVals.push_back(got->second); //the value it should be
		}
		mu.unlock();
	}
}

void PiMap::incrementCtr() {
	mapCtr++;
}

int PiMap::getCtr() {
	return mapCtr;
}

bool PiMap::pleaseStop() {
	return (mapCtr == piPairs.size() + 1);
}

void PiMap::print() {
	std::string str = "";
	std::cout << "3.";
	for (unsigned int i = 0; i < piVals.size(); i++) {
		std::cout << piVals[i];
	}
}

char PiMap::getPiVal(int idx) {
	if (idx == 0) {
		return '3';
	}
	else if (idx == 1) {
		return '.';
	}
	else {
		int newIdx = idx - 2; //to make up for the shifting above
		char charInt = '0' + piVals[idx];
		return charInt;
	}
}


