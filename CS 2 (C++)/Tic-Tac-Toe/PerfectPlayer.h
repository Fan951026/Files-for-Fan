
#ifndef _PERFECT_PLAYER_
#define _PERFECT_PLAYER_
#include "Player.h"
#include<memory>
#include<vector>
struct Node
{
	Node(Board b) :board(b), winnerFromHere(), children(){}
	Board board;
	Board::Player winnerFromHere;
	std::vector<std::shared_ptr<Node>>children;
};
void PlayFromNode(std::shared_ptr < Node >n, Board::Player turn);
class PerfectPlayer:public Player
{
public:
  PerfectPlayer(Board::Player);
  virtual Board move(Board board);
private:
	std::shared_ptr<Node>plan;
	Node*cur;
};

#endif
