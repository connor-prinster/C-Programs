#include <iostream>
#include <iomanip>
#include "EulerGraph.h"
#include <ostream>
#include <assert.h>

void main()
{  	
	//creating the three objects customized by an input file (also does all the work inside the constructor)
	EulerGraph g("prog7A.txt");
	EulerGraph g1("prog7B.txt");
	EulerGraph g2("prog7C.txt");

	//a small asthetic to make my machine run nicely
	std::cout << "Press any key to end program...";
	std::cin.get();
   
}