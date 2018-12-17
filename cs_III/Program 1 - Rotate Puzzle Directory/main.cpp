#include "Board.h"
#include "DynIntQueue.h"
#include "GameState.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>

//==========================================================================
void customFilling(Board * passBoard, int passArr[])
{
	int num9 = 0;
	//Filling newBoard1
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			passBoard->board[i][j] = passArr[num9];
			num9++;
		}
	}
}

void printBoard( Board &passedIn)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << passedIn.board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void solveIt(Board &passedBoard)
{
	DynIntQueue myQ;
	GameState gameState = GameState(passedBoard, -1, 0, "");
	myQ.enqueue(gameState);
	Board perfect = Board();
	bool solved = false;
	int currentID = 0;
	std::cout << "Original Board\n";
	std::cout << "-----\n";
	printBoard(passedBoard);
	std::cout << "-----\n\n";
	std::cout << "Running...\n";

	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	do
	{
		myQ.dequeue(gameState);
		for (int i = 0; i < 12; i++, currentID++)
		{
			Board boardCopy = gameState.current;
			std::string info = boardCopy.move(i);
			if (boardCopy == perfect)
			{
				std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> time = end - start;
				time.count();

				std::cout << "SOLVED\n\n";
				std::cout << "Solved Board is State " << currentID << " from State " << gameState.prevID << " History\n\n";
				std::cout << "Moves to Solve Board: \n" << (gameState.allMoves + info);
				std::cout << "\nSolve time: " << time.count() << " seconds\n";
				std::cout << "==================================================" << std::endl;
				return;
			}
			//printBoard(boardCopy);
			myQ.enqueue(GameState (boardCopy, gameState.stateID, currentID, gameState.allMoves + info));
		}
	} while (!solved);
}

int main()
{
	//===========================================================//
	//Filling in the boards for "Input 1 - Input 3"
	int board1Data[] = {1, 2, 3, 6, 4, 5, 9, 7, 8};
	int board2Data[] = {4, 2, 9, 7, 5, 3, 1, 8, 6};
	int board3Data[] = {6, 7, 2, 1, 5, 9, 3, 4, 8};
	Board boardPerfect = Board();
	Board board1 = Board();
	Board board2 = Board();
	Board board3 = Board();
	customFilling(&board1, board1Data);
	customFilling(&board2, board2Data);
	customFilling(&board3, board3Data);
	//Filling in board 4 (which is randomly generated)
	Board board4 = Board();
	srand(time(NULL));
	board4.makeBoard(10);
	//===========================================================//
	solveIt(board1);
	solveIt(board2);
	solveIt(board3);
	solveIt(board4);
	//===========================================================//
	std::cout << "Press any key to continue...";
	std::cin.get();
}





