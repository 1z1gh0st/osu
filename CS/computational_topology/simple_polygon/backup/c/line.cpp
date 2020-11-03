#include "line.h"
#include <cmath>
#include <limits>

bool liesBetween(double _lim1_, double _lim2_, double _x_) {
    if (_lim1_ > _lim2_) { 
        return (_x_ >= _lim2_ && _x_ <= _lim1_);
    }
    else {
        return (_x_ <= _lim2_ && _x_ >= _lim1_);
    }
}

Line::Line(const Point _p1_, const Point _p2_) {
    p1_ = _p1_;
    p2_ = _p2_;
    length_ = Point::distance(_p1_, _p2_);
    if (_p1_.x() == _p2_.x()) {
        angle_ = Angle(M_PI / 2);
        slope_ = std::numeric_limits<double>::max();
    }
    else if (_p1_.y() == _p2_.y()) {
        angle_ = Angle(0);
        slope_ = 0;
    }
    else {
        double rise = _p1_.y() - _p2_.y();
        double run = _p1_.x() - _p2_.x();
        slope_ = rise / run;
        angle_ = Angle(atan(slope_));
    }
    yIntercept_ = _p1_.y() - (slope_ * _p1_.x());
}

bool Line::operator==(const Line _other_) const {
    if (p1_ == _other_.p1_ && p2_ == _other_.p2_) {
        return true;
    }
    else if (p1_ == _other_.p2_ && p2_ == _other_.p1_) {
        return true;
    }
    else {
        return false;
    }
}

bool Line::operator<(const Line _other_) const {
    return length_ < _other_.length_;
}

bool Line::operator>(const Line _other_) const {
    return length_ > _other_.length_;
}

bool Line::operator<=(const Line _other_) const {
    return length_ <= _other_.length_;
}

bool Line::operator>=(const Line _other_) const {
    return length_ >= _other_.length_;
}

bool Line::intersects(const Point _point_) const {
    if (liesBetween(p1_.x(), p2_.x(), _point_.x())) {
        return (this->angle() == Line(_point_, p1_).angle());
    }
    else {
        return false;
    }
}

Point* Line::intersects(const Line _other_) const {
    Point A = p1_;
    Point B = p2_;
    Point C = _other_.p1();
    Point D = _other_.p2();
    Point* intersection = NULL;
    double xIntersection = (_other_.yIntercept() - yIntercept_) / (slope_ - _other_.slope());
    if (liesBetween(A.x(), B.x(), xIntersection) && liesBetween(C.x(), D.x(), xIntersection)) {
        double yIntersection = (slope_ * xIntersection) + yIntercept_;
        *intersection = Point(xIntersection, yIntersection);
    }
    return intersection;
}

Point* Line::formsPath(const Line _other_) const {
    Point A = p1_;
    Point B = p2_;
    Point C = _other_.p1();
    Point D = _other_.p2();
    Point* result = NULL;
    if (A == C) {
        *result = A;
    }
    else if (A == D) {
        *result = A;
    }
    else if (B == C) {
        *result = B;
    }
    else if (B == D) {
        *result = B;
    }
    return result;
}

Point Line::p1() const {
    return p1_;
}

Point Line::p2() const {
    return p2_;
}

double Line::length() const {
    return length_;
}

Angle Line::angle() const {
    return angle_;
}

double Line::slope() const {
    return slope_;
}

double Line::yIntercept() const {
    return yIntercept_;
}

