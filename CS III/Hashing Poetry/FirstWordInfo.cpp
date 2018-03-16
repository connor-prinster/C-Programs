#include "FirstWordInfo.h"

FirstWordInfo::FirstWordInfo()			 
{							
	word = "";
	count = 0;
}										 
FirstWordInfo::~FirstWordInfo()			 
{										 
}										 

//==================================================================================//
void FirstWordInfo::updateCount() 
{
	count++;
};

//-----------------------------------------------------------//
//          Typical toString Function for Debugging          //
//-----------------------------------------------------------//
std::string FirstWordInfo::toString()
{
	std::string swlContents = "The word \"" + word + "\" is said " + std::to_string(count) + " time(s) and has the following " + std::to_string(secondWordList.size()) + " possibilities: "; //prints "the word <word> has the following <size> possibilities: "

	for (unsigned int i = 0; i < secondWordList.size(); i++)
	{
		swlContents += secondWordList[i].toString();	//repeatedly concatonates the toString() method of each SecondWordInfo object in secondWordList
	}
	swlContents += "\n";

	return swlContents; //returns "the word <word> has the following <size> possibilities: <followingWord(freq)>\n"
}

//---------------------------------------------------------------------//
//          Custom Constructor Created by A Word and a Number          //
//---------------------------------------------------------------------//
FirstWordInfo::FirstWordInfo(std::string s, int c)
{
	word = s;
	count = c;
}

//--------------------------------------------------------------------------//
//          Based on the First Word, Adjust Second Word to Meet it          //
//--------------------------------------------------------------------------//
void FirstWordInfo::updateSecondWord(std::string word)
{
	bool wordWasFound = false;
	for (int i = 0; i < secondWordList.size(); i++)
	{
		if (secondWordList[i].word == word)
		{
			secondWordList[i].increment();	//since the word was found, it needs to be added
			wordWasFound = true;
		}
	}
	if (!wordWasFound)
	{
		secondWordList.push_back(SecondWordInfo(word, 1));	//since the word wasn't found, add a new swi to the vector with (word, 1)
	}
}
//==================================================================================//
