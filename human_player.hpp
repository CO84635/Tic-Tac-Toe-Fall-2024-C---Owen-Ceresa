#pragma once

#include <string>
#include "console.hpp"
#include "board.hpp"

class HumanPlayer
{
private:
  Board *board;
  Console *console;

public:
  char mark;
  HumanPlayer(Board *board, Console *console, char mark);
  void get_move();
  static void reset_input();
};
