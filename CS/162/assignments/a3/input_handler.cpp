#include "input_handler.h"

/********************************************************************* 
 ** Function: is_int(std::string)
 ** Description: Checks if string is a positive integer or not
 ** Parameters: std::string _s_
 ** Pre-Conditions: _s_ must be a valid string
 ** Post-Conditions: Should return true or false if _s_ is a positive integer
 *********************************************************************/ 
bool InputHandler::is_int(std::string _s_) {
    for (int i = 0; i < _s_.length(); i++) {
        if (_s_.at(i) > '9' || _s_.at(i) < '0') {
            return false;
        }
    }
    return true;
}

/********************************************************************* 
 ** Function: get_input_between(int, int)
 ** Description: Gets input bounded by two integers
 ** Parameters: int _min_, int _max_
 ** Pre-Conditions: _min_ must be less than or equal to _max_
 ** Post-Conditions: Should demand user input be a positive number between min and max
 *********************************************************************/ 
int InputHandler::get_input_between(int _min_, int _max_) {
    std::string input;
    int num;
    getline(std::cin, input);
    while (1) {
        while (!is_int(input)) {
            std::cout << "Input must be a number : ";
            getline(std::cin, input);
        }
        num = stoi(input);
        if (num < _min_ || num > _max_) {
            std::cout << "Number must be between " << _min_ << " and " << _max_ << " : ";
            getline(std::cin, input);
        } else { break; }
    }
    return num;
}