#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "HashTable.h"
#include "FirstWordInfo.h"

HashTable<std::string, FirstWordInfo> ht;	//global hashtable

void cleaningString(std::string & nextToken);	//function for creating a string free of special characters, punctuation, and uppercases
std::vector<std::string> fileToString(std::string filename);	//converts file to string and then returns a vector
std::vector<std::string> stringSplit(std::string passString, std::string filename);	//converts string to a vector in fileToString
void vecHash(std::vector<std::string>);	//will create a vecHash
void poem(std::string word, int poemLength);
std::string nextWordFromVec(FirstWordInfo *, int);

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
	std::cout << ht.toString();

	poem("sam", 20);

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
	for (unsigned int i = 0; i < vectoredFile.size(); i++)
	{
		
		FirstWordInfo * fwiForFilling = new FirstWordInfo();
		std::string currWord = vectoredFile[i];
		std::string currHashKey = ht.myHash(currWord);

		int positionWhereItExists = 0; //bool to see if a record with the same hashkey exists already
		positionWhereItExists = ht.whereDoesItExist(currHashKey);
		if (positionWhereItExists < 0)
		{
			//because whereDoesItExist returned false, must create new object
			fwiForFilling->word = currWord;	//this object now has the currWord assigned to it
			fwiForFilling->count = 1;	//since it's only appeared once, the word now has a frequency of one

			//because this may or may not be the last word in the list, we now have an if statement to decide if we add a swi to avoid overrunning bounds
			if (i < (vectoredFile.size() - 1))
			{
				//if it is at least the second to last object
				fwiForFilling->secondWordList.push_back(SecondWordInfo(vectoredFile[i + 1], 1));	//the vector now contains an anonymous swi object holding the word after currWord and a freq of one
			}
			
			ht.insert(currHashKey, fwiForFilling);	//insert the newly filled object
		}
		else if (positionWhereItExists >= 0)
		{
			FirstWordInfo * fwiForFillingExisting = ht.returnRecordAt(positionWhereItExists);
			fwiForFillingExisting->updateCount();	//since there is already an object with the same hash val, increase the amount of times it's called
			if (i < (vectoredFile.size() - 1))
			{
				fwiForFillingExisting->updateSecondWord(vectoredFile[i + 1]);	//either add or increase the frequency of a word to the secondWord vector
			}
			
			ht.remove(currHashKey);	//remove the current outdated object before inserting the updated one
			ht.insert(currHashKey, fwiForFillingExisting);	//insert the updated object
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
	std::string hashableWord = word;
	std::string nextWord = "";
	
	FirstWordInfo * fwi = new FirstWordInfo();
	
	for (int i = 0; i < poemLength; i++)
	{
		std::string hashedWord = ht.myHash(hashableWord);
		int recPos = ht.whereDoesItExist(hashedWord);	//return position of where the key is found
		fwi = ht.returnRecordAt(recPos);	//fwi is filled with the record found at recPos
		nextWord = nextWordFromVec(fwi, (rand() % fwi->count));
		hashableWord = nextWord;
		poemString += (nextWord + " ");
	}
	std::cout << poemString + "\n";
}

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
	return possWords[randomNum];
}