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
  int move;
  bool validMove = false;
   while(!validMove){

  std::cout << "What is your move? ";

  if (!(std::cin >> move)) {
            std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; 
        }

        if (this->board->isValidMove(move)) {
            this->board->move(move, this->mark);
            validMove = true; 
        } else {
            std::cout << "Invalid move. Please try again." << std::endl;
        }
 }
}
