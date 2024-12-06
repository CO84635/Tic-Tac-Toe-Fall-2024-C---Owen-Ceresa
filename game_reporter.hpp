#ifndef GAMEREPORTER_H
#define GAMEREPORTER_H

#include "game_statistics.hpp"
#include <fstream>
#include <iostream>

class GameReport {
public:
    void generateReport(GameStatistics &stats) {
        std::ofstream output_file("game_report.txt");
    
        if (output_file.is_open()) {
            output_file << "Tic-Tac-Toe Game Report\n";
            output_file << "Total Games Played: " << stats.get_games_played_count() << "\n";
            output_file << "Player One Wins: " << stats.get_player_one_wins() << "\n";
            output_file << "Player Two Wins:  " << stats.get_player_two_wins() << "\n";
            output_file << "Ties: " << stats.get_tie_count();

            output_file.close();
        } else {
            std::cerr << "Could not generate a Game Report!\n";
        }
    }
};

#endif // GAMEREPORTER_H