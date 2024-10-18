#include <iostream>
#include <cassert>

#include "board.hpp"

using namespace std;

int main()
{
  Board board;

  board.move(1, 'X');

  assert(board.get_mark(1) == 'X');

  board.move(2, 'O');

  assert(board.get_mark(2) == 'O');

  board.move(9, 'W');

  assert(board.get_mark(9) == 'W');

  board.clear();

  assert(board.get_mark(1) == '1');
  assert(board.get_mark(2) == '2');
  assert(board.get_mark(9) == '9');

  cout << "All of the tests have passed!" << endl;
  return 0;
}
