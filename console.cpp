#include "board.hpp"
#include "console.hpp"

Console::Console(Board *board)
{
  this->board = board;
}

std::string Console::display()
{
  std::string output = "";
  output += padding;
  output += board->get_mark(1);
  output += vertical_separator;
  output += board->get_mark(2);
  output += vertical_separator;
  output += board->get_mark(3);
  output += horizontal_separator;
  output += board->get_mark(4);
  output += vertical_separator;
  output += board->get_mark(5);
  output += vertical_separator;
  output += board->get_mark(6);
  output += horizontal_separator;
  output += board->get_mark(7);
  output += vertical_separator;
  output += board->get_mark(8);
  output += vertical_separator;
  output += board->get_mark(9);
  output += padding;
  output += "\n";
  return output;
}
