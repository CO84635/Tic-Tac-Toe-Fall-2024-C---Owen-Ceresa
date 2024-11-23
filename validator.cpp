#include "validator.hpp"
#include <cctype>

bool Validator::isValidMove(int i, const Board& board)
{
    char at_move = board.get_move(i - 1);
    return (i > 0 && i < 10 && isdigit(at_move));
}