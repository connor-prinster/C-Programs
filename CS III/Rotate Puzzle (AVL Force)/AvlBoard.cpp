#include "AvlBoard.h"

void AvlBoard::inputBoard(std::string fn)
{
	std::ifstream inf;
	inf.open(fn.c_str());
	//assert(inf.good());
	for (int i= 0; i < BOARD_SIZE; i++)
		for (int j=0; j<BOARD_SIZE;j++)
		   inf >> board[i][j];
}

// Create a printable representation of the AvlBoard class
// The stringstream allows you to use the power of output commands in creating a string
std::string AvlBoard::toString() const {
	std::stringstream ss;
	for (int i=0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			ss << board[i][j] << " ";
		ss << std::endl;
	}
	return ss.str();
};

// return true if board is identical to b
bool AvlBoard::operator==(AvlBoard &b) {
	
	for (int i=0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (board[i][j] != b.board[i][j]) return false;
	return true;
}

//Create a board by performing legal moves on a board
//jumbleCt indicates the number of moves that may be required
//if jumbleCt ==0, return the winning board
void AvlBoard::makeBoard(int jumbleCt) {
	int val=1;
	for (int i=0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = val++;
	jumble(jumbleCt);
}

//Copy constructor
AvlBoard::AvlBoard(const AvlBoard & b) {
	//cout << "Just Copied AvlBoard\n" << b.toString() << endl;
	assert(BOARD_SIZE > 0);
	for (int i=0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = b.board[i][j];
}


//Rotate East using row specified
void AvlBoard::rotateEast(int row){
	if (row <0|| row >=BOARD_SIZE) return;
	int wrap = board[row][BOARD_SIZE-1];
	for (int i = BOARD_SIZE-2; i >=0; i--)
		board[row][i+1] = board[row][i];
	board[row][0] = wrap;
}
//Rotate West using row specified
void AvlBoard::rotateWest(int row){
	if (row <0 || row >=BOARD_SIZE) return;
	int wrap = board[row][0];
	for (int i = 0; i <BOARD_SIZE-1; i++)
		board[row][i] = board[row][i+1];
	board[row][BOARD_SIZE-1] = wrap;
}

//Rotate South using column specified
void AvlBoard::rotateSouth(int col){
	if (col <0||col >=BOARD_SIZE) return;
	int wrap = board[BOARD_SIZE-1][col];
	for (int i = BOARD_SIZE-2; i >=0; i--)
		board[i+1][col] = board[i][col];
	board[0][col] = wrap;
}
//Rotate North using column specified
void AvlBoard::rotateNorth(int col){
	if (col <0||col >=BOARD_SIZE) return;
	int wrap = board[0][col];
	for (int i = 0; i <BOARD_SIZE-1; i++)
		board[i][col] = board[i+1][col];
	board[BOARD_SIZE-1][col] = wrap;
}

// Randomly apply ct moves to the board
void AvlBoard::jumble(int ct) {
	for (int i=0; i < ct; i++)
		move(rand()%(BOARD_SIZE*4));
}


// Make one move.  m indicates which move is wanted. Return string describing the move
std::string AvlBoard::move(int m){
	std::stringstream ss;
	ss << ":";
	int sub = m/ 4;
	switch (m%4)
	{
	case 0:  rotateNorth(sub); ss << "up " << sub << std::endl; break;
	case 1:  rotateSouth(sub); ss << "down " << sub << std::endl; break;
	case 2:  rotateEast(sub); ss << "right " << sub << std::endl; break;
	case 3:  rotateWest(sub); ss << "left " << sub << std::endl; break;
	}
	return ss.str();
}