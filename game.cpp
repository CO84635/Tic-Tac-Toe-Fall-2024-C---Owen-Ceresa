#include <iostream>

#include "game.hpp"

Game::Game(Console *console, GameState *game_state, Player *player_one, Player *player_two)
{
  this->console = console;
  this->game_state = game_state;
  this->player_one = player_one;
  this->player_two = player_two;
  this->current_player = player_one;
}

bool Game::start()
{
  char play_again;
    do
    {
        while (game_state->current_state() == "in-progress")
        {
            std::cout << console->display();
            
            if (game_state->current_state() != "in-progress")
            {
                std::cout << game_state->current_state() << std::endl;
                break;
            }

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
        

        std::string response;
        std::cout << "Do you want to play again? (y/n): ";
        getline(std::cin, response);

        if (response == "y" || response == "y")
        {
            game_state->clearBoard();
            player_one->reset_game();
            player_two->reset_game();
            current_player = player_one;
            return true;
        } else if (response == "n" || response == "N") {
            std::cout << "Thanks for playing!" << std::endl;
            return false;
        } else {
            std::cout << "Invalid response. Please enter 'y' or 'n'." << std::endl;
            continue; 
        }

    } while (true);
}
