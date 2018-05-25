#include "Card.hpp"

Card::Card()
{
	
}

Card::Card(int cardSize, int maxNum, int cardNum)
{
	std::string numToStr = std::to_string(cardNum);
	this->cardSize = cardSize;
	this->maxNumber = maxNum;
	this->cardName = "Card #" + std::to_string(cardNum);	//will read as "Card #cardNum". Makes it easier for toString function
	this->fillCard();	//will fill cards with random numbers
}

void Card::fillCard()
{
	//resize the card
	//--------------------------------------------------------------------------
	cellValues.resize(cardSize);	//resize the cards rows to size cardSize
	cellValues.resize(cardSize);	//resize the cards rows to size cardSize
	for (unsigned int i = 0; i < cellValues.size(); i++)
	{
		cellValues[i].resize(cardSize);	//resize each column to size cardSize
	}
	//--------------------------------------------------------------------------

	//fill in the card with values
	int actualMax = maxNumber * maxNumber;
	//------------------------------------------------------------------------------------------------------------
	for (unsigned int rows = 0; rows < cellValues.size(); rows++)	//runs through all the rows of the card
	{
		for (unsigned int cols = 0; cols < cellValues[rows].size(); cols++)	//runs through all the cols of the card
		{
			int thisRand = rand() % maxNumber + 1;
			bool numIsRepeat = isRepeated(thisRand);
			while (numIsRepeat)	//while the number passed already exists (ideally it will never return a true value, but it might)
			{
				thisRand = rand() % actualMax + 1;	//generates a new number to try on the next pass
				numIsRepeat = isRepeated(thisRand);
			}
			cellValues[cols][rows] = thisRand;	//the cellValue at [rows][cols] is now assigned "thisRand"
		}
	}
	//------------------------------------------------------------------------------------------------------------s
}

bool Card::isRepeated(int passNum)	//checks the entire vector for repeats
{
	for (unsigned int rows = 0; rows < cellValues.size(); rows++)	//rows
	{
		for (unsigned int cols = 0; cols < cellValues[0].size(); cols++)	//cols
		{
			int cellVal = cellValues[rows][cols];
			if (passNum == cellVal)	//if the passed number == any of the cellValues, then return true
			{
				return true;
			}
		}
	}
	return false;	//if there are no repeats return false
}

void Card::toString()
{
	std::cout << cardName << "\n";
	std::string plusLine = generatePlusLine();
	std::string completeHoriz = printHorizontal(plusLine);
	unsigned int ctr = 0;
	while (ctr < cellValues[0].size())
	{
		std::cout << completeHoriz;
		printVertical(ctr, plusLine);
		ctr++;
	}
	std::cout << completeHoriz;
}

std::string Card::generatePlusLine()
{
	for (unsigned int i = 0; i < cellValues.size(); i++)
	{
		for (unsigned int j = 0; j < cellValues[i].size(); j++)
		{
			if (cellValues[i][j] > 99)
				return "+-----";	//if the value is over 100, the val is over three integers long so make sure it has five lines for formatting
		}
	}
	return "+----";	//else return four lines for formatting
}

std::string Card::printHorizontal(std::string horizLine)
{
	std::string returnString = "";
	for (unsigned int i = 0; i < cellValues.size(); i++)
	{
		returnString += horizLine;
		//std::cout << horizLine;	//cout horizLine for as long as it's necessary
	}
	//std::cout << "+\n";	//makes sure that at the end of the line it makes sure there is an end "+" and then a newline character
	returnString += "+\n";
	return returnString;
}

void Card::printVertical(int idx, std::string passPlusLine)
{
	for (unsigned int i = 0; i < cellValues[idx].size(); i++)
	{
		if (i == 0)
			std::cout << "| ";
		std::cout << cellValues[idx][i] << printVertical_Space(cellValues[idx][i], passPlusLine) << "| ";	//for each element in the vector, toString out a single cell
	}
	std::cout << "\n";
}

std::string Card::printVertical_Space(int cellVal, std::string passPlusLine)	//makes sure that the spaces are correctly assigned
{
	if (passPlusLine == "+-----")	//if the greatest number is three digits
	{
		if (cellVal < 10)	//if single digit value
			return "   ";
		else if (cellVal < 100)	//if double digit
			return "  ";
		else if (cellVal < 1000)	//if triple digit
			return " ";
	}
	else if (passPlusLine == "+----")	//if the greatest number is two digits
	{
		if (cellVal < 10)	//if single digit
			return "  ";
		else if (cellVal < 100)	//if double digit value
			return " ";
		else if (cellVal < 1000)
			return "";
	}
	return "";
}

Card::~Card()
{
	for(unsigned int i = 0; i < cellValues.size(); i++)
	{
		for(unsigned int j = 0; j < cellValues[i].size(); j++)
		{
			cellValues[i][j] = 0;
		}
		cellValues[i].clear();
	}
}
