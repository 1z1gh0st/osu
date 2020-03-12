#include "deck.h"

/********************************************************************* 
 ** Function: Deck()
 ** Description: constructor for Deck object
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should initialize Deck with card array containing all 52 cards
 *********************************************************************/ 
Deck::Deck() {
    generate_deck();
}

/********************************************************************* 
 ** Function: ~Deck()
 ** Description: Destructor for Deck obj
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should free all memory allocated by deck object
 *********************************************************************/ 
Deck::~Deck() {

}

/********************************************************************* 
 ** Function: check_card_match(Card)
 ** Description: Checks if card can be placed on pile (matching suit/rank/wildcard)
 ** Parameters: Card _card_
 ** Pre-Conditions: _card_ must have suit and rank, and 7 must indicate the card is an eight
 ** Post-Conditions: Should return true if card can be placed on pile or false if not
 *********************************************************************/ 
void Deck::generate_deck() {
    int index = 0;
    while (index < 52) {
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 0; rank < 13; rank++) {
                cards[index].set_suit(suit);
                cards[index].set_rank(rank);
                index++;
            }
        }
    }
}

/********************************************************************* 
 ** Function: shuffle()
 ** Description: Shuffles all the cards in the deck
 ** Parameters: none
 ** Pre-Conditions: Deck cards[] array member must have 52 indicies
 ** Post-Conditions: Should shuffle deck somewhat randomly (only converges to random if you take a limit to infinity upon s)
 *********************************************************************/ 
void Deck::shuffle() {
    
    /* seed the time */
    srand(time(NULL));

    /* swap cards 100 times to shuffle */
    for (int s = 0; s < 100; s++) {

        /* pick two random indecies */
        int a = rand() % 52;
        int b = rand() % 52;

        /* swap said indecies */
        Card swap = cards[a];
        cards[a] = cards[b];
        cards[b] = swap;
    }
}

/********************************************************************* 
 ** Function: card_at(int)
 ** Description: Getter for cards in card array
 ** Parameters: int i
 ** Pre-Conditions: i must be between 0 and the size of the card array
 ** Post-Conditions: Should return Card object at associated index
 *********************************************************************/ 
Card Deck::card_at(int i) {
    return cards[i];
}

/********************************************************************* 
 ** Function: take_card()
 ** Description: Removes and returns card at the end of the array
 ** Parameters: none
 ** Pre-Conditions: n_cards must be greater than 0 and there must be a card at cards[n_cards-1]
 ** Post-Conditions: Should return the top card and remove it from the deck
 *********************************************************************/ 
Card Deck::take_card() {
    /* DEBUG
    std::cout << "Taking card from deck at " << (n_cards - 1) << std::endl;
    */
    n_cards--;
    return cards[n_cards];
}

/********************************************************************* 
 ** Function: print()
 ** Description: Prints all cards in deck
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print all the cards that are in the deck
 *********************************************************************/ 
void Deck::print() {
    for (int i = 0; i < 52; i++) {
        card_at(i).print();
    }
}

/********************************************************************* 
 ** Function: get_n_cards()
 ** Description: Getter for the n_cards member
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return the member n_cards of Deck object
 *********************************************************************/ 
int Deck::get_n_cards() {
    return n_cards;
}