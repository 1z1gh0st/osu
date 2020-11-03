#include "angle.h"
#include <cmath>

Angle::Angle() {
    value_ = 0;
}

Angle::Angle(const long double _value_) {
    value_ = _value_;
    modPi();
}

bool Angle::operator==(const Angle _other_) const {
    return value_ == _other_.value_;
}

bool Angle::operator!=(const Angle _other_) const {
    return !(*this == _other_);
}

bool Angle::operator<(const Angle _other_) const {
    return value_ < _other_.value_;
}

bool Angle::operator>(const Angle _other_) const {
    return value_ > _other_.value_;
}

bool Angle::operator<=(const Angle _other_) const {
    return value_ <= _other_.value_;
}

bool Angle::operator>=(const Angle _other_) const {
    return value_ <= _other_.value_;
}

Angle& Angle::operator+(const Angle _other_) {
    value_ += _other_.value_;
    modPi();
    return *this;
}

Angle& Angle::operator-(const Angle _other_) {
    value_ -= _other_.value_;
    modPi();
    return *this;
}

Angle& Angle::operator*(const Angle _other_) {
    value_ *= _other_.value_;
    modPi();
    return *this;
}

Angle& Angle::operator/(const Angle _other_) {
    value_ /= _other_.value_;
    modPi();
    return *this;
}

long double Angle::value() const {
    return value_;
}

void Angle::setValue(const long double _value_) {
    value_ = _value_;
    modPi();
}

void Angle::modPi() {
    while (value_ >= M_PI) {
        value_ -= M_PI;
    }
    while (value_ < 0) {
        value_ += M_PI;
    }
}

