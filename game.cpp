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
  char play_again;
    do
    {
        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

        while (game_state->current_state() == "in-progress")
        {
            std::cout << console->display();

            if (current_player == player_one){
              std::cout << "Player One:" << std::endl;
            } else {
              std::cout << "Player Two:" << std::endl;
            }
           
            current_player->get_move();

            if (game_state->current_state() != "in-progress")
            {
                std::cout << game_state->current_state() << std::endl;
                break;
            }

            current_player = (current_player == player_one) ? player_two : player_one;
        }
        std::cout << "Final Game State: " << std::endl;
        std::cout << console->display();

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> play_again;

        HumanPlayer::reset_input();

        if (play_again == 'y' || play_again == 'Y')
        {
            game_state->clearBoard();
            current_player = player_one;
        }

    } while (play_again == 'y' || play_again == 'Y');
}
