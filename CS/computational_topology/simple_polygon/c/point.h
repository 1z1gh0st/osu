#ifndef POINT_H
#define POINT_H

class Point {
    public:

        /* Constructors */
        Point();
        Point(const double _x_, const double _y_);

        /* Operators */
        bool operator==(const Point _other_) const;
        bool operator!=(const Point _other_) const;

        bool operator<(const Point _other_) const;
        bool operator>(const Point _other_) const;
        bool operator<=(const Point _other_) const;
        bool operator>=(const Point _other_) const;

        /* Getters */
        double x() const;
        double y() const;
        double norm() const;

        /* Setters */
        void setX(double _x_); 
        void setY(double _y_);

        /* Other */
        double distance(const Point _other_) const;
        static double distance(const Point _p1_, const Point _p2_);

    private:
        double x_;
        double y_;

        double norm_;
        void updateNorm();
};

#endif
