#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"

class GameState
{
private:
  Board *board;
  Player *current_player;
  bool three_in_a_row(int cell_one, int cell_two, int cell_three);
  std::string select_winner(int cell);
  int winning_combos[4][3];
  bool is_full();
  

public:
  void clearBoard();
  GameState(Board *board, Player *current_player);
  std::string current_state();
};
