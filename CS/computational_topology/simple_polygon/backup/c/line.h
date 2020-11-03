#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "angle.h"
#include <vector>

class Line {
    public:
        Line(const Point _p1_, const Point _p2_);

        bool operator==(const Line _other_) const;
        
        bool operator<(const Line _other_) const;
        bool operator>(const Line _other_) const;
        bool operator<=(const Line _other_) const;
        bool operator>=(const Line _other_) const;

        bool intersects(const Point _point_) const;
        double distanceToPoint(const Point _point_) const;
        Point* intersects(const Line _other_) const;
        Point* formsPath(const Line _other_) const;

        Point p1() const;
        Point p2() const;
        double length() const;
        Angle angle() const;
        double slope() const;
        double yIntercept() const;

    private:
        Point p1_;
        Point p2_;
        double length_;
        Angle angle_;
        double slope_;
        double yIntercept_;
};

#endif
