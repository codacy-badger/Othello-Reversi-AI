#include <iostream>
#include <string>



#ifndef Board_H
#define Board_H

using namespace std;



class Board
{
	private:
		//side length of the Othello board
		static const int size = 8;
		//percentage of the "neuron" that gets increment if its path results in a good outcome
		// static constexpr double perc = 0.25;

		int white_piece = 2;
		int black_piece = 1;




		double weights[size][size] =
	    {
	        {10,-2,2,0.5,0.5,2,-2,10},
	        {-2,-4,-0.5,-0.5,-0.5,-0.5,-4,-2},
	        {2,-0.5,1.5,0.3,0.3,1.5,-0.5,2},
	        {0.5,-0.5,0.3,0.3,0.3,0.3,-0.5,0.5},
	        {0.5,-0.5,0.3,0.3,0.3,0.3,-0.5,0.5},
	        {2,-0.5,1.5,0.3,0.3,1.5,-0.5,2},
	        {-2,-4,-0.5,-0.5,-0.5,-0.5,-4,-2},
	        {10,-2,2,0.5,0.5,2,-2,10}
	    };

	public:
		// int** board;


		Board();
		void resetBoard(int**& board);
		//places specified piece on the specified board at the specified position, and flips the opponent's pieces
		bool place_piece(int**& board, int piece, int col, int row);
		
		double getPossibleMovesCount(int**& board, int piece);
		vector<vector<int>> getPossibleMoveCoordinates(int**& board, int piece);
		vector<int**> getPossibleMoveBoards(int**& board, int piece);

		//callbacks list of pieces surrounding specified position
		void get_neighbors(int**& board, int* neighbors, int x, int y);
		int countPieces(int**& board, int piece);
		void printBoard(int**& board, int num_indents=0);

		bool isEqual(int**& board, int**& other_board);
		int getPieceAtPosition(int**& board, int col, int row);
		void copyBoard(int**& board, int**& old_board);

};



#endif


