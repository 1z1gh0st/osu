#include <iostream>
#include "card.h"

using namespace std;

void Card::set_suit(int s) {
    suit = s;
}

void Card::set_rank(int r) {
    rank = r;
}

int Card::get_suit() {
    return suit;
}

int Card::get_rank() {
    return rank;
}

void Card::print() {
    if (rank == 0) {
        cout << "Ace";
    }
    else if (rank < 10) {
        cout << (rank + 1);
    }
    else if (rank == 10) {
        cout << "Jack";
    }
    else if (rank == 11) {
        cout << "Queen";
    }
    else {
        cout << "King";
    }
    cout << " ";
    if (suit == 0) {
        cout << "of clubs";
    }
    else if (suit == 1) {
        cout << "of diamonds";
    }
    else if (suit == 2) {
        cout << "of hearts";
    }
    else {
        cout << "of spades";
    }
    cout << endl;
}