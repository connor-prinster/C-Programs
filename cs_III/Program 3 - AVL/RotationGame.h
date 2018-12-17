#pragma once
#include "AvlBoard.h"
#include "Board.h"


class RotationGame
{
public:
	RotationGame();
	~RotationGame();
	void aStarSolve(AvlBoard &passedBoard, bool seeAll);
	void bruteForceSolve(OldBoard &passedBoard);
	void printBoard(AvlBoard &passedIn);
	void printBoardFile(AvlBoard &passedIn);
	void printBoardO(OldBoard &passedIn);
	void printBoardOFile(OldBoard &passedIn);
};

