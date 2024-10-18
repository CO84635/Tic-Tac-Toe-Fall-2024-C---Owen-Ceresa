#include <iostream>

#include "human_player.hpp"

HumanPlayer::HumanPlayer(Board *board, char mark)
{
  this->board = board;
  this->mark = mark;
}

void HumanPlayer::get_move()
{
  // We need to validate this move!
  // Oops! Shall We Try Again lab
  int move;
  std::cout << "What is your move? ";
  std::cin >> move;
  this->board->move(move, this->mark);
}
