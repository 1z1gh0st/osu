#include "zoo.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

/********************************************************************* 
 ** Function: Zoo::Zoo()
 ** Description: Constructor for Zoo object
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Zoo object should be created with empty Animal* array and 100000 dollars in the money variable
 *********************************************************************/ 
Zoo::Zoo() {
    array = new Animal* [0];
    array_length = 0;
    month = 0;
    special_event = 0;
    money = 100000;
}

/********************************************************************* 
 ** Function: Zoo::~Zoo()
 ** Description: Destructor for Zoo object
 ** Parameters: none
 ** Pre-Conditions: array_length must match length of array
 ** Post-Conditions: All dynamically allocated memory should be freed
 *********************************************************************/ 
Zoo::~Zoo() {
    for (int i = 0; i < array_length; i++) {
        delete (array[i]);
    }
    delete [] array;
}

/********************************************************************* 
 ** Function: Zoo::get_animal_at(int i) const
 ** Description: Getter for animal from array
 ** Parameters: int i
 ** Pre-Conditions: i must be a valid index between array length and 0
 ** Post-Conditions: Should return the animal object from the array at that index
 *********************************************************************/ 
Animal Zoo::get_animal_at(int i) const {
    if (i >= array_length || i < 0) {
        cout << "ERROR: Attempting to get animal at invalid index i=" << i << endl;
        exit(1);    // Error handler for bad idicies
    } else {
        return *array[i];
    }
}

/********************************************************************* 
 ** Function: Zoo::get_array_length() const
 ** Description: Getter for array_length
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return array length for zoo object
 *********************************************************************/ 
int Zoo::get_array_length() const {
    return array_length;
}

/********************************************************************* 
 ** Function: Zoo::get_month()
 ** Description: Getter for month variable
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return month value
 *********************************************************************/ 
int Zoo::get_month() const {
    return month;
}

/********************************************************************* 
 ** Function: Zoo::get_special_event() const
 ** Description: Getter for special_event
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return special event value
 *********************************************************************/ 
int Zoo::get_special_event() const {
    return special_event;
}

/********************************************************************* 
 ** Function: Zoo::get_money()
 ** Description: Getter for money
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return money value
 *********************************************************************/ 
long Zoo::get_money() const {
    return money;
}

/********************************************************************* 
 ** Function: Zoo::iterate_month()
 ** Description: Performs operations for every month
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Game should have advanced one month every time this fucntion runs
 *********************************************************************/ 
void Zoo::iterate_month() {
    month++;
    for (int i = 0; i < array_length; i++) {
        array[i]->iterate_month();
    }
    print_zoo_status();
    if (array_length > 0) {
        special_event_func();
        revenue();
        pay_food_cost();
    }
    allow_animal_purchase();
}

/********************************************************************* 
 ** Function: Zoo::special_event_func()
 ** Description: Runs one of four options for the monthly special event
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should choose a random number 0-3 and run one of four options
 **     depending on what number is chosen
 *********************************************************************/ 
void Zoo::special_event_func() {
    special_event = rand() % 4;
    int rand_animal_index = rand() % array_length;
    if (special_event == 0) {
        cout << "Sickness!!!" << endl;
        sickness(rand_animal_index);
    } else if (special_event == 1) {
        cout << "Babies!!!" << endl;
        reproduce(rand_animal_index);
    } else if (special_event == 2) {
        cout << "Attendance boom!!!" << endl;
    } else {
        cout << "No special event occured." << endl;
    }
}

/********************************************************************* 
 ** Function: Zoo::sickness()
 ** Description: Animal sickness occurs and the animal either dies or is taken care of
 ** Parameters: int rand_animal_index
 ** Pre-Conditions: rand_animal_index must be between 0 and array_length
 ** Post-Conditions: Money should change based on cost of animal sickness or animal should die and be removed from array
 *********************************************************************/ 
void Zoo::sickness(int rand_animal_index) {
    if (rand_animal_index >= array_length || rand_animal_index < 0) {
        cout << "ERROR: Random animal index out of range. Exiting program." << endl;
        exit(1);
    }
    int sickness_cost = array[rand_animal_index]->get_monthly_revenue() / 2;
    cout << "Your " << array[rand_animal_index]->get_animal_type() << " has gotten sick." << endl;
    if (money >= sickness_cost) {
        cout << "You pay $" << sickness_cost << ". " << endl;
        money -= sickness_cost;
    } else {
        cout << "Not enough funds availible. Your " << array[rand_animal_index]->get_animal_type() << " dies." << endl;
        remove_animal(rand_animal_index);
    }
}

/********************************************************************* 
 ** Function: Zoo::reproduce()
 ** Description: Special event where an animal has babies
 ** Parameters: int rand_animal_index
 ** Pre-Conditions: rand_animal_index must be between 0 and array_length
 ** Post-Conditions: Should add baby animals to array
 *********************************************************************/ 
void Zoo::reproduce(int rand_animal_index) {
    if (rand_animal_index >= array_length || rand_animal_index < 0) {
        cout << "ERROR: Random animal index out of range. Exiting program." << endl;
        exit(1);
    }
    string type = array[rand_animal_index]->get_animal_type();
    int amount = array[rand_animal_index]->get_birth_rate();
    if (type == "Tiger") {
        Tiger *t = new Tiger();
        add_animal(t);
    } else if (type == "Bear") {
        Bear *b = new Bear();
        add_animal(b);
    } else {
        Sea_Lion *sl = new Sea_Lion();
        add_animal(sl);
    }
}

