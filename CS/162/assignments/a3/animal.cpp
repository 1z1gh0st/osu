#include "animal.h"

using std::cout;

/********************************************************************* 
 ** Function: Animal() 
 ** Description: Contsructor for animal
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should initialize animal
 *********************************************************************/ 
Animal::Animal() {
    animal_type = "type_not_set";
    age = 0;
    monthly_food_cost = ((rand() % 40) + 80);
}

/********************************************************************* 
 ** Function: is_baby() const
 ** Description: Checks baby status
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return true if age less than 6
 *********************************************************************/ 
bool Animal::is_baby() const {
    return (age < 6) ? true : false;
}

/********************************************************************* 
 ** Function: is_adult() 
 ** Description: Checks adult status
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return true if age at least 48
 *********************************************************************/ 
bool Animal::is_adult() const {
    return (age >= 48) ? true : false;
}

/********************************************************************* 
 ** Function: print() 
 ** Description: Prints animal age group and type
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should print age group and type to console
 *********************************************************************/ 
void Animal::print() const {
    if (is_baby()) {
        cout << "Baby ";
    } else if (!is_adult()) {
        cout << "Adolescent ";
    } else {
        cout << "Adult ";
    }
    cout << animal_type;
}

/********************************************************************* 
 ** Function: get_age() 
 ** Description: Getter for age
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return age
 *********************************************************************/ 
int Animal::get_age() const {
    return age;
}

/********************************************************************* 
 ** Function: get_birth_rate() 
 ** Description: Getter for birth_rate
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return birth_rate
 *********************************************************************/ 
int Animal::get_birth_rate() const {
    return birth_rate;
}

/********************************************************************* 
 ** Function: get_cost() 
 ** Description: Getter for cost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return cost
 *********************************************************************/ 
long Animal::get_cost() const {
    return cost;
}

/********************************************************************* 
 ** Function: get_monthly_food_cost() 
 ** Description: Getter for monthly_food_cost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return monthly_food_cost
 *********************************************************************/ 
long Animal::get_monthly_food_cost() const {
    return monthly_food_cost;
}

/********************************************************************* 
 ** Function: get_monthly_revenue() 
 ** Description: Getter for monthly_revenue
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return monthly_revenue
 *********************************************************************/ 
long Animal::get_monthly_revenue() const {
    return (age < 6) ? monthly_revenue * 2 : monthly_revenue;
}

/********************************************************************* 
 ** Function: get_animal_type() 
 ** Description: Getter for animal_type
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return animal_type
 *********************************************************************/ 
string Animal::get_animal_type() const {
    return animal_type;
}

/********************************************************************* 
 ** Function: iterate_month() 
 ** Description: Increases age by one month and gets a new random food cost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should increase age by one and change monthly_food_cost by random amount
 *********************************************************************/ 
void Animal::iterate_month() {
    age++;
    monthly_food_cost += (((rand() % 40) - 20.0) / 100.0) * monthly_food_cost;
}

/********************************************************************* 
 ** Function: set_age() 
 ** Description: Setter for age
 ** Parameters: int _age_
 ** Pre-Conditions: _age_ should be a positive integer
 ** Post-Conditions: Should change age by given amount
 *********************************************************************/ 
void Animal::set_age(int _age_) {
    age = _age_;
}
