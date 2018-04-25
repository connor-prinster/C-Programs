#include "AvlBoard.h"
#include "AvlGameState.h"
#include "AvlTree.h"
#include "RotationGame.h"
#include "Board.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>

void customFilling(AvlBoard * passBoard, int passArr[]);
void customFillingO(OldBoard * passBoard, int passArr[]);

int main()
{
	//==========================================================//
	//					Building AvlTree 't'					//			
	//==========================================================//
	AvlTree<int> t;
	for (int i=1; i < 30; i=i+3)
	     t.insert(i);
	t.insert(7);
	t.printTree();
	std::cout << std::endl << t.findMin() << std::endl;
	std::cout << t.findMax() << std::endl;
	t.toString();
	int check = 23;
	if (!t.contains(check))
		std::cout << check << " ITEM_NOT_FOUND failed!" << std::endl;

	//================================================================//
	//					Building AvlTree 't2'						  //
	//================================================================//
	AvlTree<int> t2;
	std::cout << "Inserting 1, 3, 5, 7, 9, 11, 2, 4, 8 into AvlTree t2..." << std::endl;
	t2.insert(1);
	t2.insert(3);
	t2.insert(5);
	t2.insert(7);
	t2.insert(9);
	t2.insert(11);
	t2.insert(2);
	t2.insert(4);
	t2.insert(8);
	std::cout << "Printing Resulting AvlTree2" << std::endl;
	t2.toString();
	std::cout << "Removing 7 and 9 from AvlTree t2..." << std::endl;
	t2.remove(7);
	t2.remove(9);
	std::cout << "Printing Resulting AvlTree2" << std::endl;
	t2.toString();
	std::cout << "Inserting 50, 30, 15, 18 into AvlTree2..." << std::endl;
	t2.insert(50);
	t2.insert(30);
	t2.insert(15);
	t2.insert(18);
	std::cout << "Printing Resulting AvlTree2" << std::endl;
	t2.toString();
	std::cout << "Removing Minimum Value of " << t2.findMin() << " from AvlTree2..." << std::endl;
	t2.removeMin();
	std::cout << "Printing Resulting AvlTree2" << std::endl;
	t2.toString();
	std::cout << "Removing Minimum Value of " << t2.findMin() << " from AvlTree2..." << std::endl;
	t2.removeMin();
	std::cout << "Printing Resulting AvlTree2" << std::endl;
	t2.toString();
	std::cout << "Inserting 17 into AvlTree2..." << std::endl;
	t2.insert(17);
	std::cout << "Printing Resulting AvlTree2" << std::endl;
	t2.toString();

	//================================================================//
	//					Building AvlTree 'words'					  //
	//================================================================//
	std::string name = "this";

	AvlTree<std::string> words;
	words.insert("help");
	words.insert("me");
	words.insert("please");
	words.insert("I");
	words.insert("said");
	words.insert("help");
	words.insert("me");
	words.insert("please");
	std::cout << "Printing AvlTreeWords...\n";
	words.printTree();
	std::cout << "\n\n";
	
	//======================================================================//
	//					Building AvlTree of AvlGameStates					//
	//======================================================================//
	RotationGame rp = RotationGame();
	std::cout << " ||-----------------------------------------------------------------|| " << std::endl;
	std::cout << "||===================================================================||" << std::endl;
	std::cout << "||                  Beginning to Solve AvlGameState                  ||" << std::endl;
	std::cout << "||===================================================================||" << std::endl;
	std::cout << " ||-----------------------------------------------------------------|| " << std::endl;
	std::cout << std::endl;

	int input0Data[] = { 2, 3, 6, 4, 5, 9, 7, 8, 1 };
	int input1Data[] = { 5, 6, 4, 8, 2, 9, 1, 7, 3 };
	int input2Data[] = { 2, 1, 8, 9, 4, 7, 3, 6, 5 };

	std::cout << "See Results from a Brute Force or an A* Solve? (b/a)";
	char bOa;
	std::cin >> bOa;
	std::cout << std::endl << std::endl;
	if (bOa == 'a')
	{
		std::cout << "||===========================================================================||" << std::endl;
		std::cout << "||                 Beginning to Solve AvlGameState w/ A* Sort                ||" << std::endl;
		std::cout << "||===========================================================================||" << std::endl;
		std::cout << std::endl;
		char yOn;
		bool seeAll = false;
		std::cout << "See all Boards? (y/n)";
		std::cin >> yOn;
		std::cout << std::endl << std::endl;
		if (yOn == 'y')
		{
			seeAll = true;
		}
		AvlBoard input0 = AvlBoard();
		AvlBoard input1 = AvlBoard();
		AvlBoard input2 = AvlBoard();
		customFilling(&input0, input0Data);
		customFilling(&input1, input1Data);
		customFilling(&input2, input2Data);
		rp.aStarSolve(input0, seeAll);
		rp.aStarSolve(input1, seeAll);
		rp.aStarSolve(input2, seeAll);
	}
	else
	{
		std::cout << "||====================================================================================||" << std::endl;
		std::cout << "||                 Beginning to Solve AvlGameState w/ Brute Force Sort                ||" << std::endl;
		std::cout << "||====================================================================================||" << std::endl;

		OldBoard input00 = OldBoard();
		OldBoard input10 = OldBoard();
		OldBoard input20 = OldBoard();
		customFillingO(&input00, input0Data);
		customFillingO(&input10, input1Data);
		customFillingO(&input20, input2Data);
		rp.bruteForceSolve(input00);
		rp.bruteForceSolve(input10);
		rp.bruteForceSolve(input20);
	}

	//finishing the program so it doesn't exit without being able to see the output
	std::cout << "Press 'enter' to continue...";
	std::cin.get();
	std::cin.get();
	return 0;
}

void customFilling(AvlBoard * passBoard, int passArr[])		//The customFilling to use AvlBoards
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
void customFillingO(OldBoard * passBoard, int passArr[])	//The customFilling to use OldBoards
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