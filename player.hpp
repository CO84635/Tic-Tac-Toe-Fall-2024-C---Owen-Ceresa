#pragma once

#include "board.hpp"

class Player{
public:
    virtual ~Player() = default;
    virtual void get_move() = 0;
};