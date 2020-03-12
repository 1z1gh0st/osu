#include "deck.h"
#include "card.h"
#include <iostream>

using namespace std;

int main() {
    Deck my_deck;
    my_deck.generate_deck();
    my_deck.shuffle();
    my_deck.print();
    return 0;
}
