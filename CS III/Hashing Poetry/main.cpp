#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "HashTable.h"

void cleaningString(std::string & nextToken); //function for creating a string free of 
											  //	special characters, punctuation, and uppercases
std::string returnCleanStringFromFile(std::string filename);

int main()
{
	string filename = "";										//initializing variable filename
	//std::cout << "Enter filename to generate poem from: ";	//prompting user for filename
	//std::cin >> filename;										//user inputs filename
	filename = "green.txt"; //filename set for hardwiring testing
	returnCleanStringFromFile(filename);

	std::cin.get();	//just so things work on my machine
}

std::string returnCleanStringFromFile(std::string filename)
{
	//-------------------------------------------------------
	//checking that the file actually exists
	std::string word;
	vector <std::string> completeVector;
	std::string completeString = "";
	std::cout << "Attempting to open " << filename << "...";
	std::ifstream fin(filename);
	if (fin)	std::cout << "SUCCESS" << std::endl;	//if 'fin' actually works, print success
	else		std::cout << "FAILURE" << std::endl;	//else print failure
	//-------------------------------------------------------
	while (std::getline(fin, word))
	{
		completeVector.push_back(word);
	}
	for (int i = 0; i < completeVector.size(); i++)
	{
		completeString += (completeVector[i] + " ");
	}
	return completeString;
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