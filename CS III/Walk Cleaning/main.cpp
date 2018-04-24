#include <iostream>
#include <iomanip>
#include "EulerGraph.h"
#include <ostream>
#include <assert.h>

void main()
{  	
	//creating the three objects customized by an input file
	EulerGraph g("prog7A.txt");
	EulerGraph g1("prog7B.txt");
	EulerGraph g2("prog7C.txt");

	//computes the tour of the given object
	g.computeTour();
	g1.computeTour();
	g2.computeTour();

	//a small asthetic to make my machine run cleanly
	std::cout << "Press any key to end program...";
	std::cin.get();
   
}