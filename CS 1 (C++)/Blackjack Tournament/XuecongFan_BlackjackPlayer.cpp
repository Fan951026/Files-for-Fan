#include "XuecongFan_BlackjackPlayer.h"
#include "Card.h"
#include "Hand.h"

XuecongFan_BlackjackPlayer::XuecongFan_BlackjackPlayer() {






}

/**
 * This function is called when it's your turn and you need to
 * choose whether to hit (return true) or stand (return false).
 *
 * The hand parameter tells you what's in your hand. You can call
 * getSuit(), getRank(), getLowValue(), and getHighValue() on each of
 * the cards it contains.
 *
 * The dealerUpCard parameter works the same way, and tells you what the
 * dealer up card is.
 *
 * You must return a value from this function indicating whether you want
 * to hit or stand. Return true if you want to hit and false if you want to stand.
 */
bool XuecongFan_BlackjackPlayer::hit(vector<Card> hand, Card dealerUpCard) {
	// Currently, the player will hit everytime they are asked.
	
	int score = 0;
	for (int i = 0; i < hand.size(); ++i){
		score += hand[i].getHighValue ();
		
	}
	if (score < 15){
		return true;
	}
	else {
		return false;
	}
	

	
	
}

/**
 * This function is called when it's your turn and you need to
 * choose to double down or not. If you choose to double down, you
 * will double your initial bet and receive one more card, then your
 * turn is over. Typically you would only double down if you think you
 * have a really good chance of beating the dealer base on your own hand
 * and the dealer's visible card.
 *
 * The hand parameter tells you what's in your hand. You can call
 * getSuit(), getRank(), getLowValue(), and getHighValue() on each of
 * the cards it contains.
 *
 * The dealerUpCard parameter works the same way, and tells you what the
 * dealer up card is.
 *
 * You must return a value from this function indicating whether you want
 * to double down or not. Return true if you want to double down and false
 * if you do not.
 */
bool XuecongFan_BlackjackPlayer::doubleDown(vector<Card> hand, Card dealerUpCard) {
	// Currently, this player will never double down.

	int scores = 0;
	for (int i = 0; i < hand.size(); ++i){
		scores += hand[i].getRank();

	}
	if (scores = 21){
		return true;
	}
	else {
		return false;
	}


	return false;
}

/**
 * This function is called to determine what your initial bet will be.
 * The function must return an integer between the values of 10 and 100.
 * The lowest bet you can make is 10 and the highest is 100. If you are
 * thinking of cheating and entering a number that is not in that range,
 * know that the game code checks to make sure a valid value is returned
 * and if it is not, your initialBet will default to 10.
 */
int XuecongFan_BlackjackPlayer::initialBet() {
	// Currently, this player will always return an initial bet of 10
	return 11;
}