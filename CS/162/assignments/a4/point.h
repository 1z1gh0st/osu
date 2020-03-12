#ifndef POINT_H
#define POINT_H

class Point {
    private:
        int x;
        int y;
    public:
        Point();
        Point(int, int);
        void operator=(const Point &);
        bool operator==(const Point &);
        int get_x() const;
        int get_y() const;
        void set_x(int);
        void set_y(int);
        bool in_range(int, int);
};

#endif