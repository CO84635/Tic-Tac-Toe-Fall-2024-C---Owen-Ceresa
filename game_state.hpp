#pragma once

#include <string>

#include "board.hpp"

class GameState
{
private:
  Board *board;
  bool three_in_a_row(int cell_one, int cell_two, int cell_three);
  std::string select_winner(int cell);
  int winning_combos[4][3];
  bool is_full();

public:
  void clearBoard();
  GameState(Board *board);
  std::string current_state();
};
