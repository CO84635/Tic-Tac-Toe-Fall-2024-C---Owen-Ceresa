#include "game_state.hpp"

GameState::GameState(Board *board)
{
  this->board = board;

  this->winning_combos[0][0] = 1;
  this->winning_combos[0][1] = 2;
  this->winning_combos[0][2] = 3;

  this->winning_combos[1][0] = 4;
  this->winning_combos[1][1] = 5;
  this->winning_combos[1][2] = 6;

  this->winning_combos[2][0] = 1;
  this->winning_combos[2][1] = 4;
  this->winning_combos[2][2] = 7;

  this->winning_combos[3][0] = 7;
  this->winning_combos[3][1] = 8;
  this->winning_combos[3][2] = 9;
}

bool GameState::three_in_a_row(int cell_one, int cell_two, int cell_three)
{
  return board->get_mark(cell_one) == board->get_mark(cell_two) && board->get_mark(cell_two) == board->get_mark(cell_three);
}

std::string GameState::select_winner(int cell)
{
  std::string output = "";
  output += board->get_mark(cell);
  output += " wins";
  return output;
}

std::string GameState::current_state()
{
  for (int i = 0; i < 4; i++)
  {
    if (this->three_in_a_row(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2]))
    {
      return select_winner(winning_combos[i][0]);
    }
  }

  return "in-progress";
}
