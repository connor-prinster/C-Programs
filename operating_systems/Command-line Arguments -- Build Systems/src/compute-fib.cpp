#include "compute-fib.hpp"

#include <iostream>

void computeFib::computeFibToWhat(int sayWhen) {
    if(sayWhen < 1 || sayWhen > 10){
		std::cout << "Error: '" << sayWhen << "' is out of range for function 'pi'\n";
		std::cout << "\n--- Assign 1 Help ---\n";
		std::cout << " -fib [N] : Compute the Fibonacci of [N] (0 <= N <= 40)\n";
		std::cout << " -e [N]   : Compute the value of 'e' using [N] iterations (1 <= N <= 30)\n";
		std::cout << " -pi [N]  : Display Pi to [N] digits (1 <= N <= 10)\n\n";
    } else {
		int a = 0;	//the first number
		int b = 1;	//the second number
		int c;	//this stores the combination of a and b
		for(int i = 2; i < ( sayWhen + 1); i++){
			c = a + b;	//basically a temporary variable
			a = b;	//the first number = the second number
			b = c;	//the second number = the combination
		}
		std::cout << b << std::endl;
	}
}
