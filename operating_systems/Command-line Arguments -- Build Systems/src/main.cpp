#include <iostream>

#include "compute-pi.hpp"
#include "compute-fib.hpp"
#include "compute-e.hpp"

void printGenHelp();

int main(int argc, char *argv[]) {
//	printGenHelp();
	computePi pi;
	computeFib fib;
	computeEuler euler;
	if (argc < 2) {
		std::cout << "\nError: No function name given\n";
		printGenHelp();	//if the user didn't put in the correct number of arguments, just go straight to the help menu
	} else if (argc < 3) {
		std::string typedFunc = argv[1];
		if (typedFunc == "-fib" || typedFunc == "-e" || typedFunc == "-pi") {
			std::cout << "Error: function '" << argv[1] << "' expects two arguments\n";
			printGenHelp();
		}
		else {
			std::cout << "Error: '" << argv[1] << "' is not an accepted function\n";
			printGenHelp();
		}
	} else {
		std::string desiredFunc = argv[1];
		if (desiredFunc == "-pi") {
			pi.printPiToWhat(std::atoi(argv[2])); //takes to the pi function
		} else if (desiredFunc == "-fib") {
			fib.computeFibToWhat(std::atoi(argv[2]));
		} else if (desiredFunc == "-e") {
			euler.comptueEulerToWhat(std::atoi(argv[2]));
		} else {
			std::cout << "Error: '" << argv[1] << "' is not an accepted function\n";
			printGenHelp(); //something went wrong, send this to the help menu
		}
	}
}

void printGenHelp() {
	std::cout << "\n--- Help ---\n";
	std::cout << " -fib [N] : Compute the Fibonacci of [N] (0 <= N <= 40)\n";
	std::cout << " -e [N]   : Compute the value of 'e' using [N] iterations (1 <= N <= 30)\n";
	std::cout << " -pi [N]  : Display Pi to [N] digits (1 <= N <= 10)\n\n";
}
