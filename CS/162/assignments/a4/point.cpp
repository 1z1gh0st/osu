#include "point.h"

/********************************************************************* 
 ** Function: Point
 ** Description: Constructor for class 'Point'
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should create and initialize Point at (0,0)
 *********************************************************************/ 
Point::Point() {
    x = 0;
    y = 0;
}

/********************************************************************* 
 ** Function: Point
 ** Description: Constructor for class 'Point'
 ** Parameters: x_in, y_in
 ** Pre-Conditions: none
 ** Post-Conditions: Should create and initialize Point at (x_in, y_in)
 *********************************************************************/ 
Point::Point(int x_in, int y_in) {
    x = x_in;
    y = y_in;
}

/********************************************************************* 
 ** Function: operator=
 ** Description: Assignment operator overload
 ** Parameters: const Point&p
 ** Pre-Conditions: none
 ** Post-Conditions: Should do a deep copy of the Point object
 *********************************************************************/ 
void Point::operator=(const Point &p) {
    x = p.get_x();
    y = p.get_y();
}

bool Point::operator==(const Point &p) {
    return (p.get_x() == x && p.get_y() == y);
}

/********************************************************************* 
 ** Function: get_x
 ** Description: Getter for x
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return x
 *********************************************************************/ 
int Point::get_x() const {
    return x;
}

/********************************************************************* 
 ** Function: get_y
 ** Description: Getter for y
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Should return y
 *********************************************************************/ 
int Point::get_y() const {
    return y;
}


/********************************************************************* 
 ** Function: set_x
 ** Description: Setter for x
 ** Parameters: x_in
 ** Pre-Conditions: none
 ** Post-Conditions: Should set x to x_in
 *********************************************************************/ 
void Point::set_x(int x_in) {
    x = x_in;
}

/********************************************************************* 
 ** Function: set_y
 ** Description: Setter for y
 ** Parameters: y_in
 ** Pre-Conditions: none
 ** Post-Conditions: Should set y to y_in
 *********************************************************************/ 
void Point::set_y(int y_in) {
    y = y_in;
}

/********************************************************************* 
 ** Function: in_range
 ** Description: Check if coordinates are in a given range
 ** Parameters: max_x, max_y
 ** Pre-Conditions: x and y must be positive
 ** Post-Conditions: Should return true if in range or false if not
 *********************************************************************/ 
bool Point::in_range(int max_x, int max_y) {
    bool x_in_range = (x < max_x && x >= 0);
    bool y_in_range = (y < max_y && y >= 0);
    return (x_in_range && y_in_range);
}