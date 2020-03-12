#include "game.h"

/********************************************************************* 
 ** Function: Game() constructor
 ** Description: Creates an object Game and initializes members
 ** Parameters: none
 ** Pre-Conditions: create_players() and create_deck() must be functions
 ** Post-Conditions: Should create Game object and initialize members
 *********************************************************************/ 
Game::Game() {
    create_players();
    create_deck();
}

/********************************************************************* 
 ** Function: create_players()
 ** Description: Sets player names
 ** Parameters: none
 ** Pre-Conditions: players[] array must be initialized, set_name(std::string) must be a function
 ** Post-Conditions: Should set player names appropriately
 *********************************************************************/ 
void Game::create_players() {
    players[0].set_name("Player 1");
    players[1].set_name("Player 2");
}

/********************************************************************* 
 ** Function: create_deck()
 ** Description: Shuffles the Deck cards member of Game object
 ** Parameters: none
 ** Pre-Conditions: Deck::shuffle() must be a fuction and cards must be a Deck
 ** Post-Conditions: Should shuffle deck
 *********************************************************************/ 
void Game::create_deck() {
    cards.shuffle();
}

/********************************************************************* 
 ** Function: play()
 ** Description: Deals cards and starts pile then runs game loop
 ** Parameters: none
 ** Pre-Conditions: Game::player_turn(Hand) and Game::computer_turn(Hand) must be functions
 ** Post-Conditions: Should play the game until game ending conditions
 *********************************************************************/ 
void Game::play() {

    /* Deal Cards */
    int cards_left_in_deck = 52;
    for (int i = 0; i < 14; i++) {
        if (i % 2 == 0) {
            players[0].give_card(cards.take_card());
        } else {
            players[1].give_card(cards.take_card());
        }
    }

    /* Starting the pile */
    Hand table_pile = Hand(52, 0);
    table_pile.add_card(cards.take_card());

    /* Game Loop */
    while (!check_win_conditions()) {
        player_turn(table_pile);
        computer_turn(table_pile);
    }
}

/********************************************************************* 
 ** Function: player_turn(Hand &)
 ** Description: Loops until player chooses a valid card to put on pile
 ** Parameters: Hand &_table_pile_ (pass by reference)
 ** Pre-Conditions: _table_pile_.cards must have at least one Card obj in it
 ** Post-Conditions: should break once player puts a valid card on the pile
 *********************************************************************/ 
void Game::player_turn(Hand &_table_pile_) {

    /* Player Turn */
    std::cout << "\n--YOUR TURN--\n";
    while (!check_win_conditions()) {
        _table_pile_.print_top();
        int p1_index = players[0].index_of_card_played();
        Card p1_card = players[0].take_card(p1_index);

        /* If the player chooses an eight let them pick the suit */
        if (p1_card.get_rank() == 7) {
            std::cout << "Choose the suit of your 8:" << std::endl;
            std::cout << "    1. Clubs" << std::endl;
            std::cout << "    2. Diamonds" << std::endl;
            std::cout << "    3. Hearts" << std::endl;
            std::cout << "    4. Spades" << std::endl;
            p1_card.set_suit(InputHandler::get_input_between(1,4)-1);
        }
        if (!_table_pile_.check_card_match(p1_card)) {
            std::cout << "You must draw a card.\n";
            players[0].give_card(p1_card);
            players[0].give_card(cards.take_card());
        } else { break; }
    }
}

/********************************************************************* 
 ** Function: computer_turn(Hand &)
 ** Description: Loops until computer chooses a valid card automatically to put on pile
 ** Parameters: Hand &_table_pile_ (pass by reference)
 ** Pre-Conditions: _table_pile_.cards must have at least one Card obj in it
 ** Post-Conditions: should break once computer puts a valid card on the pile
 *********************************************************************/ 
void Game::computer_turn(Hand &_table_pile_) {

    /* Computer Turn */
    std::cout << "\n--MY TURN--\n";
    while (!check_win_conditions()) {
        std::cout << players[1].get_n_cards() << " cards left...\n";
        int p2_index = players[1].index_of_first_valid_card(_table_pile_.get_card_at(_table_pile_.get_n_cards()-1));
        if (p2_index < 0) {
            std::cout << "I have no valid cards, will draw... :(\n";
            p2_index = 0;
        }
        Card p2_card = players[1].take_card(p2_index);

        /* If CPU chooses an eight let them choose the suit on card 1 in their hand */
        if (p2_card.get_rank() == 7) {
            p2_card.set_rank(players[1].get_card_at(players[1].get_n_cards()-1).get_rank());
        }
        if (!_table_pile_.check_card_match(p2_card)) {
            players[1].give_card(p2_card);
            players[1].give_card(cards.take_card());
        } else { break; }
    }
}

/********************************************************************* 
 ** Function: check_win_conditions()
 ** Description: Checks if the deck has run out (if so who has fewer cards) and checks if either player is out of cards
 ** Parameters: none
 ** Pre-Conditions: players[0] and players[1] must be initialized
 ** Post-Conditions: should return true if game over or false if not
 *********************************************************************/ 
bool Game::check_win_conditions() {
    /* Check Win Conditions */
    if (cards.get_n_cards() == 0) {
        if (players[0].get_n_cards() > players[1].get_n_cards()) {
            std::cout << "I win! >:)" << std::endl;
            return true;
        } else if (players[0].get_n_cards() < players[1].get_n_cards()) {
            std::cout << "You win!!!   ;_;" << std::endl; 
            return true;
        } else {
            std::cout << "Game drawn.\n";
            return true;
        }
    } else if (players[0].get_n_cards() == 0) {
        std::cout << "You win!" << std::endl;
        return true;
    } else if (players[1].get_n_cards() == 0) {
        std::cout << "I win!" << std::endl;
        return true;
    } else {
        return false;
    }
}