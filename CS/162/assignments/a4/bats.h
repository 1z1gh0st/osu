#ifndef BATS_H
#define BATS_H

#include "event.h"

class Bats: public Event {
    public:
        Bats();
        int encounter(InteractiveObject &);
};

#endif