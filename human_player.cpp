#include <iostream>
#include <limits>

#include "human_player.hpp"

HumanPlayer::HumanPlayer(Board *board, char mark)
{
  this->board = board;
  this->mark = mark;
}

void HumanPlayer::get_move()
{
  while(true){
  int move;
  std::cout << "What is your move? ";
  std::cin >> move;

  if (std::cin.fail() || std::cin.peek() != '\n'){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a whole number between 1 and 9." << std::endl;
    continue;
  }

  if (this->board->isValidMove(move)) {
    this->board->move(move, this->mark);
    break;
  } else {
    std::cout << "That is an invalid move!" << std::endl;
  }
  }
}
