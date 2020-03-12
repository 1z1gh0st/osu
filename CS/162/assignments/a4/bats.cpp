#include "bats.h"

using std::cout;
using std::endl;

/********************************************************************* 
 ** Function: Bats
 ** Description: Constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should contstruct a bats object
 *********************************************************************/ 
Bats::Bats() {
    name = "Bats";
    precept_message = "You hear wings flapping.";
}


/********************************************************************* 
 ** Function: Encounter
 ** Description: Polymorphic function for bats
 ** Parameters: interactive object o
 ** Pre-Conditions: &o should be a valid INteractive Object object
 ** Post-Conditions: Should kill player if player encounters
 *********************************************************************/ 
int Bats::encounter(InteractiveObject &o) {
    if (o.get_name() == "Player") {
        cout << "You get moved by the bats." << endl;
        o.move_rand();
        o.change_skip_turn();
        return 1;
    } else {
        return 0;
    }
}