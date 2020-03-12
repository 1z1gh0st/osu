#include "board.h"

using std::cout;
using std::endl;

using std::out_of_range;
using std::invalid_argument;

/********************************************************************* 
 ** Function: Board
 ** Description: Constructor for class 'Board'
 ** Parameters: int s
 ** Pre-Conditions: none
 ** Post-Conditions: Should create and initialize Board object
 *********************************************************************/ 
Board::Board(int s, bool d) {
    size = s;
    debug_mode = d;
    array = vector<vector<Room>> (size, vector<Room> (size, Room(!debug_mode)));
    add_event("Wumpus");
    add_event("Pit");
    add_event("Pit");
    add_event("Bats");
    add_event("Bats");
    add_event("Gold");
    Point p = pick_random_room();
    int temp = p.get_x();
    p.set_x(p.get_y());
    p.set_y(temp);
    rope = p;
    player = InteractiveObject("Player", rope, size);
    arrows = 3;
}

/********************************************************************* 
 ** Function: pick_random_room
 ** Description: Chooses a random point (x,y) on the board
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return a point with two random x and y coordinates  
 *********************************************************************/ 
Point Board::pick_random_room() {
    Point result (2, 0);
    do {
        result.set_x(rand() % size);
        result.set_y(rand() % size);
    } while (array.at(result.get_y()).at(result.get_x()).get_type() != "Empty");
    return result;
}

/********************************************************************* 
 ** Function: swap_rooms
 ** Description: Switches two rooms on the game board
 ** Parameters: point a, point b
 ** Pre-Conditions: none
 ** Post-Conditions: Should swap the two rooms properly
 *********************************************************************/ 
void Board::swap_rooms(Point a, Point b) {
    if (a.in_range(size, size) && a.in_range(size, size)) {
        Room temp_room(!debug_mode);
        temp_room.set_equal(array.at(a.get_y()).at(a.get_x()));
        array.at(a.get_y()).at(a.get_y()).set_equal(array.at(b.get_y()).at(b.get_x()));
        array.at(b.get_y()).at(b.get_x()).set_equal(temp_room);
        // array.at(a.get_y()).at(a.get_x()) = array.at(b.get_y()).at(b.get_x());
        // array.at(b.get_y()).at(b.get_x()) = temp_room;
    } else {
        throw out_of_range("Error: point a or b out of range");
    }
}

/********************************************************************* 
 ** Function: print_board
 ** Description: Prints board in current state
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should show board in debug state in console
 *********************************************************************/ 
void Board::print_board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "+---";
        }
        cout << "+" << endl;
        for (int j = 0; j < size; j++) {
            cout << "| ";
            Point curr_pos = Point(i,j);
            if (curr_pos == player.get_pos()) {
                cout << ".";
            } else {
                array.at(i).at(j).print_room();
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < size; j++) {
        cout << "+---";
    }
    cout << "+" << endl;

    /* Should print out as: 
        +---+---+---+---+
        |   |   |   |   |
        +---+---+---+---+
        |   |   |   |   |
        +---+---+---+---+
        |   |   |   |   |
        +---+---+---+---+
        |   |   |   |   |
        +---+---+---+---+     */
    cout << "Position : x=" << player.get_pos().get_x() << ", y=" << player.get_pos().get_y() << endl;
    cout << "Arrows : " << arrows << endl;
    cout << "Gold :";
    if (player.has_gold()) {
        cout << " yes" << endl;
    } else {
        cout << " no" << endl;
    }
}

/********************************************************************* 
 ** Function: add_event
 ** Description: Puts event into room given string of event name
 ** Parameters: string s
 ** Pre-Conditions: s shouold be wumpus, gold, pit or bats
 ** Post-Conditions: Should correctly add the event to a random empty room
 *********************************************************************/ 
void Board::add_event(string s) {
    Point p = pick_random_room();
    array.at(p.get_y()).at(p.get_x()).add_event(s);
}

/********************************************************************* 
 ** Function: turn
 ** Description: allows player turn to occur
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should be able to handle any input from the player and perform the correct action based on that input
 *********************************************************************/ 
void Board::turn() {
    player_shoots_arrow();
    if (!player.is_skip_turn()) {
        player.player_move();
    } else {
        player.change_skip_turn();
    }
    int x = player.get_pos().get_x();
    int y = player.get_pos().get_y();
    if (player.has_gold() && player.get_pos() == rope) {
        cout << "You have escaped with the gold! Congrats" << endl;
        player.die();
    } else {
        if (array.at(x).at(y).is_empty()) {
            cout << endl << endl << array.at(x).at(y).get_type() << endl << endl;
            if (x + 1 < size) {
                array.at(x+1).at(y).precept();
            }
            if (x - 1 >= 0) {
                array.at(x-1).at(y).precept();
            }
            if (y + 1 < size) {
                array.at(x).at(y+1).precept();
            }
            if (y - 1 >= 0) {
                array.at(x).at(y-1).precept();
            }
        } else {
            array.at(x).at(y).give_object(player);
            if (array[x][y].get_type() == "Gold") {
                array[x][y].clear();
            }
        }
    }
    
}

/********************************************************************* 
 ** Function: get_player
 ** Description: getter for player member of board object
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return player
 *********************************************************************/ 
InteractiveObject Board::get_player() {
    return player;
}

/********************************************************************* 
 ** Function: player_shoots_arrow
 ** Description: Allows the player to shoot an arrow and deal with what happens when that occurs
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should either kill wumpus, wake up wumpus, or do nothing
 *********************************************************************/ 
void Board::player_shoots_arrow() {
    if (arrows > 0) {
    bool shoot_arrow = false;
        cout << "Would you like to shoot an arrow? (0. no) (1. yes) ";
        shoot_arrow = (bool)InputHandler::get_input_between(0,1);
        if (shoot_arrow) {
            arrows--;
            cout << "Enter arrow direction";
            string direction = player.get_direction_input();
            fire_arrow(direction);
        }
    }
}

/********************************************************************* 
 ** Function: Fire_arrow
 ** Description: Functionality for the arrow moving in a given direction
 ** Parameters: strign direction
 ** Pre-Conditions: direction should be up down left or right
 ** Post-Conditions: Should do the same as the above function
 *********************************************************************/ 
void Board::fire_arrow(string direction) {
    cout << "Firing arrow in the " << direction << " direction!" << endl;
    InteractiveObject arrow = InteractiveObject("Arrow", player.get_pos(), size);
    cout << "good to go!" << endl;
    for (int i = 0; i < 3; i++) {
        arrow.move_obj(direction);
        int x = arrow.get_pos().get_x();
        int y = arrow.get_pos().get_y();
        if (array.at(x).at(y).is_empty()) {
            // nothing
        } else {
            
            if (array[x][y].get_type() == "Wumpus") {
                array.at(x).at(y).give_object(arrow);
                array[x][y].clear();
            }
        }
    }
    int awoken = 0;
    InteractiveObject sound = InteractiveObject("Sound", Point(), size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (array.at(i).at(j).get_type() == "Wumpus") {
                awoken = array.at(i).at(j).give_object(sound);
                if (awoken != 0) {
                    Point new_wumpus_location = pick_random_room();
                    swap_rooms(new_wumpus_location, Point(i,j));
                }
            }
        }
    }
}