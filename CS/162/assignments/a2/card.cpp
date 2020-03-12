#include "card.h"

/********************************************************************* 
 ** Function: Card() 
 ** Description: Constructor for Card object
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should create Card object
 *********************************************************************/ 
Card::Card() {

}

/********************************************************************* 
 ** Function: Card(int, int) 
 ** Description: Custom constructor for Card object that initializes suit and rank
 ** Parameters: int _suit_, int _rank_
 ** Pre-Conditions: _suit_ should be between 0 and 3, and _rank_ should be between 0 and 13
 ** Post-Conditions: Should create Card object with desired suit and rank
 *********************************************************************/ 
Card::Card(int _suit_, int _rank_) {
    set_suit(_suit_);
    set_rank(_rank_);
}

/********************************************************************* 
 ** Function: ~Card()
 ** Description: Destructor for Card object
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should free memory allocated for Card object
 *********************************************************************/ 
Card::~Card() {

}

/********************************************************************* 
 ** Function: set_suit()
 ** Description: Setter for the suit member
 ** Parameters: int s
 ** Pre-Conditions: s should be between 0 and 3
 ** Post-Conditions: Should set Card.suit to s
 *********************************************************************/ 
void Card::set_suit(int s) {
    suit = s;
}

/********************************************************************* 
 ** Function: set_rank()
 ** Description: Setter for the rank member
 ** Parameters: int r
 ** Pre-Conditions: r should be between 0 and 13
 ** Post-Conditions: Should set Card.rank to r
 *********************************************************************/ 
void Card::set_rank(int r) {
    rank = r;
}

/********************************************************************* 
 ** Function: get_suit()
 ** Description: Getter for the suit member
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return the member suit of Card object
 *********************************************************************/ 
int Card::get_suit() {
    return suit;
}

/********************************************************************* 
 ** Function: get_rank()
 ** Description: Getter for the rank member
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return the member rank of Card object
 *********************************************************************/ 
int Card::get_rank() {
    return rank;
}

/********************************************************************* 
 ** Function: print()
 ** Description: Prints out the suit and rank of the card
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print out the suit and rank of the card to the console
 *********************************************************************/ 
void Card::print() {
    if (rank == 0) {
        std::cout << "Ace";
    }
    else if (rank < 10) {
        std::cout << (rank + 1);
    }
    else if (rank == 10) {
        std::cout << "Jack";
    }
    else if (rank == 11) {
        std::cout << "Queen";
    }
    else {
        std::cout << "King";
    }
    std::cout << " ";
    if (suit == 0) {
        std::cout << "of clubs";
    }
    else if (suit == 1) {
        std::cout << "of diamonds";
    }
    else if (suit == 2) {
        std::cout << "of hearts";
    }
    else {
        std::cout << "of spades";
    }
    std::cout << std::endl;
}