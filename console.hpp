#pragma once

#include <string>

#include "board.hpp"

class Console
{
private:
  Board *board;
  std::string vertical_separator = " / ";
  std::string horizontal_separator = " \n~~~~~~~~~~~\n ";
  std::string padding = " ";

public:
  Console(Board *board);
  std::string display();
};
