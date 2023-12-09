#include "/Users/aztlan/work/SodukoGame/include/board.h"
#include <iostream>
#include <format>
#include <string>
#include <random>

board::board(int x) : dim_(x) {
	
	std::string msg = std::format("{}x{} sudoku board",dim_,dim_);
	std::cout << msg << std::endl;

	std::random_device rd;
     	std::mt19937 gen(rd());
    	std::uniform_int_distribution<> dis(1, 9); // Range of random numbers

	game = new int*[dim_];

	for (int i = 0; i < dim_; i++) {
            game[i] = new int[dim_];
        }

    	//Initialize each element of the array with a random number
    	for (int i = 0; i < dim_; i++) {
        	for (int j = 0; j < dim_; j++) {
            		game[i][j] = dis(gen);
        	}
    	}
}; 

void board::printBoard(){
	
	for (int i = 0; i < dim_; i++) {
		for (int j = 0; j < dim_; j++) {
			std::cout << game[i][j] << " ";
		}
		std::cout << std::endl;
	}
};


board::~board(){

// Free the memory when the object is destroyed
    	for (int i = 0; i < dim_; i++){
            		delete[] game[i];
        	}

        delete[] game;
};

