#pragma once
#include <limits>
#include <iostream>
#include "board.hpp"

class Player{
private:
    bool is_swarm = false;

public:
    virtual ~Player() = default;

    virtual void get_move() = 0;
    virtual char get_mark() = 0;
    virtual void reset_game() = 0;

    void reset_input(){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool get_is_swarm() {
        return is_swarm;
    }

    void set_the_swarm(bool swarm_state) {
        this->is_swarm = swarm_state;
    }
};