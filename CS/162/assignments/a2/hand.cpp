#include "hand.h"

/********************************************************************* 
 ** Function: Hand(int, int) constructor
 ** Description: Creates Hand object and initializes cards[] array size and capacity
 ** Parameters: m, n should be positive integers
 ** Pre-Conditions: m should be larger than n
 ** Post-Conditions: Should return true or false if _s_ is a positive integer
 *********************************************************************/ 
Hand::Hand(int m, int n) {
    cards = new Card [m];
    n_cards = n;
}

/* ---------Big Three---------- */
/********************************************************************* 
 ** Function: ~Hand() destructor
 ** Description: Frees dynamically allocated cards[] array and deletes object
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should have no memory leaks
 *********************************************************************/ 
Hand::~Hand() {
    std::cout << "Calling Hand destructor" << std::endl;
    delete [] cards;
}

/********************************************************************* 
 ** Function: Hand(const Hand &)
 ** Description: Copy constructor for Hand object
 ** Parameters: const Hand &h
 ** Pre-Conditions: h should be a valid hand object initialized and everything
 ** Post-Conditions: Should construct Hand object as a deep copy of h
 *********************************************************************/ 
Hand::Hand(const Hand &h) {
    std::cout << "Calling Hand copy constructor" << std::endl;
    this->n_cards = h.n_cards;
    // Deep copy of dynamically allocated array
    this->cards = new Card[52];
    for (int i = 0; i < n_cards; i++) {
        cards[i] = h.cards[i];
    }
}

/********************************************************************* 
 ** Function: operator=(const Hand &)
 ** Description: Assignment operator overload
 ** Parameters: const Hand &h
 ** Pre-Conditions: h should be a valid hand object initialized and everything
 ** Post-Conditions: Should make it so that the assignment operator is a deep copy rather than a shallow one
 *********************************************************************/ 
Hand& Hand::operator=(const Hand &h) {
    std::cout << "Calling Hand assignment operator overload" << std::endl;
    delete [] cards;
    this->n_cards = h.n_cards;
    // Deep copy of dynamically allocated array
    this->cards = new Card[52];
    for (int i = 0; i < n_cards; i++) {
        cards[i] = h.cards[i];
    }
    return *this;
}
/* ---------End of Big Three---------*/

/********************************************************************* 
 ** Function: add_card(Card)
 ** Description: Appends Card object to end of array cards[]
 ** Parameters: Card c
 ** Pre-Conditions: n_cards must be initialized and less than 52, c must be a valid card object
 ** Post-Conditions: c should be appended to end of cards[] array
 *********************************************************************/ 
void Hand::add_card(Card c) {
    cards[n_cards] = c;     // Add card to the next free index (ie. if I have 0 cards, add to the 0 index etc...)
    n_cards++;
}

/********************************************************************* 
 ** Function: take_card_at(int)
 ** Description: Removes card at given index and returns that card
 ** Parameters: int i
 ** Pre-Conditions: i must be less than n_cards so that it is a legitamate index
 ** Post-Conditions: Should make it so that the assignment operator is a deep copy rather than a shallow one
 *********************************************************************/ 
Card Hand::take_card_at(int i) {
    if (i >= n_cards) {
        std::cout << "Error, trying to take card at i=" << i << ", which is out of range.\n";
        exit(1);
    } else {
        Card c = cards[i];
        n_cards--;
        for (int j = i; j < n_cards; j++) {
            cards[j] = cards[j+1];
        }
        return c;
    }
}

/********************************************************************* 
 ** Function: check_card_match(Card)
 ** Description: Checks if card can be placed on pile (matching suit/rank/wildcard)
 ** Parameters: Card _card_
 ** Pre-Conditions: _card_ must have suit and rank, and 7 must indicate the card is an eight
 ** Post-Conditions: Should return true if card can be placed on pile or false if not
 *********************************************************************/ 
bool Hand::check_card_match(Card _card_) {
    if (_card_.get_rank() == cards[n_cards-1].get_rank()) {
        std::cout << "Card rank matches top of pile!\n";
        add_card(_card_);
        return true;
    } else if (_card_.get_suit() == cards[n_cards-1].get_suit()) {
        std::cout << "Card suit matches top of pile!\n";
        add_card(_card_);
        return true;
    } else if (_card_.get_rank() == 7) {
        std::cout << "Eight has been played!\n";
        add_card(_card_);
        return true;
    } else {
        std::cout << "Card does not match. Go fish. \n";
        return false;
    }
}

/********************************************************************* 
 ** Function: print_hand()
 ** Description: Prints all cards in hand to console
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print hand to console
 *********************************************************************/ 
void Hand::print_hand() {
    for (int i = 0; i < n_cards; i++) {
        cards[i].print();
    }
    std::cout << std::endl;
}

/********************************************************************* 
 ** Function: print_top()
 ** Description: Prints the card on the top of the pile
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print card at the end of the array
 *********************************************************************/ 
void Hand::print_top() {
    std::cout << "Card on top: ";
    cards[n_cards-1].print();
}

/********************************************************************* 
 ** Function: print_at()
 ** Description: Prints card at a given index
 ** Parameters: int i
 ** Pre-Conditions: i must be an integer between 0 and (n_cards - 1)
 ** Post-Conditions: Should print card at given index
 *********************************************************************/ 
void Hand::print_at(int i) {
    if (i >= n_cards) {
        std::cout << "Error: trying to print card at invalid index " << i << ".\n";
    } else {
        cards[i].print();
    }
}

/********************************************************************* 
 ** Function: get_n_cards()
 ** Description: Accessor for n_cards member
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return the number cards in cards[] array
 *********************************************************************/ 
int Hand::get_n_cards() {
    return n_cards;
}

/********************************************************************* 
 ** Function: get_card_at(int)
 ** Description: Accessor for cards array
 ** Parameters: int _i_
 ** Pre-Conditions: _i_ must be an integer between 0 and (n_cards - 1)
 ** Post-Conditions: Should return card at the given index
 *********************************************************************/ 
Card Hand::get_card_at(int _i_) {
    return cards[_i_];
}