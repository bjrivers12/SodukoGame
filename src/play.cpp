#include <iostream>
#include "/Users/aztlan/work/SodukoGame/include/board.h"

int main(){

	int size;

	std::cout << "enter the size of the board you wish to play : ";	

	std::cin >> size;

	std::cout << "you chose a " << size << "x" << size << " board" << std::endl;

	board game1(size);

	game1.printBoard();	

	return 0;
}

