#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
    private:
        int suit;   // Should be in the range 0-3.
        int rank;   // Should be in the range 0-12.
    public:
        /* Constructors */
        Card();
        Card(int suit, int rank);

        /* Destructors */
        ~Card();

        /* Mutators */
        void set_suit(int s);
        void set_rank(int r);

        /* Accessors */
        int get_suit();
        int get_rank();
        void print();
};
#endif
