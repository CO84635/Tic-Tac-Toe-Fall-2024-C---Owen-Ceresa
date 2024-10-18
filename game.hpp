#pragma once

#include "game_state.hpp"
#include "console.hpp"
#include "human_player.hpp"

class Game
{
private:
  Console *console;
  GameState *game_state;
  HumanPlayer *player_one;
  HumanPlayer *player_two;
  HumanPlayer *current_player;

public:
  Game(Console *console, GameState *game_state, HumanPlayer *player_one, HumanPlayer *player_two);
  void start();
};
