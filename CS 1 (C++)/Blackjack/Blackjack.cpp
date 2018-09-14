#include"Blackjack.h"
#include<string>
#include<vector>
#include<ctime>

void Blackjack::resolveWinner(){

	if (getPlayerScore() > 21){
		status = DEALER_WIN;
		cout << "your busted" << endl;
		cout << "Dealer wins, with " << getDealerScore() << " to your " << getPlayerScore() << endl;
	}
	else if (getDealerScore() > 21){
		status = PLAYER_WIN;
		cout << "Dealer busted" << endl;
		cout << "You win, with " << getPlayerScore() << " to Dealer's " << getDealerScore() << endl;
	}
	else if (getPlayerScore() > getDealerScore()){

		status = PLAYER_WIN;
		cout << "You win, with " << getPlayerScore() << " to Dealer's " << getDealerScore() << endl;
	}
	else{
		status = DEALER_WIN;

		cout << "Dealer wins, with " << getDealerScore() << " to your " << getPlayerScore() << endl;
	}



}
int Blackjack::hit(){
	
	int card = rand() % 13+1;
	card = rand() % 13+1;
	deck[card]--;
	return card;

}
void Blackjack::pass(){
	if (status == DEALER_TURN){
		resolveWinner();
	}
	if (status == PLAYER_TURN){
		status = DEALER_TURN;
	}

	

}

Blackjack::Blackjack(){
	srand(time(NULL));
		
	reset();



}
void Blackjack::reset(){
	for (int i = 0; i < 13; ++i){
		deck[i] = 4;
		

	}
	playerHand.clear();
	dealerHand.clear();
	status = PLAYER_TURN;
	playerHand.push_back(hit());
	playerHand.push_back(hit());
	dealerHand.push_back(hit());
	dealerHand.push_back(hit());
	showHole = false;
	
	
}
Blackjack::Status Blackjack::getStatus(){
	return status;


}
int Blackjack::getPlayerScore(){
	int sum = 0;
	int num = 0;
	for (int i = 0; i < playerHand.size(); ++i){

		if (playerHand.at(i) > 0 && playerHand.at(i) < 9){
			sum += playerHand.at(i) + 1;
		}
		else if (playerHand.at(i) >= 9)
		{
			sum += 10;

		}
		else if (playerHand.at(i) == 0){
			num++;
			sum += 11;
		
		
		}

	}
	while (sum > 21 && num > 0){
		sum -= 10;
		num--;
		}
	return sum;


}
int Blackjack::getDealerScore(){
	int sum = 0;
	int cout = 0;
	for (int i = 0; i < dealerHand.size(); ++i){

		if (dealerHand.at(i) > 0 && dealerHand.at(i) < 9){
			sum += playerHand.at(i) + 1;
		}
		else if (dealerHand.at(i) >= 9)
		{
			sum += 10;

		}
		else if (dealerHand.at(i) == 0){
			cout++;
			sum += 11;


		}
	}
	while (sum > 21 && cout > 0){
		sum -= 10;
		cout--;
	}


	return sum;



}
void Blackjack::displayPlayerHand(){
	cout << "Your hand: ";
	

	for (int i = 0; i < playerHand.size(); ++i)
	{
		if (showHole == false && i == 0 && getPlayerScore() != 21){
			cout << "A" << " ";
		}
		else if (playerHand.at(i) == 0){
			cout << "A" << " ";
		}
		else if (playerHand.at(i) == 10){
			cout << "J" << " ";
		}
		else if (playerHand.at(i) == 11){
			cout << "Q" << " ";
		}
		else if (playerHand.at(i) == 12){
			cout << "k" << " ";
		}
		else{
			cout << playerHand.at(i)+1 << " ";
		}
	}
	cout << endl;
	cout << "You currently have a score of " << getPlayerScore() << endl;
	
}
void Blackjack::displayDealerHand(){
	cout << "Dealer hand: ";
	
	for (int i = 0; i < dealerHand.size(); ++i)
	{
		if (showHole == false && i == 0 && getDealerScore() != 21){
			cout << "A" << " ";
		}
		else if (showHole == false && i == 1 && getDealerScore() != 21){
			i++;
			cout << "H"<< " ";
		}
		else if (dealerHand.at(i) == 0){
			cout << "A" << " ";
		}
		else if (dealerHand.at(i) == 10){
			cout << "J" << " ";
		}
		else if (dealerHand.at(i) == 11){
			cout << "Q" << " ";

		}
		else if (dealerHand.at(i) == 12){
			cout << "k" << " ";
		}
		
		else{
			cout << dealerHand.at(i)+1 << " " << endl;
		}
	}
	cout << endl;
}

	void Blackjack::makeMove(Move move){
		
		if (status == PLAYER_TURN){
			if (move == HIT){
				playerHand.push_back(hit());
				displayPlayerHand();
			}
			else{
				pass();
			}
		}
		if (status == DEALER_TURN){
			if (move = HIT){
				dealerHand.push_back(hit());
				displayDealerHand();
			}
			else{
				pass();
			}
		}
		
		
		/*switch (move){
		case'h':
		case'H':
			hit();
			break;
		case'P':
		case'p':
			pass();
			break;
		default:
			cout << "Invalid input. Please choose h to hit or p to pass." << endl;
			
		}*/
	
	}
void Blackjack::displayInstructions(){
	cout << "Welcome to Blackjack! Click the flashing ad to play for real money. Trust me, it's not a scam at all." << endl;
	cout << "Get 21 points on the player's first two cards (called a blackjack), without a dealer blackjack;" << endl;
	cout << "	Reach a final score higher than the dealer without exceeding 21; " << endl;
	cout << "	or Let the dealer draw additional cards until his or her hand exceeds 21." << endl;
	cout << "The player or players are dealt an initial two-card hand and add together the value of their cards." << endl;
	cout << "	Face cards (kings, queens, and jacks) are counted as ten points." << endl;
	cout << "	A player and the dealer can count their own ace as 1 point or 11 points. " << endl;
	cout << "	All other cards are counted as the numeric value shown on the card." << endl;
	cout << "After receiving their initial two cards, players have the option of getting a hit, or taking an additional card. " << endl;
	cout << "In a given round, the player or the dealer wins by having a score of 21 or by having the highest score that is less than 21. " << endl;
	cout << "Scoring higher than 21 (called busting or going bust) results in a loss." << endl;
	cout << "A player may win by having any final score equal to or less than 21 if the dealer busts. " << endl;
	cout << "If a player holds an ace valued as 11, the hand is called soft, meaning that the player cannot go bust by taking an additional card;" << endl;
	cout << "11 plus the value of any other card will always be less than or equal to 21. Otherwise, the hand is hard." << endl;
	cout << "Dealing cards..." << endl;


}
