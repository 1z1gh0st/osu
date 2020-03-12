#ifndef TIGER_H
#define TIGER_H

#include "animal.h"
#include <iostream>

class Tiger: public Animal {
    private:
        
    public:
        Tiger();
        void print_name() const;
};

#endif
