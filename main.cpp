#include <iostream>
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "pyromancer.hpp"
#include "swarm.hpp"
#include "game.hpp"

int main() {
    // Board board;
    // Console console(&board);
    // Pyromancer player_one(&board, &console, 'X');
    // HumanPlayer player_two(&board, &console, 'O');
    // Pyromancer current_player = player_one;
    // GameState game_state(&board, &current_player);
    // Game game(&console, &game_state, &player_one, &player_two);

    
    Board board;
    Console console(&board);
    bool game_over = false;

    while (!game_over) {
        std::string game_mode_option;
        std::cout << "Welcome to Tic Tac Toe!" << std::endl;
        std::cout << "Which mode of TTT would you like to play? (1) Regular (2) Battle TTT: " << std::endl;
        std::getline(std::cin, game_mode_option);

        Player *player_one = nullptr;
        Player *player_two = nullptr;

        if (game_mode_option == "1") {
            player_one = new HumanPlayer(&board, &console, 'X');
            player_two = new HumanPlayer(&board, &console, 'O');
        }


        std::string pyromancer_description = "The Pyromancer can reset the board once per game, clearing all marks and starting fresh.";
        std::string swarm_description = "The Swarm can win by filling all four corners of the board.";
        
        if (game_mode_option == "2") {
            std::string player_one_type;
            std::cout << "Select Player One type: \n(1) Regular \n" << "(2) Pyromancer - " << pyromancer_description << "\n(3) Swarm - " << swarm_description << std::endl;
            std::getline(std::cin, player_one_type);
            if (player_one_type == "2") {
                player_one = new Pyromancer(&board, &console, 'X');
            } else if (player_one_type == "3") {
                player_one = new Swarm(&board, &console, 'X');
            }

            std::string player_two_type;
            std::cout << "Select Player Two type: \n(1) Regular \n" << "(2) Pyromancer - " << pyromancer_description << "\n(3) Swarm - " << swarm_description << std::endl;
            std::getline(std::cin, player_two_type);
            if (player_two_type == "2") {
                player_two = new Pyromancer(&board, &console, 'O');
            } else if (player_two_type == "3") {
                player_two = new Swarm(&board, &console, 'O');
            }
        }

        GameState game_state(&board, &*player_one);
        Game game(&console, &game_state, &*player_one, &*player_two);

        game_over = !game.start();

        delete player_one;
        delete player_two;
    }

    return 0;
}
