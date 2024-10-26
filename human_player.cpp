#include <iostream>
#include <limits>
#include <sstream>
#include "human_player.hpp"
#include "console.hpp"

HumanPlayer::HumanPlayer(Board *board, Console *console, char mark)
{
  this->board = board;
  this->console = console;
  this->mark = mark;
}

void HumanPlayer::get_move()
{
  std::string input;
  bool validMove = false;

  while(!validMove){
      std::cout << "What is your move? ";
      std:getline(std::cin, input);

      std::stringstream ss(input);
      int move;

      if (ss >> move && ss.eof()) {
      // if (!(std::cin >> move)) {
      //       std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
      //       std::cin.clear(); 
      //       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      //       continue; 
      //   }

        if (this->board->isValidMove(move)) {
            this->board->move(move, this->mark);
            validMove = true; 
        } else {
            std::cout << "Invalid move. Please try again." << std::endl;
            std::cout << console->display() << std::endl;
        }
      } else {
        std::cout << "Invalid input. Please enter a whole number between 1 and 9." << std::endl;
        std::cout << console->display() << std::endl;
      }
    }
}

void HumanPlayer::reset_input(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
