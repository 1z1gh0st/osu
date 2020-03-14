/******************************************************
** Program: input_handler.cpp
** Author: Philip Warton
** Date: 03/14/2020
** Description: Function definitions for Input_Handler
** Input: none
** Output: none
******************************************************/
#include "input_handler.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/********************************************************************* 
 ** Function: get_integer()
 ** Description: Demands integer input from user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return an integer based on user input
 *********************************************************************/ 
int Input_Handler::get_integer() {
    string input;
    do {
        getline(cin, input);
    } while (!is_int(input));
    return stoi(input);
}

/********************************************************************* 
 ** Function: get_uint()
 ** Description: Demands integer input from user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return an integer based on user input
 *********************************************************************/ 
unsigned int Input_Handler::get_uint() {
    string input;
    do {
        getline(cin, input);
    } while (!is_uint(input));
    return stoul(input);
}

/********************************************************************* 
 ** Function: is_int(string)
 ** Description: Checks if a c++ string is an integer
 ** Parameters: string s
 ** Pre-Conditions: Assumes s is a valid string
 ** Post-Conditions: Should return true if s is an integer, false otherwise
 *********************************************************************/ 
bool Input_Handler::is_int(string s) {
    if (s[0] != 45 && (s[0] > 57 || s[0] < 48)) {
        return false;
    }
    for (int i = 1; i < s.length(); i++) {
        if (s[i] > 57 || s[i] < 48) {
            return false;
        }
    }
    return true;
}

/********************************************************************* 
 ** Function: is_uint(string)
 ** Description: Checks if a c++ string is an integer
 ** Parameters: string s
 ** Pre-Conditions: Assumes s is a valid string
 ** Post-Conditions: Should return true if s is an integer, false otherwise
 *********************************************************************/ 
bool Input_Handler::is_uint(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 57 || s[i] < 48) {
            return false;
        }
    }
    return true;
}

/********************************************************************* 
 ** Function: get_specific_char(char *)
 ** Description: Gets a char input from the user from the given char array
 ** Parameters: char *a (should be array of characters)
 ** Pre-Conditions: Assumes a is an array of chars
 ** Post-Conditions: Should return a character from the given array based on user input
 *********************************************************************/ 
char Input_Handler::get_specific_char(char *a) {
    string input;
    do {
        getline(cin, input);
    } while (!is_specific_char(a, input));
    return input[0];
}

/********************************************************************* 
 ** Function: is_specific_char(char *a, string s)
 ** Description: Checks if s is a char from array a
 ** Parameters: char *a, string s
 ** Pre-Conditions: Assumes a is a char array
 ** Post-Conditions: Should return true if a is char from a, otherwise false
 *********************************************************************/ 
bool Input_Handler::is_specific_char(char *a, string s) {
    if (s.length() != 1) {
        return false;
    }
    for (int i = 0; i < sizeof(a)/sizeof(*a); i++) {
        if (s[0] == a[i]) {
            return true;
        }
    }
    return false;
}