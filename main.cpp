#include <iostream>

#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "game.hpp"

int main()
{
  Board board;
  GameState game_state(&board);
  Console console(&board);
  HumanPlayer player_one(&board, 'X');
  HumanPlayer player_two(&board, 'O');
  HumanPlayer current_player = player_one;
  Game game(&console, &game_state, &player_one, &player_two);

  game.start();
}
