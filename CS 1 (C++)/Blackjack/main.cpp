#include<iostream>
#include<string>
#include"Blackjack.h"
using namespace std;

int main(){
	Blackjack B;

	char choice='q';
	char move;

	while (choice != 'n'){
			B.reset();
			B.displayInstructions();
			B.displayPlayerHand();
			B.displayDealerHand();
			
			cout << "Dealer currently has a score of " << B.getDealerScore() << endl;
			while (B.getStatus() == Blackjack::PLAYER_TURN){
				cout << "Enter move : ";
				cin >> move;
				if (move == 'h'){
					B.makeMove(Blackjack::HIT);

				}
				else if (move == 'p'){
					B.makeMove(Blackjack::PASS);

				}
				else{
					cout << "Invalid choice! Pleace choice h(hit) or p(pass)." << endl;

				}
			}
			while (B.getStatus() == Blackjack::DEALER_TURN){
				if (B.getDealerScore() < 15){
					cout << "Dealer hit" << endl;

					B.makeMove(Blackjack::HIT);
				}
				else {

					cout << "Dealer pass" << endl;
					B.makeMove(Blackjack::PASS);
				}


			}
			
				cout << "would you like to play again(y/n)? " << endl;
				cin >> choice;
				

				if (choice == 'y'){
					B.reset();
				}
				else if (choice == 'n'){
					cout << "Thank for playing!" << endl;
				}
				else{
					cout << "Invalid choice!" << endl;
					cout << "would you like to play again(y/n)? " << endl;
					cin >> choice;

				}
			
		
		

	}

	return 0;
}
	








