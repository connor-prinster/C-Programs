#include "RotationGame.h"
#include "AvlBoard.h"
#include "AvlTree.h"
#include "Board.h"
#include "DynIntQueue.h"
#include "GameState.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>



RotationGame::RotationGame(){ }

RotationGame::~RotationGame() { }

//printing to file
//ofstream outputFile;
//outputFile.open("example.txt");
//outputFile << "Writing this to a file.\n";
//outputFile.close();

//std::ofstream ofs;
//ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
//ofs.close();

void RotationGame::printBoard(AvlBoard &passedIn)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << passedIn.board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void RotationGame::printBoardFile(AvlBoard &passedIn)
{
	std::ofstream myfile("output.txt", std::ios_base::app);
	myfile << "Original Board\n";	//aesthetic details
	myfile << "-----\n";				// "
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			myfile << passedIn.board[i][j] << " ";
		}
		myfile << std::endl;
	}
	myfile << "-----\n\n";			// "
	myfile << "Running...\n";		// "
	myfile.close();	
}


void RotationGame::aStarSolve(AvlBoard &passedBoard, bool seeAll)
{
	std::ofstream myfile("output.txt", std::ios_base::app);
	std::vector<AvlGameState> vAgs;
	AvlTree<AvlGameState> avlT = AvlTree<AvlGameState>(); //creates tree
	AvlGameState avlGameState = AvlGameState(passedBoard, -1, 0, 0, "");	//creates original AvlGameState
	avlT.insert(avlGameState);	//inserts avlGameState
	AvlBoard perfect = AvlBoard(); //creates perfect AvlBoard
	bool solved = false;	//checker for do-while loop
	int currentID = 0;	//sets original value of currentID
	std::cout << "Original Board\n";	//aesthetic details
	std::cout << "-----\n";				// "
	printBoard(passedBoard);			//PRINTS BOARD
	std::cout << "-----\n\n";			// "
	std::cout << "Running...\n";		// "

	printBoardFile(passedBoard);
	

	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	do
	{
		avlGameState = avlT.findMin(); //'dequeuing tree'
		vAgs.push_back(avlGameState);
		avlT.removeMinComplex();	//deleting the minimum val
		if (avlGameState.current == perfect)		//check for perfection
		{
			if (!seeAll)
			{
				std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();	//set the end time
				std::chrono::duration<double> time = end - start;	//compute total time
				time.count();

				std::cout << "SOLVED\n\n";																						//Aesthetic data
				std::cout << "Solved Board is State " << currentID << " from State " << avlGameState.prevID << " History\n\n";	// "
				std::cout << "Moves to Solve Board: \n" << (avlGameState.allMoves);												// "
				std::cout << "\nSolve time: " << time.count() << " seconds\n";													// "
				std::cout << "==================================================" << std::endl;									// "

				myfile << "SOLVED\n\n";																						//Aesthetic data
				myfile << "Solved Board is State " << currentID << " from State " << avlGameState.prevID << " History\n\n";	// "
				myfile << "Moves to Solve Board: \n" << (avlGameState.allMoves);												// "
				myfile << "\nSolve time: " << time.count() << " seconds\n";													// "
				myfile << "==================================================" << std::endl;									// "

				solved = true;
				myfile.close();
				return;
			}
			else
			{	//the seeAll boolean has been set to true and must print off all the boards in the vAgs vector
				std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();	//set the end time
				std::chrono::duration<double> time = end - start;	//compute total time
				time.count();
				
				int removedStateCtr = 0;
				std::cout << "SOLVED\n\n";																						//Aesthetic data
				std::cout << "Solved Board is State " << currentID << " from State " << avlGameState.prevID << " History:\n";	// "
				printBoard(vAgs[0].current);
				std::cout << "--------------------------" << std::endl;
				std::cout << "  <STEPS TO SOLVE BOARD>  " << std::endl;
				std::cout << "--------------------------" << std::endl;

				myfile << "SOLVED\n\n";																						//Aesthetic data
				myfile << "Solved Board is State " << currentID << " from State " << avlGameState.prevID << " History:\n";	// "
				printBoard(vAgs[0].current);
				myfile << "--------------------------" << std::endl;
				myfile << "  <STEPS TO SOLVE BOARD>  " << std::endl;
				myfile << "--------------------------" << std::endl;
				for (int i = 1; i < vAgs.size(); i++)
				{
					std::cout << "Solved Board is State " << vAgs[i].stateID << " from State " << vAgs[i].prevID << " (" << vAgs[i].costSoFar << "):[" << vAgs[i].expCost << "] " << std::endl;
					std::cout << "====== " << std::endl;
					std::cout << "STEP " << i-1 << std::endl;
					std::cout << "====== " << std::endl;
					std::cout << "MOVE " << i << "\n" << vAgs[i].allMoves;
					std::cout << "------" << std::endl;
					printBoard(vAgs[i].current);
					std::cout << "------" << std::endl;
					std::cout << "Removed " << removedStateCtr << " states\n";

					myfile << "Solved Board is State " << vAgs[i].stateID << " from State " << vAgs[i].prevID << " (" << vAgs[i].costSoFar << "):[" << vAgs[i].expCost << "] " << std::endl;
					myfile << "====== " << std::endl;
					myfile << "STEP " << i - 1 << std::endl;
					myfile << "====== " << std::endl;
					myfile << "MOVE " << i << "\n" << vAgs[i].allMoves;
					myfile << "------" << std::endl;
					printBoard(vAgs[i].current);
					myfile << "------" << std::endl;
					myfile << "Removed " << removedStateCtr << " states\n";

					removedStateCtr++;
				}
				std::cout << "Total Solve Time: " << time.count() << " seconds\n\n";
				std::cout << "==================================================" << std::endl;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "==================================================\n\n" << std::endl;

				myfile << "Total Solve Time: " << time.count() << " seconds\n\n";
				myfile << "==================================================" << std::endl;
				myfile << "--------------------------------------------------" << std::endl;
				myfile << "==================================================\n\n" << std::endl;

				solved = true;
				myfile.close();
				return;

			}
			
		}
		for (int i = 0; i < 12; i++, currentID++)
		{
			AvlGameState avgs = AvlGameState();
			AvlBoard avlBoardCopy = avlGameState.current;	//making sure that the for-loop always starts with a 'fresh' copy of the dequeued

			std::string info = avlBoardCopy.move(i); //the super fun move function I'm glad I didn't have to write
			//int tempExpCost = avlBoardCopy.computeExpCost();	//calculate expected cost

			avlT.insert(AvlGameState(avlBoardCopy, avlGameState.stateID, currentID, avlGameState.costSoFar + 1, avlGameState.allMoves + info)); //insert anon AvlGameState
		}
	} while (!solved);
	
}


