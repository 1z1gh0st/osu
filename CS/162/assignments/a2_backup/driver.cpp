/******************************************************
** Program: Crazy Eights
** Author: Philip Warton
** Date: 02/01/2020
** Description: Plays game of crazy eights with one human player and one cpu player
** Input: Card in hand to be played and the suit of eight when eight is played
** Output: Top card on pile, hand of player, and winner of game
******************************************************/

#include "deck.h"
#include "card.h"
#include "player.h"
#include "hand.h"
#include "game.h"
#include <iostream>

int main() {
    while (1) {
        Game game = Game();
        game.play();
        bool repeat = false;
        if (!repeat) {
            break;
        }
    }
    /* TESTING: BIG THREE
    while (1) {
        Card ace;
        ace.set_rank(0);
        ace.set_suit(0);

        Card king;
        king.set_rank(13);
        king.set_suit(3);

        Card jack;
        jack.set_rank(10);
        jack.set_suit(1);

        Hand h1 = Hand(52, 0);
        Hand h2 = h1;
        Hand h3 = Hand(52, 0);
        h3 = h1;

        h1.add_card(ace);
        h2.add_card(king);
        h3.add_card(jack);

        h1.print_hand();
        h2.print_hand();
        h3.print_hand();

        break;
    }*/
    return 0;
}
