#pragma once

#include "game_state.hpp"
#include "console.hpp"
#include "human_player.hpp"
#include "player.hpp"
#include "board.hpp"
#include "game_reporter.hpp"


class Game
{
private:
  Console *console;
  GameState *game_state;
  Player *player_one;
  Player *player_two;
  Player *current_player;
  GameStatistics *stats;

public:
  Game(Console *console, GameState *game_state, Player *player_one, Player *player_two, GameStatistics *stats);
  bool start();
};
