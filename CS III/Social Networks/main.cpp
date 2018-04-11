#include <iostream>
#include <string>
#include <time.h>

#include "Graph.h"

int main()
{
	Graph g;	//practice Graph object

	g.performAllUnions();

	std::cout << "Press 'ENTER' to exit program";
	std::cin.get();	//just for help on my machine
}
