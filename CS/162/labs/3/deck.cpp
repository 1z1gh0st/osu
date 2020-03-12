#include <iostream>
#include "deck.h"
#include "card.h"
#include <cstdlib>

using namespace std;

void Deck::generate_deck() {
    int index = 0;
    while (index < 52) {
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 0; rank < 13; rank++) {
                card_array[index].set_suit(suit);
                card_array[index].set_rank(rank);
                index++;
            }
        }
    }
}

void Deck::shuffle() {
    
    srand(time(NULL));

    /* swap cards 100 times to shuffle */
    for (int s = 0; s < 100; s++) {

        /* pick two random indecies */
        int a = rand() % 52;
        int b = rand() % 52;

        /* swap said indecies */
        Card swap = card_array[a];
        card_array[a] = card_array[b];
        card_array[b] = swap;
    }
}

Card Deck::card_at(int i) {
    return card_array[i];
}

void Deck::print() {
    for (int i = 0; i < 52; i++) {
        card_at(i).print();
        cout << "i: " << i << endl;
    }
}