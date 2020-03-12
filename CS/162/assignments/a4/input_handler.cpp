#include "input_handler.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;
using std::stoi;
using std::cerr;

/********************************************************************* 
 ** Function: is_int(std::string)
 ** Description: Checks if string is a positive integer or not
 ** Parameters: std::string _s_
 ** Pre-Conditions: _s_ must be a valid string
 ** Post-Conditions: Should return true or false if _s_ is a positive integer
 *********************************************************************/ 
bool InputHandler::is_natural(string _s_) {
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
    string input;
    int num;
    getline(cin, input);
    while (1) {
        while (!is_natural(input)) {
            cout << "Input must be a number : ";
            getline(cin, input);
        }
        num = stoi(input);
        if (num < _min_ || num > _max_) {
            cout << "Number must be between " << _min_ << " and " << _max_ << " : ";
            getline(cin, input);
        } else { break; }
    }
    return num;
}

char InputHandler::get_wasd() {
    char in = 0;
    string input;
    bool is_wasd = false;
    while (!is_wasd) {
        cout << ">> ";
        getline(cin, input);
        in = input.at(0);
        if (in == 'w' || in == 'a' || in == 's' || in == 'd') {
            is_wasd = true;
            return in;
        } else {
            cout << "Please input 'w' 'a' 's' or 'd'." << endl;
        }
    }
}

/********************************************************************* 
 ** Function: InputHandler
 ** Description: Constructor
 ** Parameters: cmd line args
 ** Pre-Conditions: none
 ** Post-Conditions: Should error handle properly given any cmd line args
 *********************************************************************/ 
InputHandler::InputHandler(int argc, char **argv) {
    try {
        if (argc < 2) {
            throw invalid_argument("ERROR, not enought command line arguments. Enter a number to specify size.");
        }
        string size_input = argv[1];
        if (!is_natural(size_input) || stoi(size_input) < 4 || stoi(size_input) > 10000) {
            throw invalid_argument("ERROR, command line argument 1 must be a positive integer between 4 and 10000");
        } else {
            size = stoi(size_input);
        }
        if (argc > 3) {
            throw invalid_argument("ERROR, too many command line arguments");
        } else {
            if (argc == 3) {
                string debug_input = argv[2];
                if (debug_input == "true") {
                    debug = true;
                } else if (debug_input == "false") {
                    debug = false;
                } else {
                    throw invalid_argument("ERROR, argument 2 must be 'true' or 'false'");
                }
            }
        }
    } catch (invalid_argument e) {
        cerr << e.what() << endl;
        cout << "Please enter the size of your game board:\n>> ";
        size = (int)get_input_between(4, 10000);
        cout << "Would you like to enter debug mode?" << endl;
        cout << "    0. No" << endl;
        cout << "    1. Yes" << endl;
        cout << ">> ";
        debug = (bool)get_input_between(0,1);
    }
}

/* Function: getter for member variable 'size' */
int InputHandler::get_size() const {
    return size;
}

/* Function: getter for member variable 'debug' */
bool InputHandler::is_debug() const {
    return debug;
}
