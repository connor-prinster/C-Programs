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
std::string nextWordFromVec(FirstWordInfo *, int);
void runTestVec(std::string first, int length, bool show, std::string filename);

int main()
{
	//-----------------------------------------------------------------------//
	//     each vector now holds each individual word of each *.txt file     //
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

	vecHash(greenPoemVec);
	runTestVec("sam", 20, true, "green.txt");

	vecHash(inchPoemVec);
	//runTestVec("computer", 50, false, "inch.txt");

	vecHash(PoePoemVec);
	runTestVec("nevermore", 50, false, "Poe.txt");
	
	//vecHash(SeussPoemVec);
	//runTestVec("mordecai", 50, false, "Seuss.txt");
	//ht.makeEmpty();

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
	for (unsigned int i = 0; i < vectoredFile.size(); i++)
	{
		std::string currWord = vectoredFile[i];	//from the vectoredFile, assign currWord to a word in the vector
		std::string currHashKey = ht.myHash(currWord);	//hash the currWord

		
		//if the object doesn't exist, we've got to make it exist
		if (ht.find(currHashKey) == NULL)
		{
			FirstWordInfo * fwi = new FirstWordInfo(currWord, 1);	//assign fwi to a fwi object with word = currWord and count = 1

			//if it is at least the second to last spot in the vectored file, the new object MUST have a second word
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
	
	FirstWordInfo * fwi = new FirstWordInfo();
	
	for (int i = 0; i < poemLength; i++)
	{
		std::string hashedWord = ht.myHash(wordToConcat);	//hash the passed word
		fwi = ht.find(hashedWord);
		poemString += (wordToConcat + " ");	//concatonate the hashed word to the poemString
		int randNum = (rand() % (fwi->count));
		if (randNum == fwi->count)
		{
			randNum -= 1;	//to adjust for when it has to be accessed by a vector starting with index 0
		}
		wordToConcat = nextWordFromVec(fwi, randNum);	//access function to find the next word
	}
	std::cout << poemString + "\n";
}
//================================================================================================================//

//==========================================================================================//
//          Create a Vector To Easily Determine Which Word Should Follow the First          //
//==========================================================================================//
std::string nextWordFromVec(FirstWordInfo * passFWI, int randomNum)
{
	std::vector<std::string> possWords;
	std::string chosenWord = "";
	
	//runs a for-loop for as long as there are different words in secondWordList
	for (int spotInSWL = 0; spotInSWL < passFWI->secondWordList.size(); spotInSWL++)
	{
		//runs a for-loop for as long as the count of times a word is said
		for (int j = 0; j < passFWI->secondWordList[spotInSWL].count; j++)
		{
			possWords.push_back(passFWI->secondWordList[spotInSWL].word);
		}
	}
	assert(randomNum < possWords.size());
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