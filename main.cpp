#include <iostream>

#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "pyromancer.hpp"
#include "swarm.hpp"
#include "game.hpp"

int main()
{
  Board board;
  Console console(&board);
  Pyromancer player_one(&board, &console, 'X');
  // HumanPlayer player_two(&board, &console, 'O');
  HumanPlayer player_two(&board, &console, 'O');
  Pyromancer current_player = player_one;
  GameState game_state(&board, &current_player);
  Game game(&console, &game_state, &player_one, &player_two);

  game.start();
}
