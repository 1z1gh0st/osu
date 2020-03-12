#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "input_handler.h"

class Game {
    private:
        Deck cards;
        Player players[2];
        void player_turn(Hand &);
        void computer_turn(Hand &);
        bool check_win_conditions();
    public:
    /* Constructors */
    Game();

    /* Mutators */
    void create_players();
    void create_deck();

    /* Accessors */
    void play();

};
#endif