#include <iostream>
#include <string>
#include "TicTacToe.h"

using namespace std;

int main(){

	TicTacToe T;
	char game = 'y';
	int cell;
	T.displayInstructions();
	while (game =='y'){
		T.reset();
			

		while (T.getStatus() == TicTacToe::ONGOING){

			T.displayBoard();
			cout << "Enter move for player " << T.nextToMove()<<" :";

			cin >> cell;
			T.move(cell);

		}

		if (T.getStatus() == TicTacToe::PLAYER_1_WIN){
			cout << "Player X won!" << endl;
			cout << "Would you like to play again (y/n)?" << endl;
			cin >> game;
		
		
		}
		else if (T.getStatus() == TicTacToe::PLAYER_2_WIN){
			cout << "Player O won!" << endl;
			cout << "Would you like to play again (y/n)?" << endl;
			cin >> game;
	
			
		}
		else if (T.getStatus() == TicTacToe::DRAW){
			cout << "The Game was a draw!" << endl;
			cout << "Would you like to play again (y/n)?" << endl;
			cin >> game;


		}
		while (game != 'n' && game != 'y'){
		
			cout << "Invalid choice." << endl;
			cout << "Would you like to play again (y/n)?" << endl;
			cin >> game;
		}
		
	}
	return 0;
}