#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <iostream>

class InputHandler {
    public:
        static int get_input_between(int, int);
        static bool is_int(std::string);
};

#endif