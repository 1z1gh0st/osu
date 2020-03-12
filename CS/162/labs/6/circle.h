#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape {
    private:
        float radius;
    public:
        Circle(float);
        float area();
};

#endif