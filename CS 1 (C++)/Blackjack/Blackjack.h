#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Blackjack
{
public:
	enum Status { PLAYER_TURN, DEALER_TURN, PLAYER_WIN, DEALER_WIN };
	enum Move { HIT, PASS };
	Blackjack();
	void reset();
	Status getStatus();
	int getPlayerScore();
	void displayPlayerHand();
	int getDealerScore();
	void displayDealerHand();
	void makeMove(Move move);
	void displayInstructions();


private:
	void resolveWinner();
	 int hit();
	 void pass();
	 Status status;
	 int deck[13];
	 bool showHole;
	 std::vector < int >playerHand;
	 std::vector < int > dealerHand;

};
