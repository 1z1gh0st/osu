#ifndef ANGLE_H
#define ANGLE_H


class Angle {
    public:
        Angle();
        Angle(const long double _value_);

        bool operator==(const Angle _other_) const;
        bool operator!=(const Angle _other_) const;

        bool operator<(const Angle _other_) const;
        bool operator>(const Angle _other_) const;
        bool operator<=(const Angle _other_) const;
        bool operator>=(const Angle _other_) const;

        Angle &operator+(const Angle _other_);
        Angle &operator-(const Angle _other_);
        Angle &operator*(const Angle _other_);
        Angle &operator/(const Angle _other_);

        long double value() const;
        void setValue(const long double _value_);
    private:
        void modPi();
        long double value_; 
};

#endif
