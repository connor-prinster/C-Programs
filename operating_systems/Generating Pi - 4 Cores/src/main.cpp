#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <queue>

#include "threadQueue.hpp"
#include "printPi.hpp"


void threadWorker(ThreadQueue& ptq) {
	while (!ptq.isEmpty()) {
		ptq.fillMapIndex(); // fill the map yo
		std::cout << "." << std::flush;
	}
}

int main(int argc, char *argv[]) {
	ThreadQueue tq;	//create a queue of size (n)
	if (argc > 1)
		tq.initializeQueue(std::atoi(argv[1])); //
	else
		tq.initializeQueue(1000);

	std::vector<std::shared_ptr<std::thread>> threads;

	for (std::uint16_t core = 0; core < std::thread::hardware_concurrency(); core++) {
		threads.push_back(std::make_shared<std::thread>(threadWorker, std::ref(tq)));
	}

	for (auto&& thread : threads) {
		thread->join();
	}

	std::cout << std::endl << std::endl;

	tq.printMap();

	std::cout << std::endl << std::endl;

	PrintPi pp;
	pp.print();

	std::cout << std::endl << std::endl;

	return 0;
}
