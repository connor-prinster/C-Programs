#include <iostream>
#include <string>

#include "HashTable.h"

void removeExtraCharacters(std::string & nextToken); //function for creating a string free of 
															//	special characters, punctuation, and uppercases

int main()
{
	std::cout << "Hello World" << std::endl;

	std::cin.get();
}

void removeExtraCharacters(std::string & nextWord)
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