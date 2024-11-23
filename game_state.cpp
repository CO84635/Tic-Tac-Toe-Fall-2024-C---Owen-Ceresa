#include "game_state.hpp"

GameState::GameState(Board *board, Player *current_player)
{
    this->board = board;
    this->current_player = current_player;
}

bool GameState::three_in_a_row(int cell_one, int cell_two, int cell_three)
{
    return board->get_mark(cell_one) == board->get_mark(cell_two) && board->get_mark(cell_two) == board->get_mark(cell_three) && board->get_mark(cell_one) != ' ';
}

void GameState::clearBoard(){
    board->clear();
}

std::string GameState::select_winner(int cell)
{
    std::string output = "";
    output += board->get_mark(cell);
    output += " wins";
    return output;
}

bool GameState::is_full()
{
    for (int cell = 1; cell <= 9; cell++)
    {
        if (isdigit(board->get_mark(cell))) {
            return false;
        }
    }
    return true;
}

std::string GameState::current_state()
{
    if (current_player->get_is_swarm()) {

        char mark1 = board->get_mark(1);
        char mark3 = board->get_mark(3);
        char mark7 = board->get_mark(7);
        char mark9 = board->get_mark(9);

        if (mark1 == mark3 && mark1 == mark7 && mark1 == mark9 
            && mark1 != '1' && mark1 != '2' && mark1 != '3' 
            && mark1 != '4' && mark1 != '5' && mark1 != '6' 
            && mark1 != '7' && mark1 != '8' && mark1 != '9') {
                
            return select_winner(1);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (this->three_in_a_row(i * 3 + 1, i * 3 + 2, i * 3 + 3))
        {
            return select_winner(i * 3 + 1);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (this->three_in_a_row(i + 1, i + 4, i + 7))
        {
            return select_winner(i + 1);
        }
    }

    if (this->three_in_a_row(1, 5, 9))
    {
        return select_winner(1);
    }
    if (this->three_in_a_row(3, 5, 7))
    {
        return select_winner(3);
    }

    if(is_full()) {
        return "Game ended in a draw!";
    }

    return "in-progress";
}
