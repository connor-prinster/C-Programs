#include "compute-e.hpp"

void computeEuler::comptueEulerToWhat(int sayWhen) {
	if(sayWhen < 1 || sayWhen > 30){
		std::cout << "Error: '" << sayWhen << "' is out of range for function 'e'\n";
		std::cout << "\n--- Assign 1 Help ---\n";
       	        std::cout << " -fib [N] : Compute the Fibonacci of [N] (0 <= N <= 40)\n";
		std::cout << " -e [N]   : Compute the value of 'e' using [N] iterations (1 <= N <= 30)\n";
		std::cout << " -pi [N]  : Display Pi to [N] digits (1 <= N <= 10)\n\n";
	} else {
		long double euler = 0;
		for (int i = 0; i < sayWhen; i++) {
			euler += computeTaylorSection(i);
		}
		std::cout << std::setprecision(sayWhen) <<  euler << std::endl;
	}
}

long computeEuler::computeFactorial(int toWhat) {
	long factorial = 1;
	for(int i = 1; i <= toWhat; i++) {
		factorial *= i;
	}
	return factorial;
}

long double computeEuler::computeTaylorSection(int whichFactorial) {
    long double factorial = computeFactorial(whichFactorial);
	long double dec = (1 / factorial);
	return dec;
}
