#include "rectangle.h"
#include "shape.h"

Rectangle::Rectangle(float w, float h) : Shape("rectangle", "blue") {
    width = w;
    height = h;
}

float Rectangle::area() {
    return width * height;
}