/********************************************************************* 
 ** Function: Zoo::attendance_boom()
 ** Description: Special event where there is an attendance boom and all sea lions generate extra revenue
 ** Parameters: none
 ** Pre-Conditions: array_length must match length of array
 ** Post-Conditions: Should increment money by a random extra amount based on how many sea lions are within
 *********************************************************************/ 
void Zoo::attendance_boom() {
    int sea_lion_count = 0;
    for (int i = 0; i < array_length; i++) {
        if (array[i]->get_animal_type() == "Sea_Lion") {
            money += rand() % 250 + 150;
        }
    }
}

/********************************************************************* 
 ** Function: Zoo::add_animal()
 ** Description: Adds an animal to array
 ** Parameters: Animal *a
 ** Pre-Conditions: *a must be a pointer to a valid Animal object and array_length must match length of array
 ** Post-Conditions: Should copy the array to one of larger length and add *a to the end of the array
 *********************************************************************/ 
void Zoo::add_animal(Animal *a) {
    Animal **temp_arr = new Animal* [array_length + 1];
    for (int i = 0; i < array_length; i++) {
        temp_arr[i] = array[i];
    }
    temp_arr[array_length] = a;
    array_length++;
    delete [] array;
    array = temp_arr;
}

/********************************************************************* 
 ** Function: Zoo::remove_animal()
 ** Description: Removes animal from array
 ** Parameters: int index
 ** Pre-Conditions: index must be between 0 and array_length
 ** Post-Conditions: Array_length should decrement by one and the array 
 **     should only contain animals that were not the one at the given index
 *********************************************************************/ 
void Zoo::remove_animal(int index) {
    if (array_length != 0) {
        Animal **temp_arr = new Animal* [array_length - 1];
        for (int i = 0; i < array_length; i++) {
            if (i < index) {
                temp_arr[i] = array[i];
            } else if (i == index) {
                delete array[i];
                continue;
            } else {
                temp_arr[i - 1] = array[i];
            }
        }
        // free_array();
        delete [] array;
        array = temp_arr;
        array_length--;
    } else {
        cout << "ERROR: trying to remove animal from empty array" << endl;
        exit(1);
    }
}

/********************************************************************* 
 ** Function: Zoo::allow_animal_purchase()
 ** Description: Let the user purchase at most two animals
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should change money value based on animal purchases and add said animals to array
 *********************************************************************/ 
void Zoo::allow_animal_purchase() {
    for (int i = 0; i < 2; i++) {
        cout << "Would you like to purchase an animal? : " << endl;
        cout << "    1. Tiger ($12,000)" << endl;
        cout << "    2. Black Bear ($5,000)" << endl;
        cout << "    3. Sea Lion ($700)" << endl;
        cout << "    4. None" << endl;
        cout << ">> ";
        int animal_to_purchase_type = InputHandler::get_input_between(1, 4);
        if (animal_to_purchase_type == 1) {
            if (money >= 12000) {
                money -= 12000;
                Tiger *tiger = new Tiger;
                add_animal(tiger);
            } else {
                cout << "\nYou do not have enough funds to purchase this animal." << endl;
            }
        } else if (animal_to_purchase_type == 2) {
            if (money >= 5000) {
                money -= 5000;
                Bear *bear = new Bear;
                add_animal(bear);
            } else {
                cout << "\nYou do not have enough funds to purchase this animal." << endl;
            }
        } else if (animal_to_purchase_type == 3) {
            if (money >= 700) {
                money -= 700;
                Sea_Lion *sea_lion = new Sea_Lion;
                add_animal(sea_lion);
            } else {
                cout << "\nYou do not have enough funds to purchase this animal." << endl;
            }
        }
        if (animal_to_purchase_type != 4) {
            array[array_length - 1]->set_age(48);
        }
    }
}

/********************************************************************* 
 ** Function: Zoo::revenue()
 ** Description: Adds appropriate amount of revenue from animal based on animal type
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should increase money by correct amount
 *********************************************************************/ 
void Zoo::revenue() {
    for (int i = 0; i < array_length; i++) {
        money += array[i]->get_monthly_revenue();
    }
}

/********************************************************************* 
 ** Function: Zoo::pay_food_cost()
 ** Description: Takes away money based on animal food cost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should end game if out of money or take appropriate amount of money away
 *********************************************************************/ 
void Zoo::pay_food_cost() {
    for (int i = 0; i < array_length; i++) {
        money -= array[i]->get_monthly_food_cost();
        if (money < 0) {
            cout << "No money for food. Animal dies." << endl;
            remove_animal(i);
        }
    }
}

/********************************************************************* 
 ** Function: Zoo::print_zoo_status()
 ** Description: Prints the status of the zoo
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should display important details about zoo status to console
 *********************************************************************/ 
void Zoo::print_zoo_status() {
    cout << "--MONTH " << month << "--" << endl;
    cout << "Money : " << money << endl;
    if (array_length > 0) {
        cout << "Animals : " << endl;
        for (int i = 0; i < array_length; i++) {
            cout << "    " << array[i]->get_animal_type();
            cout << " : age = " << array[i]->get_age() << " months";
            cout << " : revenue = $" << array[i]->get_monthly_revenue();
            cout << " : food cost = $" << array[i]->get_monthly_food_cost() << endl;
        }
    } else {
        cout << "Your zoo has no animals. Nice!" << endl;
    }
    
}
