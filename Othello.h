#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"




#ifndef OTHELLO_H
#define OTHELLO_H

using namespace std;



class Othello
{
	private:
		int** board;
		int size = 8;
		
		//if true, player goes first. AI otherwise
		bool turn;

		//0, or O
		int player_piece;
		//1, or X
		int AI_piece;

		//AI #1
		Tree tree;

	public:
		Othello();
		

		//runs the game
		void run();
		//if it was player's turn, it's now AI's turn
		void changeTurn();
		//returns true if it's player's turn to move. false otherwise
		bool isPlayersTurn();
		//player's turn to move. returns true if successful
		bool playersMove();
		//AI's turn to move. returns true if successful
		bool AIMove(int AI_version);
		//returns true if player won the game
		bool playerWon();
		//returns true if AI won the game
		bool AIWon();
		bool place_piece(int** board, int piece, int col, int row);
		void convert_to_coordinates(string position, int * coordinates);
		string convert_to_notation(int col, int row);

		//returns array of possible moves in string format
		vector<vector<int>> possibleMoves(int piece);
		void get_neighbors(int* neighbors, int x, int y);
		//reset's game
		void resetGame();

		int count_flips(vector<int> col_list, int piece, int other_piece);
		vector<int> get_column(int** board, int col);
		vector<int> get_row(int** board, int row);
		vector<int> get_up_diagonal(int** board, int col, int row);
		vector<int> get_down_diagonal(int** board, int col, int row);

		int countPieces(int** board, int piece);

};


#endif

