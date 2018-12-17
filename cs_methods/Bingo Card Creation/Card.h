#pragma once
#include <vector>
#include <string>
#include <iostream>

class Card
{
public:
	Card(int cardSize, int maxNum, int cardNum);	//constructor
	~Card();	//destructor
	void toString();	//a simple toString() function to toString out a grid representation of the card

private:
	int cardSize;	//the n value of the n*n-celled card
	int maxNumber;	//max number available in the card
	void fillCard();	//fills card with random numbers
	std::string cardName;	//just makes it easier to toString out the name of the card
	std::vector< std::vector<int> > cellValues;	//vector of vectors for two dimensional vector
	std::string generatePlusLine();	//creates an individual "+-..." line
	std::string printHorizontal(std::string horizLine);	//creates a full list of "+-..." lines
	void printVertical(int idx, std::string passPlusLine);	//prints out each cell
	std::string printVertical_Space(int cellVal, std::string passPlusLine);	//generates the spaces needed at the end of each cell in printVertical()
	bool isRepeated(int passNum);	//checks that no cell is a repeat of another
};

