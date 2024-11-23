#include <iostream>
#include <sstream>
#include "pyromancer.hpp"
#include "validator.hpp"
#include "console.hpp"

Pyromancer::Pyromancer(Board *board, Console *console, char mark)
{
  this->board = board;
  this->mark = mark;
  this->console = console;
  this->BoardExploded = false;
}

char Pyromancer::get_mark()
{
  return this->mark;
}

void Pyromancer::reset_game() {
    this->board->clear();
    this->BoardExploded = false;
}

void Pyromancer::get_move()
{   
    std::string input;
    bool validMove = false;

    while(!validMove){
        std::cout << "Do you want to (1) enter a cell or (2) explode the board?" << std::endl;
        std:getline(std::cin, input);

        if (input == "1" ){ 
            std::cout << "What is your move? ";
            std::getline(std::cin, input);

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
                std::cout << this->console->display() << std::endl;
            }
        } else if (input == "2") {
            if (!BoardExploded) {
                std::cout << "Exploding the board!" << std::endl;
                this->board->clear();
                BoardExploded = true;
                validMove = true;
            } else {
                std::cout << "Cannot explode the board! You may only use it once per game!" << std::endl;
            }
        } else {
            std::cout << "Invalid option. Please enter either 1 or 2." << std::endl;
        }
    } 
}