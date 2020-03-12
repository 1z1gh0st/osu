#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "tiger.h"
#include "sea_lion.h"
#include "bear.h"
#include "input_handler.h"

#include <iostream>

class Zoo {
    private:
        Animal **array;
        int array_length;
        int month;
        int special_event;
        long money;
    public:
        // Constructors
        Zoo();

        // Destructor
        ~Zoo();

        // Getters
        Animal get_animal_at(int) const;
        int get_array_length() const;
        int get_month() const;
        int get_special_event() const;
        long get_money() const;

        // Mutators
        void iterate_month();
        void special_event_func();
        void sickness(int);
        void reproduce(int);
        void attendance_boom();
        void allow_animal_purchase();
        void revenue();
        void pay_food_cost();

        // Array Mutators
        void add_animal(Animal*);
        void remove_animal(int);

        // Print
        void print_zoo_status();
};

#endif
