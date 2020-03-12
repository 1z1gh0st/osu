#ifndef HAND_H
#define HAND_H

#include <iostream>

#include "card.h"

class Hand {
    private:
        Card* cards;
        int n_cards;    // Number of cards in the hand.
    public:
        /* Constructors */
        Hand(int, int);

        /* Big Three */
        ~Hand();
        Hand(const Hand &);
        Hand& operator= (const Hand&);

        /* Mutators */
        void add_card(Card);
        Card take_card_at(int);
        bool check_card_match(Card);

        /* Accessors */
        Card get_card_at(int);
        void print_hand();
        void print_top();
        void print_at(int);
        int get_n_cards();
};
#endif