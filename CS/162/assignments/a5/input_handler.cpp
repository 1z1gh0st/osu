#include "input_handler.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int Input_Handler::get_integer() {
    string input;
    do {
        getline(cin, input);
    } while (!is_int(input));
    return stoi(input);
}

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

char Input_Handler::get_specific_char(char *a) {
    string input;
    do {
        getline(cin, input);
    } while (!is_specific_char(a, input));
    return input[0];
}

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