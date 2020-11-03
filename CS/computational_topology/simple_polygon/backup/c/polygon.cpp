#include "polygon.h"

Polygon::Polygon(const Point _p1_, const Point _p2_, const Point _p3_) {

    vertices_.insert(_p1_);
    vertices_.insert(_p2_);
    vertices_.insert(_p3_);
    vertices_.insert(_p3_);
    vertices_.insert(Point(1,-1));
    v_ = 3;
    for (auto v : vertices_) {
        printf("(%f,%f)",v.x(),v.y());
    }

    edges_.push_back(Line(_p1_, _p2_));
    edges_.push_back(Line(_p2_, _p3_));
    edges_.push_back(Line(_p3_, _p1_));
    e_ = 3;
}

Polygon::Polygon(const Line _l1_, const Line _l2_, const Line _l3_) {
    edges_.push_back(_l1_);
    edges_.push_back(_l2_);
    edges_.push_back(_l3_);
    e_ = 3;
    
    vertices_.insert(_l1_.p1());
    vertices_.insert(_l1_.p2());
    if (vertices_.count(_l2_.p1()) == 0) {
        vertices_.insert(_l2_.p1());
    }
    else {
        vertices_.insert(_l2_.p2());
    }
    v_ = 3;

}

bool Polygon::hasPoint(const Point _point_) const {
    return (vertices_.count(_point_) != 0);
}

bool Polygon::hasLine(const Line _line_) const {
    for (auto l = edges_.begin(); l != edges_.end(); ++l) {
        if (_line_ == *l) {
            return true;
        }
    }
    return false;
}

void Polygon::addPoint(const Point _point_) {
    // 1. Pick point in middle
    // ----- CENTER OF MASS --------
    vertices_.insert(_point_);
    v_++;
    double sumX = 0;
    double sumY = 0;
    for (auto p : vertices_) {
        sumX += p.x();
        sumY += p.y();
    }
    Point center = Point((sumX / v_), (sumY / v_));

    // 2. Sort all other points by angle
    // ------ SORT ------
    std::vector<Point> upperPointsSorted;
    std::vector<Point> lowerPointsSorted;
    for (auto p : vertices_) {
        printf("(%f,%f)", p.x(), p.y());
        if (p.y() >= center.y()) {
            for (auto q = upperPointsSorted.begin(); q != upperPointsSorted.end(); ++q) {  
                Line cq = Line(center, *q);
                Line cp = Line(center, p);
                if (cq.angle() == cp.angle() && cq.length() <= cp.length()) {
                    break;
                }
                else if (cq.angle() < cp.angle()) {
                    break;
                }
            }
            upperPointsSorted.push_back(p);
        }
        else {
            for (auto q = lowerPointsSorted.begin(); q != lowerPointsSorted.end(); ++q) {  
                Line cq = Line(center, *q);
                Line cp = Line(center, p);
                if (cq.angle() == cp.angle() && cq.length() <= cp.length()) {
                    break;
                }
                else if (cq.angle() < cp.angle()) {
                    break;
                }
            }
            lowerPointsSorted.push_back(p);
        }
    }
    printf("\n\n");
    for (auto p : upperPointsSorted) {
        printf("(%f,%f)", p.x(), p.y());
    }
    for (auto p : lowerPointsSorted) {
        printf("(%f,%f)", p.x(), p.y());
    }

    // 3. Draw a line in order through each point including the attachment map from end->beginning
    e_ = 0;
    edges_.clear();
    Point prev, first, last;
    for (auto curr = upperPointsSorted.begin(); curr != upperPointsSorted.end(); ++curr) {
        if (curr != upperPointsSorted.begin()) {  
            edges_.push_back(Line(prev, *curr));
            e_++;
        }
        else {
            first = *curr;
        }
        prev = *curr;
        last = prev;
    }
    for (auto curr = lowerPointsSorted.begin(); curr != lowerPointsSorted.end(); ++curr) {
        if (curr != lowerPointsSorted.begin()) {  
            edges_.push_back(Line(prev, *curr));
            e_++;
        }
        else {
            edges_.push_back(Line(last, *curr));
            e_++;
        }
        prev = *curr;
        last = prev;
    }
    edges_.push_back(Line(first, last));
    e_++;
}

int Polygon::countVertices() const {
    return v_;
}

int Polygon::countEdges() const {
    return e_;
}

void Polygon::print() const {
    for (auto edge = edges_.begin(); edge != edges_.end(); ++edge) {
        printf("(%f,%f)->(%f,%f)\n", edge->p1().x(), edge->p1().y(), edge->p2().x(), edge->p2().y());
    }
    printf("\n\n");
}
