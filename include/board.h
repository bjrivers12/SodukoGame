#ifndef BOARD_H
#define BOARD_H

class board {

public:
	board(int x); //default constructor
	~board(); // default destructor
	void printBoard(); // method to print board
private:
	int dim_;
	int** game;
};

#endif







