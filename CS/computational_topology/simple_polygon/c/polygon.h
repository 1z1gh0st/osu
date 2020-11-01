#ifndef POLYGON_H
#define POLYGON_H

#include "line.h"
#include <vector>

class Polygon {
    public:
        Polygon(const Point _p1_, const Point _p2_, const Point _p3_);
        Polygon(const Line _l1_, const Line _l2_, const Line _l3_);

        bool hasPoint(const Point _point_) const;
        bool hasLine(const Line _line_) const;
        void addPoint(const Point _point_) const;

        bool liesWithin(const Point _point_) const;

        int countVertices();
        int countEdges();

        double area();

    private:
        std::unordered_set<Point> vertices;
        std::vector<Line> edges;
        int v_;
        int e_;
        double area_;
};

#endif
