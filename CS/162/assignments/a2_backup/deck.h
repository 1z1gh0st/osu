#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <iostream>

#include "card.h"

class Deck {
    private:
        Card cards[52];
        int n_cards = 52;    // Number of cards remaining in the deck.

    public:
        /* Constructors */
        Deck();

        /* Destructors */
        ~Deck();

        /* Mutators */
        void generate_deck();
        void shuffle();

        /* Accessors */
        Card card_at(int i);
        Card take_card();
        void print();
        int get_n_cards();
};
#endif