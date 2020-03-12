#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.h"
using namespace std;

class Deck {
private:
    Card card_array[52];

public:
    Deck();
    void generate_deck();
    void shuffle();
    Card card_at(int i);
    void print();
};
#endif