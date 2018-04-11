#include "EdgeNode.h"

void EdgeNode::toString()
{
	std::cout << "\n-----NODE REPORT-----";
	std::cout << "\n===================================\n";
	std::cout << nameForFun << std::endl;
	std::cout << "\nCurrent Node:   " << selfVal << std::endl;
	std::cout << "\nParent Node: " << parentIdx << std::endl;
	std::cout << "===================================\n";
}