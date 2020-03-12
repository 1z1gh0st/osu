#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Animal {
    protected:
        int age;
        int birth_rate;
        long cost;
        long monthly_food_cost;
        long monthly_revenue;
        string animal_type;
    public:
        // Default Constructor
        Animal();

        // Accessors
        bool is_baby() const;
        bool is_adult() const;
        void print() const;

        // Getters
        int get_age() const;
        int get_birth_rate() const;
        long get_cost() const;
        long get_monthly_food_cost() const;
        long get_monthly_revenue() const;
        string get_animal_type() const;

        // Setters
        void set_age(int);

        // Mutators
        void iterate_month();
};

#endif
