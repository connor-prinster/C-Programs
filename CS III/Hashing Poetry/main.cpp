#include <iostream>
#include <string>
#include <fstream>

#include "HashTable.h"

void cleaningString(std::string & nextToken); //function for creating a string free of 
															//	special characters, punctuation, and uppercases

int main()
{
	string filename = "";										//initializing variable filename
	//===========================================================================================
	//DEALING WITH OPENING THE FILE
	
	//----------------------
	//hardwiring for testing purposes

	//std::cout << "Enter filename to generate poem from: ";		//prompting user for filename
	//std::cin >> filename;										//user inputs filename
	filename = "Seuss.txt";
	std::cout << std::endl;	
	//----------------------

	//-------------------------------------------------------
	//checking that the file actually exists
	std::cout << "Attempting to open " << filename << "...";
	std::ifstream fin(filename);
	if (fin)	std::cout << "SUCCESS" << std::endl;	//if 'fin' actually works, print success
	else		std::cout << "FAILURE" << std::endl;	//else pring failure
	//-------------------------------------------------------
	//===========================================================================================

	std::cin.get();	//just so things work on my machine
}

void cleaningString(std::string & nextWord)
{
	for (int i = 0; i < nextWord.length();)
	{
		//checking if there is some non-alphanumeric characters, and if so, remove them
		if (nextWord[i] > 255 || nextWord[i] < 0 || ispunct(nextWord[i]))
		{
			nextWord.erase(i, 1);
		}
		//regardless of if the specific char is already lowercase, make sure everything is lowercase
		else
		{
			nextWord[i] = tolower(nextWord[i]);
			i++;
		}
	}
}