#include <iostream>
#include <iomanip>
#include "EulerGraph.h"
#include <ostream>
#include <assert.h>
using namespace std;

void main()
{  	ofstream fout;
	fout.open("tourOut.txt");
	assert(fout);	//make sure this thing is actually lit.

   EulerGraph g("prog7A.txt");
   g.computeTour(fout);  // If I want the output to appear on console, I just make the parameter "cout"

   EulerGraph g1("prog7B.txt");
   g1.computeTour(fout);

   EulerGraph g2("prog7C.txt");
   g2.computeTour(cout);

   std::cout << "Press any key to end program...";
   std::cin.get();
}