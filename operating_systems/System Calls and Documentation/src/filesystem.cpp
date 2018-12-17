#include "filesystem.hpp"

fileSystemOperations::fileSystemOperations() {
}

fileSystemOperations::~fileSystemOperations() {
}

void fileSystemOperations::getcwdFunc() {
	char cwd[256];

	auto before = std::chrono::high_resolution_clock::now();
	
	for (int i = 0; i < 1000000; i++) {
		getcwd(cwd, sizeof(cwd));
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took getcwd() " << dur.count() << " seconds to perform this operation\n\n";
}

void fileSystemOperations::chdirFunc() {

	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		chdir(".");
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took chdir() " << dur.count() << " seconds to perform this operation\n\n";
}

void fileSystemOperations::accessFunc() {
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		access("/proc/self/exe", R_OK);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took access() " << dur.count() << " seconds to perform this operation\n\n";
}

void fileSystemOperations::syncFunc() {
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		sync();
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took sync() " << dur.count() << " seconds to perform this operation\n\n";
}

void fileSystemOperations::chmodFunc() {
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		chmod("/proc/self/exe", S_IRUSR);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took chmod() " << dur.count() << " seconds to perform this operation\n\n";
}

void fileSystemOperations::dup2Func() {
	auto before = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000000; i++) {
		dup2(1, 2);
	}

	auto after = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = after - before;
	std::cout << "\nIt took dup2() " << dur.count() << " seconds to perform this operation\n\n";
}
