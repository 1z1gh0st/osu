#ifndef LINE_H
#define LINE_H

#include <set>
#include "point.h"
#include "angle.h"

class Line {
    public:
        Line(const Point _p1_, const Point _p2_);
        
        bool operator<(const Line _other_) const;
        bool operator>(const Line _other_) const;
        bool operator<=(const Line _other_) const;
        bool operator>=(const Line _other_) const;

        bool intersects(const Point _point_) const;
        double distanceToPoint(const Point _point_) const;
        Point* intersects(const Line _other_) const;
        Point* formsPath(const Line _other_) const;

        std::set<Point> endPoints() const;
        double length() const;
        Angle angle() const;

    private:
        std::set<Point> endPoints_; 
        double length_;
        Angle angle_;
};

#endif
