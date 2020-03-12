#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"

#include <iostream>

using namespace std;

int main() {
    Shape my_shape = Shape("weird shape", "blue");
    cout << my_shape.area() << endl;
    Rectangle my_rect = Rectangle(2, 5.5);
    return 0;
}