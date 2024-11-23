#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"
#include "console.hpp"

class Swarm : public Player
{
private:
  Board *board;
  char mark;
  Console *console;

public:
    void reset_game() override;
    Swarm(Board *board, Console *console, char mark){
        this->board = board;
        this->mark = mark;
        this->console = console;
        set_the_swarm(true);
    };

  void get_move() override;
  char get_mark() override;
};