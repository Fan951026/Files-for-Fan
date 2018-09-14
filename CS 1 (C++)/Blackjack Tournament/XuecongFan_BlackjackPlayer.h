#ifndef STUDENTNAME_BLACKJACKPLAYER_H
#define STUDENTNAME_BLACKJACKPLAYER_H
#include "BlackjackPlayer.h"

/**
 * A class derived from the abstract class BlackjackPlayer. This class implements
 * a strategy for competing in an Blackjack tournament. It consists of three functions
 * which the simulator calls for each player: hit(), which chooses whether to hit
 * (be dealt another card) or not (to stand), doubleDown() which chooses if
 * a player wants to double their bet and take one more card or not, and
 * initialBet() which provides the initial bet value.
 */
class XuecongFan_BlackjackPlayer: public BlackjackPlayer {
	
public:
	XuecongFan_BlackjackPlayer();   // default constructor
	
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
	bool hit(vector<Card> hand, Card dealerUpCard);
	
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
	bool doubleDown(vector<Card> hand, Card dealerUpCard);
	
	/**
	 * This function is called to determine what your initial bet will be.
	 * The function must return an integer between the values of 10 and 100.
	 * The lowest bet you can make is 10 and the highest is 100. If you are
	 * thinking of cheating and entering a number that is not in that range,
	 * know that the game code checks to make sure a valid value is returned
	 * and if it is not, your initialBet will default to 10.
	 */
	int initialBet();
};
#endif
