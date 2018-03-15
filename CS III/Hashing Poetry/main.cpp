#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "HashTable.h"
#include "FirstWordInfo.h"

HashTable<std::string, FirstWordInfo> hashTable;	//global hashtable

void cleaningString(std::string & nextToken);	//function for creating a string free of special characters, punctuation, and uppercases
std::vector<std::string> fileToString(std::string filename);	//converts file to string and then returns a vector
std::vector<std::string> stringSplit(std::string passString, std::string filename);	//converts string to a vector in fileToString
void vecHash(std::vector<std::string>);	//will create a vecHash
void poem(std::string word, int poemLength);

int main()
{
	//----------------------------------------------------------------------//
	//     each vector now holds each individual word of the *.txt file     //
	//----------------------------------------------------------------------//
	std::vector<std::string> clownPoemVec = fileToString("clown.txt");		
	std::vector<std::string> greenPoemVec = fileToString("green.txt");	
	std::vector<std::string> inchPoemVec = fileToString("inch.txt");
	std::vector<std::string> PoePoemVec = fileToString("Poe.txt");
	std::vector<std::string> SeussPoemVec = fileToString("Seuss.txt");
	//--------------------------------------------------//
	//     create poems (firstword, length, vector)     //
	//--------------------------------------------------//
	vecHash(greenPoemVec);

	std::cout << "---REACHED END OF PROGRAM---" << std::endl;
	std::cin.get();	//just so things work on my machine
}

//================================================================================================================//
//          Function to open file and accesses cleaningString to return a toString() version of the file          //
//================================================================================================================//
std::vector<std::string> fileToString(std::string filename)
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
		std::cout << "SUCCESS" << std::endl;	//if 'fin' actually works, print success, program will continue on
	}
	else
	{
		std::cout << "\nFAILURE -- EXITING PROGRAM \nPRESS ENTER TO EXIT"; //else print fail
		cin.get();
		exit(1);	//exit program to avoid any extra problems
	}
	//-------------------------------------------------------
	while (std::getline(fin, word))
	{
		completeVector.push_back(word);	//puts the current item into the vector
	}
	for (unsigned int i = 0; i < completeVector.size(); i++)
	{
		completeString += (completeVector[i] + " "); //concatonates the word to the return string
	}

	cleaningString(completeString);

	return stringSplit(completeString, filename);
}
//=====================================================================================================

//===========================================================================================//
//          Function to remove any non-alphanumeric characters and clear uppercases          //
//===========================================================================================//
void cleaningString(std::string & token)
{
	for (unsigned int i = 0; i < token.length();)
	{
		//checking if there is some non-alphanumeric characters, and if so, remove them
		if (token[i] > 255 || token[i] < 0 || ispunct(token[i]))
		{
			token.erase(i, 1);
		}
		//regardless of if the specific char is already lowercase, make ABSOLUTELY SURE everything is lowercase
		else
		{
			token[i] = tolower(token[i]);
			i++;
		}
	}
}
//===========================================================================================//

//==========================================================================================//
//          Function to Split the String Version of the Poem into Individual Words          //
//==========================================================================================//
std::vector<std::string> stringSplit(std::string passString, std::string filename)
{
	std::istringstream iss(passString);
	std::vector<std::string> v;
	while (iss >> passString)
	{
		v.push_back(passString);
	}
	std::cout << filename << " is now successfully in vector form\n";
	return v;
}
//==========================================================================================//

//====================================================================================//
//          Fill the HashTable with a Hashed Version of the Passed-in Vector          //
//====================================================================================//
void vecHash(std::vector<std::string> vectoredFile)
{
	//runs a procedure for inserting/updating the hashtable for the length of the vecHash
	for (int unsigned i = 0; i < vectoredFile.size(); i++)
	{
		std::string cusHash = std::to_string(hashTable.customHash(vectoredFile[i]));	//creates a hash val for the current word in the vector
		FirstWordInfo * foundHash = hashTable.find(cusHash);	//find the pointer, assign it to foundHash
		hashTable.remove(cusHash);	//delete the cushash

		//check for the existence of the found val
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if (foundHash == NULL)		
		{
			//no object exists with the curHash value so we must create a new one
			FirstWordInfo * fwi = new FirstWordInfo();

			//to make sure this doesn't run over the array's bounds, i CANNOT be the last in the array
			//------------------------------------------------------------------------------------------
			if (i < (vectoredFile.size() - 1))	
			{
				fwi->word = vectoredFile[i];	//set the first word as i
				fwi->updateSecondWord(vectoredFile[i + 1]);	//since there is a second word, set the second word as i+1
			}
			else
			{
				fwi->word = vectoredFile[i];	//set the first word as i since we've reached this point, this is the last word in the vector, so we don't add a second word
			}
			//------------------------------------------------------------------------------------------

			//insert hashval, fwi into the hashtable
			hashTable.insert(vectoredFile[i], fwi);	
		}
		else
		{
			foundHash->count++;	//since the word already exists, increment the number of times it's already been found
		}
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------
	}
}

//================================================================================================================//
//          Create a Poem Starting With 'startingWord' of Length 'poemLength' from Words in vectoredFile          //
//================================================================================================================//
void poem(std::string word, int poemLength)
{

}