#include "wumpus.h"

using std::cout;
using std::endl;
using std::invalid_argument;

Wumpus::Wumpus() {
    name = "Wumpus";
    precept_message = "You smell a terrible stench.";
}

int Wumpus::encounter(InteractiveObject &o) {
    if (o.get_name() == "Player") {
        cout << "You have encountered the Wumpus, you die" << endl;
        o.die();
        return 1;
    } else if (o.get_name() == "Arrow") {
        cout << "Arrow hit the Wumpus, the Wumpus dies!" << endl;
        return 2;
    } else if (o.get_name() == "Sound") {
        bool woken_up = ((rand() % 4) != 0);
        if (woken_up) {
            cout << "The Wumpus has been awoken, and moved!" << endl;
        }
    } else {
        throw invalid_argument("The game obj passed in is unknown");
    }
}