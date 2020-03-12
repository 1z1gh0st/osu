#ifndef SHAPE_H
#define SHAPE_H
#include <cstdlib>
#include <string>

using std::string;

class Shape {
    protected: 
        string name;
        string color;
    public:
        Shape(string, string);
        float area();
};

#endif