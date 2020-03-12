#include "player.h"

/********************************************************************* 
 ** Function: Player() constructor
 ** Description: Initializes cards_in_hand to 0
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: cards_in_hand should equal 0
 *********************************************************************/ 
Player::Player() {
    cards_in_hand = 0;
}

/********************************************************************* 
 ** Function: set_name(std::string)
 ** Description: Sets player name to some string
 ** Parameters: std::string _s_
 ** Pre-Conditions: _s_ must be a valid std::string
 ** Post-Conditions: player name should be set to _s_
 *********************************************************************/ 
void Player::set_name(std::string _s_) {
    name = _s_;
}

/********************************************************************* 
 ** Function: give_card(Card)
 ** Description: Adds card to player's hand
 ** Parameters: Card _c_
 ** Pre-Conditions: _c_ must be a valid card object, cards_in_hand must be less than 52
 ** Post-Conditions: Should add _c_ to player's hand
 *********************************************************************/ 
void Player::give_card(Card _c_) {
    /* DEBUG
    std::cout << "Giving ";
    _c_.print();
    std::cout << " to " << name << std::endl << std::endl;
    */
    hand.add_card(_c_);
    cards_in_hand++;
}

/********************************************************************* 
 ** Function: take_card(int)
 ** Description: Calls hand.take_card_at(int) and returns that card
 ** Parameters: int _i_
 ** Pre-Conditions: _i_ must be less than 53
 ** Post-Conditions: Should return the card at the requested index and have removed it from hand
 *********************************************************************/ 
Card Player::take_card(int _i_) {
    return hand.take_card_at(_i_);
}

/********************************************************************* 
 ** Function: print_player_hand()
 ** Description: Prints all the cards in hand out to the console
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print all the cards out to the console
 *********************************************************************/ 
void Player::print_player_hand() {
    hand.print_hand();
}

/********************************************************************* 
 ** Function: get_card_at(int)
 ** Description: Calls hand.get_card_at(int) and returns that card
 ** Parameters: int _i_
 ** Pre-Conditions: _i_ must be less than 53
 ** Post-Conditions: Should return the card from the desired index
 *********************************************************************/ 
Card Player::get_card_at(int _i_) {
    return hand.get_card_at(_i_);
}

/********************************************************************* 
 ** Function: get_n_cards()
 ** Description: Gets the number of cards in the hand
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return the number of cards in the player hand
 *********************************************************************/ 
int Player::get_n_cards() {
    return hand.get_n_cards();
}

/********************************************************************* 
 ** Function: index_of_card_played()
 ** Description: Prints UI for all cards in player hand and demands the player choose 1 card to play
 ** Parameters: none
 ** Pre-Conditions: hand must have at least 1 card in it
 ** Post-Conditions: Should return number based on user input
 *********************************************************************/ 
int Player::index_of_card_played() {
    std::cout << "Choose a card to play : \n";
    for (int i = 0; i < hand.get_n_cards(); i++) {
        std::cout << "    " << (i+1) << ". ";
        hand.print_at(i);
    }
    return (InputHandler::get_input_between(1,hand.get_n_cards())-1);
}

/********************************************************************* 
 ** Function: index_of_first_valid_card(Card)
 ** Description: Automatically finds a valid card to play onto the pile (FOR CPU USE)
 ** Parameters: Card _card_ (card on top of pile)
 ** Pre-Conditions: _card_ must be the card on top of the game pile
 ** Post-Conditions: Should return the index of a valid card to play, or if there are none return -1
 *********************************************************************/ 
int Player::index_of_first_valid_card(Card _card_) {
    for (int i = hand.get_n_cards()-1; i >= 0; i--) {
        /* DEBUG
        std::cout << "checking index " << i << " for valid card...\n";
        */
        if (hand.get_card_at(i).get_rank() == _card_.get_rank()) {
            std::cout << "I found a valid card\n";
            return i;
        } else if (hand.get_card_at(i).get_suit() == _card_.get_suit()) {
            std::cout << "I found a valid card\n";
            return i;
        } else if (hand.get_card_at(i).get_rank() == 7) {
            std::cout << "I found an eight...\n";
            return i;
        }
    }
    return -1;
}