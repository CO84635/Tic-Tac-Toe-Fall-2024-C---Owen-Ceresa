#include <iostream>
#include <sstream>
#include "validator.hpp"
#include "console.hpp"
#include "swarm.hpp"

char Swarm::get_mark()
{
  return this->mark;
}

void Swarm::reset_game() {
    this->board->clear();
}

void Swarm::get_move()
{
  std::string input;
  bool validMove = false;

  while(!validMove){
      std::cout << "What is your move? ";
      std:getline(std::cin, input);

      std::stringstream ss(input);
      int move;
      if (ss >> move && ss.eof()) {
        if (move >= 1 && move <= 9 && Validator::isValidMove(move, *board)) {
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