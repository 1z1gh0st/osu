#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>

using std::string;

class Input_Handler {
    private:
    public:
        static int get_integer();
        static bool is_int(string);
        static char get_specific_char(char*);
        static bool is_specific_char(char*, string);
};

#endif