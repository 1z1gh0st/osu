/******************************************************
** Program: wumpus.cpp
** Author: Philip Warton
** Date: 02/28/2020
** Description:  Hunt the wumpus game
** Input: cmd line args
** Output: game
******************************************************/

#include "header.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    InputHandler h = InputHandler(argc, argv);
    Board game_board = Board(h.get_size(), h.is_debug());
    game_board.print_board();
    while (1) {
        game_board.print_board();
        game_board.turn();
        if (game_board.get_player().is_dead()) {
            break;
        }
    }
    return 0;
}