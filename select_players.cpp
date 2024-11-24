#include "select_players.hpp"
#include <iostream>

void SelectPlayers::selectPlayers(Board &board, Console &console, Player*& player_one, Player*& player_two, const std::string &game_mode_option) {
    std::string pyromancer_description = "The Pyromancer can reset the board once per game, clearing all marks and starting fresh.";
    std::string swarm_description = "The Swarm can win by filling all four corners of the board.";

    if (game_mode_option == "1") {
        player_one = new HumanPlayer(&board, &console, 'X');
        player_two = new HumanPlayer(&board, &console, 'O');
    } else if (game_mode_option == "2") {
        std::string player_one_type, player_two_type;

        while (true) {
            std::cout << "Select Player One type: \n(1) Regular \n(2) Pyromancer - " << pyromancer_description << "\n(3) Swarm - " << swarm_description << std::endl;
            std::getline(std::cin, player_one_type);
            if (player_one_type == "1") {
                player_one = new HumanPlayer(&board, &console, 'X');
                break;
            } else if (player_one_type == "2") {
                player_one = new Pyromancer(&board, &console, 'X');
                break;
            } else if (player_one_type == "3") {
                player_one = new Swarm(&board, &console, 'X');
                break;
            } else {
                std::cout << "Invalid choice for Player One. Please choose '1', '2', or '3'." << std::endl;
            }
        }

        while (true) {
            std::cout << "Select Player Two type: \n(1) Regular \n(2) Pyromancer - " << pyromancer_description << "\n(3) Swarm - " << swarm_description << std::endl;
            std::getline(std::cin, player_two_type);
            if (player_two_type == "1") {
                player_two = new HumanPlayer(&board, &console, 'O');
                break;
            } else if (player_two_type == "2") {
                player_two = new Pyromancer(&board, &console, 'O');
                break;
            } else if (player_two_type == "3") {
                player_two = new Swarm(&board, &console, 'O');
                break;
            } else {
                std::cout << "Invalid choice for Player Two. Please choose '1', '2', or '3'." << std::endl;
            }
        }
    }
}
