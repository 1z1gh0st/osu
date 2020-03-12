#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

class InputHandler {
    private:
        int size;
        bool debug;
    public:
        // Static functions
        static int get_input_between(int, int);
        static bool is_natural(std::string);
        static char get_wasd();
        
        // Constructor
        InputHandler(int, char **);

        // Getters
        int get_size() const ;
        bool is_debug() const ;
};

#endif