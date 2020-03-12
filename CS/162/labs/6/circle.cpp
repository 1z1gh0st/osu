#include "circle.h"

Circle::Circle(float r) : Shape("circle", "green") {
    radius = r;
}

float Circle::area() {
    return (3.1415926535 * radius);
}