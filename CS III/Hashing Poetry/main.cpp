#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>

#include "HashTable.h"
#include "FirstWordInfo.h"

HashTable<std::string, FirstWordInfo> ht;	//global hashtable

void cleaningString(std::string & nextToken);	//function for creating a string free of special characters, punctuation, and uppercases
std::vector<std::string> fileToString(std::string filename);	//converts file to string and then returns a vector
std::vector<std::string> stringSplit(std::string passString, std::string filename);	//converts string to a vector in fileToString
void vecHash(std::vector<std::string>);	//will create a vecHash
void poem(std::string word, int poemLength);
std::string nextWordFromVec(std::string, unsigned int);
void runTestVec(std::string first, int length, bool show, std::string filename);

int main()
{
	//-----------------------------------------------------------------------//
	//     each vector now holds each individual passedHashKey of each *.txt file     //
	//-----------------------------------------------------------------------//
	std::vector<std::string> clownPoemVec = fileToString("clown.txt");		
	std::vector<std::string> greenPoemVec = fileToString("green.txt");	
	std::vector<std::string> inchPoemVec = fileToString("inch.txt");
	std::vector<std::string> PoePoemVec = fileToString("Poe.txt");
	std::vector<std::string> SeussPoemVec = fileToString("Seuss.txt");

	//--------------------------------------------------//
	//     create poems (firstword, length, vector)     //
	//--------------------------------------------------//
	
	vecHash(clownPoemVec);
	runTestVec("go", 20, true, "clown.txt");
	ht.makeEmpty();

	vecHash(greenPoemVec);
	runTestVec("sam",20, true, "green.txt");
	ht.makeEmpty();

	vecHash(inchPoemVec);
	runTestVec("computer", 50, false, "inch.txt");
	ht.makeEmpty();

	vecHash(PoePoemVec);
	runTestVec("nevermore", 50, false, "Poe.txt");
	ht.makeEmpty();

	vecHash(SeussPoemVec);
	runTestVec("mordecai", 50, false, "Seuss.txt");
	ht.makeEmpty();

	std::cout << "\n---PRESS 'ENTER' TO EXIT---" << std::endl;
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
		completeString += (completeVector[i] + " "); //concatonates the passedHashKey to the return string
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
	for (unsigned int i = 0; i < vectoredFile.size(); i++)
	{
		std::string currWord = vectoredFile[i];	//from the vectoredFile, assign currWord to a passedHashKey in the vector
		std::string currHashKey = ht.myHash(currWord);	//hash the currWord

		
		//if the object doesn't exist, we've got to make it exist
		if (ht.find(currHashKey) == NULL)
		{
			FirstWordInfo * fwi = new FirstWordInfo(currWord, 1);	//assign fwi to a fwi object with passedHashKey = currWord and count = 1

			//if it is at least the second to last spot in the vectored file, the new object MUST have a second passedHashKey
			if (i < vectoredFile.size() - 1)
			{
				fwi->updateSecondWord(vectoredFile[i + 1]);
			}
			ht.insert(currHashKey, fwi);	//insert the new object into the hashtable
		}
		else
		{
			ht.find(currHashKey)->updateCount();
			if (i < (vectoredFile.size() - 1))
			{
				ht.find(currHashKey)->updateSecondWord(vectoredFile[i + 1]);
			}
		}	
	}
}

//================================================================================================================//
//          Create a Poem Starting With 'startingWord' of Length 'poemLength' from Words in vectoredFile          //
//================================================================================================================//
void poem(std::string word, int poemLength)
{
	srand(time(NULL));
	//would create a "rand() % count"
	
	std::string poemString = "";	//initializing the string 
	std::string wordToConcat = word;

	for (unsigned int i = 0; i < poemLength; i++)
	{
		std::string hashedWord = ht.myHash(wordToConcat); //hash the passedHashKey. First time is the one passed to the function, any time other than that is the passedHashKey updated at the end of this for-loop
		FirstWordInfo * fwi = ht.find(hashedWord);
		poemString += (wordToConcat + " "); //add "<passedHashKey> " in order to make sure a space is between each passedHashKey in the poem
		int randNum = (rand() % (fwi->count)); 

		wordToConcat = nextWordFromVec(hashedWord, randNum); 
		word = wordToConcat;
	}
	std::cout << poemString + "\n";
}
//================================================================================================================//

//==========================================================================================//
//          Create a Vector To Easily Determine Which Word Should Follow the First          //
//==========================================================================================//
std::string nextWordFromVec(std::string passedHashKey, unsigned int randomNum)
{
	std::string chosenWord = "";
	FirstWordInfo * fwi = ht.find(passedHashKey);
	std::vector<std::string> possWords;
	for (unsigned int swlSpot = 0; swlSpot < fwi->secondWordList.size(); swlSpot++)
	{
		for (unsigned int swlCount = 0; swlCount < fwi->secondWordList[swlSpot].count; swlCount++)
		{
			possWords.push_back(fwi->secondWordList[swlSpot].word);
		}
	}
	if (randomNum == possWords.size() && randomNum != 0)
	{
		if (randomNum != 0)
		{
			randomNum = randomNum - 1;
			assert(randomNum < possWords.size());
		}
	}

	assert(possWords.size() != 0 && "There couldn't be a following word as this is the last word");

	return possWords[randomNum];
}
//==========================================================================================//

//====================================================================================//
//          Function to Require Only One Call From Main to Satisfy Test Reqs          //
//====================================================================================//
void runTestVec(std::string firstWord, int length, bool showNot, std::string filename)
{

	std::cout << "\n============================\n";
	std::cout << "Poem generated by " << filename << ": \n";
	std::cout << "============================\n";
	poem(firstWord, length);
	if (showNot)
	{
		std::cout << ht.toString(length);
	}
	std::cout << "\n============================\n";
	ht.makeEmpty();
}
//====================================================================================//