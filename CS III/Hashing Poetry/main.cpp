#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "HashTable.h"

void cleaningString(std::string & nextToken); //function for creating a string free of 
											  //	special characters, punctuation, and uppercases
std::string returnCleanFileString(std::string filename);

int main()
{
	string filename = "";										//initializing variable filename
	//std::cout << "Enter filename to generate poem from: ";	//prompting user for filename
	//std::cin >> filename;										//user inputs filename
	filename = "green.txt"; //filename set for hardwiring testing
	returnCleanFileString(filename);

	std::cin.get();	//just so things work on my machine
}

std::string returnCleanFileString(std::string filename)
{
	//-------------------------------------------------------
	//checking that the file actually exists
	std::string word;
	vector <std::string> completeVector;
	std::string completeString = "";
	std::cout << "Attempting to open " << filename << "...";
	std::ifstream fin(filename);
	if (fin)
	{
		std::cout << "SUCCESS" << std::endl;	//if 'fin' actually works, print success
	}
	else
	{
		std::cout << "FAILURE -- EXITING PROGRAM \nPRESS ENTER TO EXIT" << std::endl; //else print failure
		cin.get();
		exit(1);
	}
	//-------------------------------------------------------
	while (std::getline(fin, word))
	{
		completeVector.push_back(word);	//puts the current item into the vector
	}
	for (int i = 0; i < completeVector.size(); i++)
	{
		completeString += (completeVector[i] + " "); //concatonates the word to the return string
	}

	cleaningString(completeString);

	return completeString;
}

void cleaningString(std::string & token)
{
	for (int i = 0; i < token.length();)
	{
		//checking if there is some non-alphanumeric characters, and if so, remove them
		if (token[i] > 255 || token[i] < 0 || ispunct(token[i]))
		{
			token.erase(i, 1);
		}
		//regardless of if the specific char is already lowercase, make sure everything is lowercase
		else
		{
			token[i] = tolower(token[i]);
			i++;
		}
	}
}