#include "pit.h"

using std::cout;
using std::endl;

Pit::Pit() {
    name = "Pit";
    precept_message = "You feel a breeze.";
}

int Pit::encounter(InteractiveObject &o) {
    if (o.get_name() == "Player") {
        cout << "You fall into a bottomless pit. You die!" << endl;
        o.die();
        return 1;
    } else {
        return 0;
    }
}