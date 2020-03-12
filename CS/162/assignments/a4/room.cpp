#include "room.h"

using std::cout;
using std::endl;
using std::invalid_argument;

Room::Room(bool h) {
    type = "Empty";
    empty = true;
    hidden = h;
    event = NULL;
}

Room::Room(bool h, string s) {
    type = s;
    empty = false;
    hidden = h;
    if (s == "Wumpus") {
        event = new Wumpus();
    } else if (s == "Gold") {
        event = new Gold();
    } else if (s == "Bats") {
        event = new Bats();
    } else if (s == "Pit") {
        event = new Pit();
    } else {
        throw invalid_argument("Name does not match known name, 'Wumpus', 'Gold', 'Bats', 'Pit'");
    }
}

Room::~Room() {

}

Room::Room(const Room &r) {
    type = r.type;
    event = r.event;
    hidden = r.hidden;
    empty = r.empty;
}

void Room::set_equal(Room &r) {
    cout << "Current type: " << type << " | R type: " << r.get_type() << endl;
    type = r.get_type();
    cout << "Current event: " << event << " | R Event: " << r.get_event() << endl;
    event = r.get_event();
    cout << "Current empty: " << empty << " | R empty: " << r.is_empty() << endl;
    empty = r.is_empty();
    cout << "Current hidden: " << hidden << " | R Hidden: " << r.is_hidden() << endl;
    hidden = r.is_hidden();
}

Room Room::operator=(const Room &r) {
    cout << "1" << endl;
    type = r.type;
    cout << "2" << endl;
    event = r.event;
    cout << "3" << endl;
    empty = r.empty;
    cout << "4" << endl;
    hidden = r.hidden;
    cout << "5" << endl;
}

bool Room::is_hidden() const {
    return hidden;
}

Event* Room::get_event() const {
    return event;
}

/********************************************************************* 
 ** Function: print_room
 ** Description: Prints the room
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print the status of the room and the even if in debug mode
 *********************************************************************/ 
void Room::print_room() {
    if (hidden) {
        cout << "X";
    } else {
        reveal();
    }
}

/********************************************************************* 
 ** Function: Reveal
 ** Description: Reveals what happens in the room
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should show what is going on in the room
 *********************************************************************/ 
void Room::reveal() {
    if (!empty) {
        cout << type.at(0);
    } else {
        cout << " ";
    }
}

string Room::get_type() const {
    return type;
}

int Room::give_object(InteractiveObject &o) {
    cout << "is give object called" << endl;
    return event->encounter(o);
}

bool Room::is_empty() const {
    return empty;
}

void Room::precept() {
    if (!empty) {
        event->precept();
    }
}

void Room::clear() {
    type = "empty";
    empty = true;
}

void Room::add_event(string s) {
    type = s;
    empty = false;
    if (s == "Wumpus") {
        event = new Wumpus();
    } else if (s == "Gold") {
        event = new Gold();
    } else if (s == "Bats") {
        event = new Bats();
    } else if (s == "Pit") {
        event = new Pit();
    } else {
        throw invalid_argument("Name does not match known name, 'Wumpus', 'Gold', 'Bats', 'Pit'");
    }
}