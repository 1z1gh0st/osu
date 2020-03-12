#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "event.h"
#include "interactive_obj.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

using std::string;

class Room {
    private:
        bool empty;
        bool hidden;
        Event *event;
        string type;
    public:
        Room(bool);
        Room(bool, string);
        ~Room();

        Room operator=(const Room &);
        Room(const Room &);

        void set_equal(Room &);
        
        string get_type() const;
        Event* get_event() const;
        bool is_hidden() const;
        bool is_empty() const;

        void precept();

        void print_room();
        void reveal();
        int give_object(InteractiveObject &);
        void clear();
        void add_event(string);
};

#endif