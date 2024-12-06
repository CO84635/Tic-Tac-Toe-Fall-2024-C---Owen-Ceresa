#include <iostream>
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "pyromancer.hpp"
#include "swarm.hpp"
#include "game.hpp"
#include "select_players.hpp"
#include "game_statistics.hpp"
#include "game_reporter.hpp"

int main() {
    Board board;
    Console console(&board);
    GameStatistics stats;
    GameReport reporter;
    bool game_over = false;
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    while (!game_over) {
        std::string game_mode_option;

        std::cout << "Which mode of TTT would you like to play? (1) Regular (2) Battle TTT: " << std::endl;
        std::getline(std::cin, game_mode_option);

        Player *player_one = nullptr;
        Player *player_two = nullptr;

        if (game_mode_option == "1" || game_mode_option == "2") {
            SelectPlayers::selectPlayers(board, console, player_one, player_two, game_mode_option);

            GameState game_state(&board, &*player_one);
            Game game(&console, &game_state, &*player_one, &*player_two, &stats);

            game_over = !game.start();
            
            delete player_one;
            delete player_two;
        } else {
            std::cout << "Invalid response. Please enter '1' or '2'." << std::endl;
        }
    }

    reporter.generateReport(stats);

    return 0;
}