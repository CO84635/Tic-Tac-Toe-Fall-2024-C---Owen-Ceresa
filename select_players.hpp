#ifndef SELECT_PLAYERS_HPP
#define SELECT_PLAYERS_HPP

#include "board.hpp"
#include "console.hpp"
#include "human_player.hpp"
#include "pyromancer.hpp"
#include "swarm.hpp"

class SelectPlayers {
public:
    static void selectPlayers(Board &board, Console &console, Player*& player_one, Player*& player_two, const std::string &game_mode_option);
};

#endif // SELECT_PLAYERS_HPP
