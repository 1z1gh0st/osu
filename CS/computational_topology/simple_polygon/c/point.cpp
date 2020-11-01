#include "point.h"
#include <cmath>

/* Constructors */
Point::Point() {
    x_ = 0;
    y_ = 0;
}

Point::Point(const double _x_, const double _y_) {
    x_ = _x_;
    y_ = _y_;
}


/* Operators */
bool Point::operator==(const Point _other_) {
    return x_ == _other_.x_ && y_ == _other_.y_;
}

bool Point::operator!=(const Point _other_) {
    return !(*this == _other_);
}

bool Point::operator<(const Point _other_) {
    return norm_ < _other_.norm_;
}

bool Point::operator>(const Point _other_) {
    return norm_ > _other_.norm_;
}

bool Point::operator<=(const Point _other_) {
    return norm_ <= _other_.norm_;
}

bool Point::operator>=(const Point _other_) {
    return norm_ >= _other_.norm_;
}


/* Getters */
double Point::x() const { return x_; }
double Point::y() const { return y_; }
double Point::norm() const { return norm_; }


/* Setters */
void Point::setX(double _x_) { 
    x_ = _x_; 
    updateNorm();
}

void Point::setY(double _y_) {
    y_ = _y_;
    updateNorm();
}


/* Other */
double Point::distance(const Point _other_)  const {
    return Point(abs(x_ - _other_.x()), abs(y_ - _other_.y())).norm();
}

double Point::distance(const Point _p1_, const Point _p2_) {
    return _p1_.distance(_p2_);
}

/* Internal */
void Point::updateNorm() {
    norm_ = sqrt(pow(x_, 2) + pow(y_, 2));
}

