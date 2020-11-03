#include "polygon.h"

#include <iostream>

int main() {
    Point A = Point(1, 1);
    Point B;
    Point C = Point(1, -1);
    Polygon firstPolygon = Polygon(A, B, C);
    Point D = Point(-2, 0.5);
    firstPolygon.print();
    firstPolygon.addPoint(D);
    firstPolygon.print();
    return 0;
}
