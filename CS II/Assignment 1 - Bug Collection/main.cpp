#include <iostream>
#include <vector>
#include <algorithm>

#include "Bug.hpp"
#include "TestCases.hpp"


void printBugs(std::vector<Bug> bugs)
{
	//TODO:write a function that prints all the contents of the bug array.  Use Bug::print() for each bug. 
	//=======================================================================================//
	Bug c_bug;
	int sizeOf = bugs.size();

	for (int i = 0; i < sizeOf; i++)
	{
		bugs[i].print();
	}
	//=======================================================================================//
	//
}

void sortMass(std::vector<Bug>& bugs)
{
	//TODO:write a function to bubble sort the contents of a bug array based on the mass
	//=======================================================================================//
	Bug bug;
	int sizeOfSort = bugs.size();
	bool swapped;
	Bug temp;
	do
	{
		swapped = false;
		for (int i = 0; i < sizeOfSort - 1; i++)
		{
			//std::cout << "getMass() is: " << bugs[i].getMass() << std::endl;
			if (bugs[i].getMass() < bugs[i + 1].getMass())
			{
				temp = bugs[i];
				bugs[i] = bugs[i + 1];
				bugs[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
	//=======================================================================================//
	//
}

int main()
{
	const unsigned int NUMBUGS = 5;

	//TODO: make a vector of NUMBUGS bugs
	//=======================================================================================//
	std::vector<Bug> bugs(NUMBUGS);
	//=======================================================================================//

	std::cout << std::endl << "-- Initial Bugs --" << std::endl << std::endl;
	printBugs(bugs);
	executeTest(testCase1, bugs, "Initial Bugs");

	//TODO: add three more bugs to the vector
	//=======================================================================================//
	std::vector<Bug> newBugVector(3);

	for (int i = 0; i < 3; i++)
	{
		Bug newBuggo = newBugVector[i];
		bugs.push_back(newBuggo);
	}
	//=======================================================================================//
	//

	std::cout << std::endl << "-- Three More Bugs --" << std::endl << std::endl;
	printBugs(bugs);
	executeTest(testCase2, bugs, "Three More Bugs");

	sortMass(bugs);

	std::cout << std::endl << "-- Sorted By Mass --" << std::endl << std::endl;
	printBugs(bugs);
	executeTest(testCase3, bugs, "Sorted By Mass");

	//TODO: get rid of the 5 bugs with the greatest mass
	//=======================================================================================//
	std::reverse(bugs.begin(), bugs.end());
	//---------------------------------------------------------------------------------------//
	for (int i = 0; i < (NUMBUGS); i++)
	{
		bugs.pop_back();
	}
	//=======================================================================================//
	//

	std::cout << std::endl << "-- Removed Five Biggest --" << std::endl << std::endl;
	printBugs(bugs);
	executeTest(testCase4, bugs, "Removed Five Biggest");

	std::cin.get();

	return 0;
}
