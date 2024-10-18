#include <iostream>

#include "game.hpp"

Game::Game(Console *console, GameState *game_state, HumanPlayer *player_one, HumanPlayer *player_two)
{
  this->console = console;
  this->game_state = game_state;
  this->player_one = player_one;
  this->player_two = player_two;
  this->current_player = player_one;
}

void Game::start()
{
  while (game_state->current_state() == "in-progress")
  {
    std::cout << console->display();
    current_player->get_move();
    if (current_player->mark == 'X')
    {
      current_player = player_two;
    }
    else
    {
      current_player = player_one;
    }
  }
}
