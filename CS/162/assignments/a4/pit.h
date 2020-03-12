#ifndef PIT_H
#define PIT_H

#include "event.h"

class Pit: public Event {
    public:
        Pit();
        int encounter(InteractiveObject &);
};

#endif