//==================================================================//
//					 BruteForceSolve Print Function					//			
//==================================================================//
void RotationGame::printBoardO(OldBoard &passedIn)
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

void RotationGame::printBoardOFile(OldBoard &passedIn)
{
	std::ofstream myfile("output.txt", std::ios_base::app);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			myfile << passedIn.board[i][j] << " ";
		}
		myfile << std::endl;
	}
	myfile.close();
}


//==============================================================//
//					 BruteForceSolve Function					//			
//==============================================================//
void RotationGame::bruteForceSolve(OldBoard &passedBoard)
{
	std::ofstream myfile("output.txt", std::ios_base::app);
	OldDynIntQueue myQ;
	OldGameState gameState = OldGameState(passedBoard, -1, 0, "");
	myQ.enqueue(gameState);
	OldBoard perfect = OldBoard();
	bool solved = false;
	int currentID = 0;
	std::cout << "Original Board\n";
	std::cout << "-----\n";
	printBoardO(passedBoard);
	printBoardOFile(passedBoard);
	std::cout << "-----\n\n";
	std::cout << "Running...\n";

	myfile << "Original Board\n";
	myfile << "-----\n";
	printBoardO(passedBoard);
	printBoardOFile(passedBoard);
	myfile << "-----\n\n";
	myfile << "Running...\n";


	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	do
	{
		myQ.dequeue(gameState);
		for (int i = 0; i < 12; i++, currentID++)
		{
			OldBoard boardCopy = gameState.current;
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

				myfile << "SOLVED\n\n";
				myfile << "Solved Board is State " << currentID << " from State " << gameState.prevID << " History\n\n";
				myfile << "Moves to Solve Board: \n" << (gameState.allMoves + info);
				myfile << "\nSolve time: " << time.count() << " seconds\n";
				myfile << "==================================================" << std::endl;
				return;
			}
			//printBoard(boardCopy);
			myQ.enqueue(OldGameState(boardCopy, gameState.stateID, currentID, gameState.allMoves + info));
		}
	} while (!solved);
	myfile.close();
}