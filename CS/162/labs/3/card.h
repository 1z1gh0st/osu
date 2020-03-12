#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
private:
    int suit;
    int rank;

public:
    void set_suit(int s);
    void set_rank(int r);
    int get_suit();
    int get_rank();
    void print();
};
#endif
