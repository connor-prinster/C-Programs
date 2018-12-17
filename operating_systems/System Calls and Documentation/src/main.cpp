#include <iostream>
#include <string>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#include "c++lang.hpp"
#include "process.hpp"
#include "filesystem.hpp"
#include "io.hpp"

void printMenuList();
void inputDirectory(std::string, int, char *, bool);
void forkHelper() {
	processOperations po;
	po.forkFunc();
}

void ctrlCatch(int a) {
	printMenuList();
}

void sigusrCatch(int a) {
	//this does nothing tbh
}

int main(int argc, char *argv[]) {
	//initialize the choice
	std::string choice = "";
	//installs the signal handler for ctrl-c and reroutes it
	signal(SIGINT, ctrlCatch);
	//makes the SIGUSR2 just die a silent death
	signal(SIGUSR2, sigusrCatch);
	//need this to pass
	char * filename;
	//the last index will be the size - 1
	int lastIdx = argc - 1;
	//if there are fewer than two args, no flags given 
	if (argc < 2) {
		printMenuList();
	}
	//one char means must have put in letter/number 
	else if (argc < 3 && strlen(argv[1]) < 2) { 
		inputDirectory(argv[1], getpid(), filename, false);
	}
	//more than three inputs means either multiple chars or a file name.
	else if (argc > 2) {
		//if the size of the last index is a single character, it's a char, no filename
		if(strlen(argv[lastIdx]) < 2) {
			inputDirectory(argv[lastIdx], getpid(), filename, false);
		}
		//if the size of the last index is more than a single char, it's a filename, the 
		//second to last is the flag
		else if (strlen(argv[lastIdx]) > 1) {
			filename = argv[lastIdx];
			inputDirectory(argv[lastIdx - 1], getpid(), filename, false);
		}
	}
}

//print out menu list and return the user's input
void printMenuList() {
	//need the pid to work correctly
	int pid = getpid();
	//just initialize the string
	std::string inputVal = "";
	//this is the menu printout
	std::cout << "Time wasting main menu PID: " << pid << "\n";
	std::cout << "\t0) C++ artimetic\n";
	std::cout << "\t1) Math library()\n";
	std::cout << "\t2) new/delete char[1]\n";
	std::cout << "\t3) new char[1]\n";
	std::cout << "\t4) kill(0)\n";
	std::cout << "\t5) kill(SIGUSR2)\n";
	std::cout << "\t6) nanosleep(1)\n";
	std::cout << "\t7) nanosleep(1,000)\n";
	std::cout << "\t8) nanosleep(1,000,000)\n";
	std::cout << "\t9) fork()\n";
	std::cout << "\ta) getcwd\n";
	std::cout << "\tb) chdir()\n";
	std::cout << "\tc) access(/proc/self/exe)\n";
	std::cout << "\td) sync()\n";
	std::cout << "\te) chmod()\n";
	std::cout << "\tf) dup2()\n";
	std::cout << "\tg) I/O Bound loop over /dev/mmcblk0\n";
	std::cout << "\tq) quit this fine program\n";
	std::cout << "Selection: ";
	//pull in the inputVal
	std::cin >> inputVal;
	//this is just a dead filename
	char * filename;
	//	the input value must be pushed, the pid must stay the same, filename is passed if there 
	//	is one, false because no filename was given
	inputDirectory(inputVal, pid, filename, false);
}

void inputDirectory(std::string inputVal, int pid, char * filename, bool ioFlag) {
	operationLoops ol;
	processOperations po;
	fileSystemOperations fso;
	ioOperations iOp;
	
	if (inputVal == "0" || inputVal == "-0") {
		std::cout << "Beginning the C++ Arithmetic Option:";
		ol.arithmetic();
	}
	else if (inputVal == "1" || inputVal == "-1") {
		std::cout << "Beginning the Math Library() Option:";
		ol.mathLab();
	}
	else if (inputVal == "2" || inputVal == "-2") {
		std::cout << "Beginning the New/Delete Char Option:";
		ol.newDel();
	}
	else if (inputVal == "3" || inputVal == "-3") {
		std::cout << "Beginning the New Char Option:";
		ol.newNoDel();
	}
	else if (inputVal == "4" || inputVal == "-4") {
		std::cout << "Beginning the Kill(0) Option:";
		po.killFunc(0, pid);
	}
	else if (inputVal == "5" || inputVal == "-5") {
		std::cout << "Beginning the Kill(SIGUSR2) Option:";
		po.killFunc(SIGUSR2, pid);
	}
	else if (inputVal == "6" || inputVal == "-6") {
		std::cout << "Beginning the nanosleep(1) Option:";
		po.nanosleepFunc(1);
	}
	else if (inputVal == "7" || inputVal == "-7") {
		std::cout << "Beginning the nanosleep(1,000) Option:";
		po.nanosleepFunc(1000);
	}
	else if (inputVal == "8" || inputVal == "-8") {
		std::cout << "Beginning the nanosleep(1,000,000) Option:";
		po.nanosleepFunc(1000000);
	}
	else if (inputVal == "9" || inputVal == "-9") {
		forkHelper();
	}
	else if (inputVal == "a" || inputVal == "-a") {
		std::cout << "Beginning the getcwd() Option:";
		fso.getcwdFunc();
	}
	else if (inputVal == "b" || inputVal == "-b") {
		std::cout << "Beginning the Chdir() Option:";
		fso.chdirFunc();
	}
	else if (inputVal == "c" || inputVal == "-c") {
		std::cout << "Beginning the access(/proc/self/exe) Option:";
		fso.accessFunc();
	}
	else if (inputVal == "d" || inputVal == "-d") {
		std::cout << "Beginning the sync() Option:";
		fso.syncFunc();
	}
	else if (inputVal == "e" || inputVal == "-e") {
		std::cout << "Beginning the chmod() Option:";
		fso.chmodFunc();
	}
	else if (inputVal == "f" || inputVal == "-f") {
		std::cout << "Beginning the dup2() Option:";
		fso.dup2Func();
	}
	else if (inputVal == "g" || inputVal == "-g") {
		std::cout << "Beginning the I/O Bound Loop Over /dev/mmcblk0 Option:";
		iOp.ioLoop(ioFlag, filename);
	}
	else if (inputVal == "q") {
		std::cout << "\nQuitting\n";
		exit(0);
	}
	else {
		//if we got here, no correct input was placed
		std::cout << "\nInvalid Input\n\n";
		//go to menu list to end up here again
		printMenuList();
	}
	printMenuList();
}
