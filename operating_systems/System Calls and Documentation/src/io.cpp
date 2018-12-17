#include "io.hpp"

ioOperations::ioOperations() {
}

ioOperations::~ioOperations() {
}

void ioOperations::ioLoop(bool input, const char * filename) {
	char buffer[BUFSIZ];
	const char * outFile;
	outFile = "/dev/null";
	filename = "/dev/mmcblk0";

	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		//opening the files
		int inFd = open(filename, O_RDONLY);
		int outFd = open(outFile, O_WRONLY);
		//fill the buffer with the read data
		size_t readout = read(inFd, buffer, BUFSIZ);
		//write to file
		size_t writeRet = write(outFd, buffer, BUFSIZ);
		//close both files opened earlier
		int closeIn = close(inFd);
		int closeOut = close(outFd);
		//clear out buffer for later
		memset(buffer, 0, sizeof(buffer));
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took the I/O " << dur.count() << " seconds to perform this operation\n\n";
}