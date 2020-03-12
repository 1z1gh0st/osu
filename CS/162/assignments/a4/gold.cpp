#include "gold.h"

using std::cout;
using std::endl;

Gold::Gold() {
    name = "Gold";
    precept_message = "You see a glimmer nearby.";
}

int Gold::encounter(InteractiveObject &o) {
    cout << "does encounter get called for gold" << endl;
    if (o.get_name() == "Player") {
        cout << "You have found the gold!" << endl;
        o.give_gold();
        return 1;
    } else {
        return 0;
    }
}