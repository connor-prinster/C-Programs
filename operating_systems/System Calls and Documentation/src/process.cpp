#include "process.hpp"

processOperations::processOperations() {
}

processOperations::~processOperations() {
}

void processOperations::killFunc(int signal, int pid) {
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		kill(pid, signal);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took kill(" << signal << ")-ing " << dur.count() << " seconds to perform this operation\n\n";
}

void processOperations::nanosleepFunc(long nanoDelay) {
	auto before = std::chrono::high_resolution_clock::now();

	struct timespec req = { 0 };
	req.tv_sec = 0;
	req.tv_nsec = nanoDelay;

	for (int i = 0; i < 1000000; i++) {
		nanosleep(&req, NULL);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took nanosleep(" << nanoDelay << ")-ing " << dur.count() << " seconds to perform this operation\n\n";
}

void processOperations::forkFunc() {
	auto before = std::chrono::high_resolution_clock::now();
	
	for(int i = 0; i < 1000000; i++) {
		if (fork() == 0) {
			exit(0);
		}
		wait(0);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took fork() " << dur.count() << " seconds to perform this operation\n\n";
}
