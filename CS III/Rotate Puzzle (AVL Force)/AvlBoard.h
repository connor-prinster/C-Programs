#ifndef BOARD_H
#define BOARD_H
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>



class AvlBoard {
public:
	static const int BOARD_SIZE = 3;
	int board[BOARD_SIZE][BOARD_SIZE];  // Values of board
	AvlBoard(const AvlBoard & b);  //Create board from another board
	std::string move(int m);  //m is which move.  Returns string describing move
	void makeBoard(int jumbleCt = 0);  //Starting from a perfect board, do jumbleCt moves to alter it
	std::string toString() const;  //return a string which represents the contents of the board
	bool operator==(AvlBoard &b);   //Return true if two boards are equal
	AvlBoard(){ makeBoard(); };
	void rotateEast(int row);
	void rotateWest(int row);
	void rotateNorth(int col);
	void rotateSouth(int col);
	void inputBoard(std::string fn);
	void jumble(int ct);  //Do jumble moves to alter board
};
#endif