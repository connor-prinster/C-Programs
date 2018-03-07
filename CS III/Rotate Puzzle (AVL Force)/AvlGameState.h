#pragma once
#include "AvlBoard.h"
#include "AvlTree.h"

#include <string>

const int BOARD_SIZE = 3;

class AvlGameState
{
public:
	AvlBoard current; //contents of current board
	int stateID; //State ID of the current board
	int prevID; //State of the previous board
	int costSoFar; //number of moves from initial state
	int expCost;	//expected cost to reach next solution
	std::string allMoves; //what are all the moves you made?

	AvlGameState() //base constructor
	{
		current.makeBoard();
	}
	AvlGameState(AvlBoard curr, int prev, int currID, int currCost, std::string all) //custom constructor
	{
		current = curr;
		stateID = currID;
		prevID = prev;
		costSoFar = currCost;
		expCost = computeExpCost();
		allMoves = all;
	}

	int computeExpCost()
	{
		int computedCost = 0;
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if ((current.board[i][j] - 1) / 3 != i) computedCost++;
				if ((current.board[i][j] - 1) % 3 != j) computedCost++;
			}
		}
		return computedCost/3;
	}
	
	bool operator<(AvlGameState ags) const
	{
		if (this->costSoFar + this->expCost < ags.costSoFar + ags.expCost) return true;
		else return false;
	}

	bool operator>(AvlGameState ags) const
	{
		if (this->costSoFar + this->expCost > ags.costSoFar + ags.expCost) return true;
		else return false;
	}

	bool operator<=(AvlGameState ags) const
	{
		if (this->costSoFar + this->expCost <= ags.costSoFar + ags.expCost) return true;
		else return false;
	}

	bool operator>=(AvlGameState ags) const
	{
		if (this->costSoFar + this->expCost >= ags.costSoFar + ags.expCost) return true;
		else return false;
	}
};
