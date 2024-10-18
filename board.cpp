#include "board.hpp"

void Board::clear()
{
  this->moves[0] = '1';
  this->moves[1] = '2';
  this->moves[2] = '3';
  this->moves[3] = '4';
  this->moves[4] = '5';
  this->moves[5] = '6';
  this->moves[6] = '7';
  this->moves[7] = '8';
  this->moves[8] = '9';
}

void Board::move(int i, char m)
{
  if (i > 0 && i < 10)
  {
    this->moves[i - 1] = m;
  }
}

char Board::get_mark(int i)
{
  return this->moves.at(i - 1);
}
