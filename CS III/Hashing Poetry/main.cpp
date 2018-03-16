#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "HashTable.h"
#include "FirstWordInfo.h"

HashTable<std::string, FirstWordInfo> ht;	//global hashtable

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
	for (unsigned int i = 0; i < vectoredFile.size(); i++)
	{
		FirstWordInfo * fwiForCheckingNull = NULL; //create blank object for each potential word in vector
		FirstWordInfo * fwiForFilling = NULL;
		std::string currWord = vectoredFile[i];
		std::string currHashKey = ht.myHash(currWord);

		fwiForCheckingNull = ht.returnRecordAt(currHashKey);
		if (fwiForCheckingNull == NULL)
		{
			//because returnRecordAt returned a NULL, there is no matching key so we must create an object
			fwiForFilling->word = currWord;	//this object now has the currWord assigned to it
			fwiForFilling->count = 1;	//since it's only appeared once, the word now has a frequency of one

			//because this may or may not be the last word in the list, we now have an if statement to decide if we add a swi to avoid overrunning bounds
			if (i < (vectoredFile.size() - 1))
			{
				//if it is at least the second to last object
				fwiForFilling->secondWordList.push_back(SecondWordInfo(vectoredFile[i + 1], 1));	//the vector now contains an anonymous swi object holding the word after currWord and a freq of one
			}
		}
		else if (fwiForCheckingNull != NULL)
		{
			fwiForFilling->updateCount();	//since there is already an object with the same hash val, increase the amount of times it's called
			fwiForFilling->updateSecondWord(currWord);	//either add or increase the frequency of a word to the secondWord vector
		}
		
		ht.insert(currHashKey, fwiForCheckingNull);
	}





	////runs a procedure for inserting/updating the hashtable for the length of the vecHash
	//for (int unsigned i = 0; i < vectoredFile.size(); i++)
	//{
	//	//FirstWordInfo * foundHash = NULL;	//creates an object that can be used
	//	
	//	FirstWordInfo * foundHash = new FirstWordInfo();
	//	std::string currHashKey = hashTable.myHash(vectoredFile[i]);	//creates the hash of the word
	//	//int currPos = hashTable.returnPos(currHashKey);	//return the position of where the hash is
	//	foundHash = hashTable.returnRecordAt(currHashKey);	//based off a hashkey, return the object (if it exists)
	//	
	//	//check for the existence of the found val
	//	//------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//	if (foundHash == NULL)		
	//	{
	//		//no object exists with the curHash value so we must create a new one
	//		FirstWordInfo * fwiForCheckingNull = new FirstWordInfo();

	//		//to make sure this doesn't run over the array's bounds, i CANNOT be the last in the array
	//		//------------------------------------------------------------------------------------------
	//		if (i < (vectoredFile.size() - 1))	
	//		{
	//			fwiForCheckingNull->word = vectoredFile[i];	//set the first word as i
	//			fwiForCheckingNull->updateSecondWord(vectoredFile[i + 1]);	//since there is a second word, set the second word as i+1
	//		}
	//		else
	//		{
	//			fwiForCheckingNull->word = vectoredFile[i];	//set the first word as i since we've reached this point, this is the last word in the vector, so we don't add a second word
	//		}
	//		//------------------------------------------------------------------------------------------
	//		
	//		//insert hashval, fwiForCheckingNull into the hashtable
	//		hashTable.insert(currHashKey, fwiForCheckingNull);	
	//	}
	//	else if (foundHash != NULL)
	//	{
	//		foundHash->updateCount();	//since the word already exists, increment the number of times it's already been found by one
	//		//hashTable.returnPos(currHashKey);
	//		hashTable.remove(currHashKey);
	//		hashTable.insert(currHashKey, foundHash);
	//	}
	//	//------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//}
}

//================================================================================================================//
//          Create a Poem Starting With 'startingWord' of Length 'poemLength' from Words in vectoredFile          //
//================================================================================================================//
void poem(std::string word, int poemLength)
{

}