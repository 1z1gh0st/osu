#ifndef POLYGON_H
#define POLYGON_H

#include "line.h"
#include <vector>
#include <set>

class Polygon {

    public:
        Polygon(const Point _p1_, const Point _p2_, const Point _p3_);
        Polygon(const Line _l1_, const Line _l2_, const Line _l3_);

        bool hasPoint(const Point _point_) const;
        bool hasLine(const Line _line_) const;
        void addPoint(const Point _point_);

        bool liesWithin(const Point _point_) const;

        int countVertices() const;
        int countEdges() const;

        void print() const;
        //double area();

    private:
        std::set<Point> vertices_;
        std::vector<Line> edges_;
        int v_;
        int e_;
        double area_;
};

#endif
