#pragma once
#include "Board.h"

#include <string>

const int SIZE = 3;

class GameState
{
public:
	Board current; //contents of current board
	int stateID; //State ID of the current board
	int prevID; //State of the previous board
	std::string allMoves; //what are all the moves you made?

	GameState() //base constructor
	{
		current.makeBoard();
	}
	GameState(Board curr, int prev, int currID, std::string all) //custom constructor
	{
		current = curr;
		stateID = currID;
		prevID = prev;
		allMoves = all;
	}
};

