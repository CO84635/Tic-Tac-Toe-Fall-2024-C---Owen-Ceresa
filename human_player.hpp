#pragma once

#include <string>
#include "console.hpp"
#include "board.hpp"
#include "player.hpp"

class HumanPlayer : public Player 
{
private:
  Board *board;
  Console *console;
  char mark;

public:
  HumanPlayer(Board *board, Console *console, char mark);
  char get_mark() override;
  void get_move() override;
  void reset_game() override;
};
