#include "TicTacToe.h"
#include <string>

bool TicTacToe::checkForWin(char c){
	
		if (board[0][0] == c && board[0][1] == c && board[0][2] ==c ){
			return true;
		}
		else if (board[1][0] == c && board[1][1] == c && board[1][2]==c ){
			return true;
		}
		else if (board[2][0] == c && board[2][1] == c && board[2][2]==c ){
			return true;
		}
		else if (board[0][0] == c && board[1][0] == c && board[2][0] ==c ){
			return true;
		}
		else if (board[0][1] == c && board[1][1] == c && board[2][1]==c ){
			return true;
		}
		else if (board[0][2] == c && board[1][2] == c && board[2][2]==c ){
			return true;
		}
		else if (board[0][0] == c && board[1][1] == c && board[2][2]==c ){
			return true;
		}
		else if (board[0][2] == c && board[1][1] == c && board[2][0]==c){
			return true;
		}
	
		else{
			return false;
		}
		
	
	

	




}
TicTacToe::TicTacToe(){
	reset();
}

void TicTacToe::reset(){
	numMoves = 0;
	player[0]='X';
	player[1]= 'O';
	status = ONGOING;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			board[i][j] = ' ';
			cout << board[i][j];

			
		}
		cout << endl;
	}
}

TicTacToe::Status TicTacToe::getStatus(){
	return status;

}


char TicTacToe::getPlayer1(){
	return player[0];
}
char TicTacToe::getPlayer2(){
	return player[1] ;
}
char TicTacToe::nextToMove(){
	if (numMoves % 2 == 0){
		return player[0];

	}
	else {
		return player[1];
	}


	/*for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++i){
			if (numMoves == 'X' && board[i][j] != 'X' && board[i][j] != 'O')
			{
				board[i][j] = 'X';

			}
			else if (numMoves == 'O' && board[i][j] != 'X' && board[i][j] != 'O')
			{
				board[i][j] = 'O';

			}
			else
			{
				cout << "Invalid Move. This cell has already been chosen.";

			}
		}
	}*/
	

		
	}





void TicTacToe::displayInstructions(){
	cout << "This is the game of Tic Tac Toe." << endl;
	cout << "X moves first. Each player chooses their" << endl;
	cout << "move by selecting the cell they want to place" << endl;
	cout << "their mark in. The cells are numbered as follows:" << endl;
	cout << "1 2 3 " << endl;
	cout << "4 5 6 " << endl;
	cout << "7 8 9 " << endl;
	

}
void TicTacToe::displayBoard(){
	
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "-------------------" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "-------------------" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
bool TicTacToe::move(int cell){
	int row;
	int col;
	if (cell == 1){
		row = 0;
		col = 0;
	}
	else if (cell == 2){
		row = 0;
		col = 1;
	}
	else if (cell == 3){
		row = 0;
		col = 2;
	}
	else if (cell == 4){
		row = 1;
		col = 0;
	}
	else if (cell == 5){
		row = 1;
		col = 1;
	}
	else if (cell == 6){
		row = 1;
		col = 2;
	}
	else if (cell == 7){
		row = 2;
		col = 0;
	}
	else if (cell == 8){
		row = 2;
		col = 1;
	}
	else if (cell == 9){
		row = 2;
		col = 2;
	}
	if (cell>9 || cell < 1){
		cout << "Invalid Input. Enter a number between 1 and 9." << endl;
		return false;
	}
	if (board[row][col] != ' '){
		cout << "Invalid Move. This cell has already been chosen." << endl;
		return false;
	}
	board[row][col] = nextToMove();
	

	if (((checkForWin('X')) == true) && status == ONGOING){
		status = PLAYER_1_WIN;
	}
	else if (((checkForWin('O')) == true) && status == ONGOING){
		status = PLAYER_2_WIN;


	}
	numMoves++;
	if (numMoves == 9 && status== ONGOING){
		status = DRAW;
		
		}
	
		
		return true;





}