#include "line.h"
#include <cmath>

bool lies_between(double _lim1_, double _lim2_, double _x_) {
    if (_lim1_ > _lim2_) { 
        return (_x_ >= _lim2_ && _x_ <= _lim1_);
    }
    else {
        return (_x_ <= _lim2_ && _x_ >= _lim1_);
    }
}

Line::Line(const Point _p1_, const Point _p2_) {
    endPoints_ = std::set<Point> { _p1_, _p2_ };
    length_ = Point::distance(_p1_, _p2_);
    if (_p1_.x() == _p2_.x()) {
        angle_ = Angle(M_PI / 2);
    }
    else if (_p1_.y() == _p2_.y()) {
        angle_ = Angle(0);
    }
    else {
        double rise = _p1_.y() - _p2_.y();
        double run = _p1_.x() - _p2_.x();
        angle_ = Angle(atan(rise / run));
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
    Point A, B;
    for (auto endPoint : endPoints_) {
        if (endPoints_.count(A) == 0) {
            A = endPoint;
        }
        else {
            B = endPoint;
        }
    }
    if (lies_between(A.x(), B.x(), _point_.x())) {
        return (this->angle() == Line(_point_, A).angle());
    }
    else {
        return false;
    }
}

Point* Line::intersects(const Line _other_) const {
    Point A, B, C, D;
    for (auto endPoint : endPoints_) {
        if (endPoints_.count(A) == 0) {
            A = endPoint;
        }
        else {
            B = endPoint;
        }
    }
    for (auto endPoint : _other_.endPoints_) {
        if (endPoints_.count(C) == 0) {
            C = endPoint;
        }
        else {
            D = endPoint;
        }
    }
    Point* result = NULL;
    double xDiff = A.x() - B.x(); 
    double xDiffOther = C.x() - D.x();
    double yDiff = A.y() - B.y();
    double yDiffOther = C.y() - D.y();
    double div = (xDiff * yDiffOther) - (yDiff * xDiffOther);
    if (div == 0)
        return result;
    else {
    }
}

Point* Line::formsPath(const Line _other_) const {
    Point A, B, C, D;
    for (auto endPoint : endPoints_) {
        if (endPoints_.count(A) == 0) {
            A = endPoint;
        }
        else {
            B = endPoint;
        }
    }
    for (auto endPoint : _other_.endPoints_) {
        if (endPoints_.count(C) == 0) {
            C = endPoint;
        }
        else {
            D = endPoint;
        }
    }
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

std::set<Point> Line::endPoints() const {
    return endPoints_;
}

double Line::length() const {
    return length_;
}

Angle Line::angle() const {
    return angle_;
}
