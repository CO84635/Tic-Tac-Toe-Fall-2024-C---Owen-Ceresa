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

public:
  char mark;

  HumanPlayer(Board *board, Console *console, char mark);
  void get_move() override;
  static void reset_input();
};
