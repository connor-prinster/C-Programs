#include "compute-pi.hpp"

void computePi::printPiToWhat(int toWhat) {
	if(toWhat < 1 || toWhat > 10){
		std::cout << "Error: '" << toWhat << "' is out of range for function 'pi'\n";
		std::cout << "\n--- Assign 1 Help ---\n";
		std::cout << " -fib [N] : Compute the Fibonacci of [N] (0 <= N <= 40)\n";
		std::cout << " -e [N]   : Compute the value of 'e' using [N] iterations (1 <= N <= 30)\n";
		std::cout << " -pi [N]  : Display Pi to [N] digits (1 <= N <= 10)\n\n";
	} else {
		std::cout << std::setprecision(toWhat + 1) << pi  << std::endl; // this an 'off-by-one' error as the setprecision by using the '3.*' as a precision point
	}
}
