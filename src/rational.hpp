#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include "iostream"

class Rational
{
public:
    Rational(int numerator, int denominator = 1);
    Rational(const Rational& copy);
    ~Rational() = default;

    Rational& operator=(const Rational& other);
    Rational& operator=(int i);

    int numerator() const { return numer_; }
    int denominator() const { return denom_; }

    static Rational normalize(const Rational& other);
    static Rational normalized(int numerator, int denominator);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    Rational operator+() const;
    Rational operator-() const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;

private:
    friend std::ostream& operator<<(std::ostream &, const Rational &);
    friend std::istream& operator>>(std::istream &, Rational &);

private:
    int numer_;
    int denom_;
};

Rational operator+(const Rational& r, int i);
Rational operator+(int i, const Rational& r);

Rational operator-(const Rational& r, int i);
Rational operator-(int i, const Rational& r);

Rational operator*(const Rational& r, int i);
Rational operator*(int i, const Rational& r);

Rational operator/(const Rational& r, int i);
Rational operator/(int i, const Rational& r);

#endif //RATIONAL_HPP