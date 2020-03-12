#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "input_handler.h"

class Player {
    private:
        Hand hand = Hand(52, 0);
        int cards_in_hand;
        std::string name;
    public:
    /* Constructors */
    Player();
    
    /* Destructors */

    /* Mutators */
    void set_name(std::string);
    void give_card(Card);
    Card take_card(int);

    /* Accessors */
    Card get_card_at(int);
    void print_player_hand();
    int get_n_cards();
    int index_of_card_played();
    int index_of_first_valid_card(Card);
};
#endif