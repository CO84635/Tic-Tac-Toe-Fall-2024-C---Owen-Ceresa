#ifndef PYROMANCER_H
#define PYROMANCER_H

#include <string>

#include "board.hpp"
#include "player.hpp"
#include "console.hpp"

class Pyromancer : public Player
{
private:
    Board *board;
    char mark;
    Console *console;
    bool BoardExploded = false;

public:
    Pyromancer(Board *board, Console *console, char mark);
    void get_move() override;
    char get_mark() override;
    void reset_game() override;
};

#endif // PYROMANCER_H