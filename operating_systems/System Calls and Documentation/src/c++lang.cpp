#include "c++lang.hpp"

operationLoops::operationLoops() {
}

operationLoops::~operationLoops() {
}

void operationLoops::arithmetic() {
	int var1 = 1;
	int var2 = 1
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		var += var2
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took '+' " << dur.count() << " seconds to perform this operation\n\n";
}

void operationLoops::mathLab() {
	int var = 0;
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		var = sqrt(100);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took sqrt() " << dur.count() << " seconds to perform this operation\n\n";
}

void operationLoops::newDel() {
	char * myPointer;
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		myPointer = new char[1];
		delete myPointer;
		myPointer = NULL;
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took allocating/deleting " << dur.count() << " seconds to perform this operation\n\n";
}

void operationLoops::newNoDel() {
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		char * q = new char;
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took allocating/deleting " << dur.count() << " seconds to perform this operation\n\n";

}

//auto before = std::chrono::high_resolution_clock::now();
//
//auto after = std::chrono::high_resolution_clock::now();
//std::chrono::duration<double> dur = after - before;
//std::cout << "\nIt took allocating/deleting " << dur.count() << " seconds to perform this operation\n\n";
