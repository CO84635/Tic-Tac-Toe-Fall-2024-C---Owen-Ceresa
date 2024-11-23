#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "board.hpp"

class Validator
{
public:
    static bool isValidMove(int i, const Board& board);
};
#endif // VALIDATOR_H