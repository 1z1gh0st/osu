#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include "interactive_obj.h"

class Wumpus: public Event {
    public:
        Wumpus();
        int encounter(InteractiveObject &);
};
#endif