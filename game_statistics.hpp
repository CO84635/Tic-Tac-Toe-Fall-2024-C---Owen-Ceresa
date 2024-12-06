#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

class GameStatistics {
private:
    int games_played_count;
    int player_one_win_count;
    int player_two_win_count;
    int ties_count;

public:
    GameStatistics() {
        this->games_played_count = 0;
        this->player_one_win_count = 0;
        this->player_two_win_count = 0;
        this->ties_count = 0;
    }

    void increment_player_one_wins() { ++player_one_win_count; ++games_played_count;}

    void increment_player_two_wins() { ++player_two_win_count; ++games_played_count;}
        
    void increment_ties() { ++ties_count; ++games_played_count;}

    int get_player_one_wins() { return player_one_win_count; }

    int get_player_two_wins() { return player_two_win_count; }

    int get_tie_count() { return ties_count; }

    int get_games_played_count() { return games_played_count; }
};

#endif // GAMESTATISTICS_H