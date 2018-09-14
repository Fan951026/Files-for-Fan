#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
#include <string>

using namespace std;
class TicTacToe
{

public:
	enum Status { ONGOING, DRAW, PLAYER_1_WIN, PLAYER_2_WIN };
	TicTacToe();
	void reset();
	Status getStatus();
	char getPlayer1();
	char getPlayer2();
	char nextToMove();
	void displayInstructions();
	void displayBoard();
	bool move(int cell);


private:
	
	bool checkForWin(char c);
	char board[3][3];
	int numMoves;
	char player[2];
	Status status;










};
#endif;