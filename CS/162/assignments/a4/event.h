#ifndef EVENT_H
#define EVENT_H

#include "interactive_obj.h"
#include <cstdlib>
#include <string>

using std::string;

class Event {
    protected:
        string precept_message;
        string name;
        char symbol;
    public:
        void show();
        void precept();
        virtual int encounter(InteractiveObject &) = 0;
};

#endif