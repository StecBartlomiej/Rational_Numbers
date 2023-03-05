#include "rational.hpp"

Rational::Rational(int numerator, int denominator) : numer_{numerator}, denom_{denominator}
{}

Rational::Rational(const Rational &copy)
{
    this->numer_ = copy.numer_;
    this->denom_ = copy.denom_;
}

Rational &Rational::operator=(const Rational &other)
{
    if (this != &other)
    {
        this->numer_ = other.numer_;
        this->denom_ = other.denom_;
    }
    return *this;
}

Rational &Rational::operator=(int i)
{
    this->numer_ = i;
    this->denom_ = 1;
    return *this;
}

Rational Rational::normalize(const Rational &other)
{
    // Algorytm Euklidesa (Euclidean algorithm)
    int a = abs(other.numer_);
    int b = abs(other.denom_);
    int c;
    if (b != 1)
    {
        while (b != 0)
        {
            c = a % b;
            a = a / b;
            b = b / c;
        }
    }
    return Rational(other.numer_ / a, other.denom_ / a);
}

Rational Rational::normalized(int numerator, int denominator)
{
    int a = abs(numerator);
    int b = abs(denominator);
    int c;
    if (b != 1)
    {
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }
    }
    return Rational(numerator / a, denominator / a);
}

Rational Rational::operator+(const Rational &other) const
{
    int x = other.numer_;
    int y = other.denom_;
    if (this != &other)
    {
        x *= this->denom_;
        y *= this->denom_;
    }
    return normalized((this->numer_ * other.denom_) + x, y);
}


Rational Rational::operator-(const Rational &other) const
{
    int x = other.numer_;
    int y = other.denom_;
    if (this != &other)
    {
        x *= this->denom_;
        y *= this->denom_;
    }
    return normalized((this->numer_ * other.denom_) - x, y);
}

Rational Rational::operator*(const Rational &other) const
{
    return normalized(this->numer_ * other.numer_, this->denom_ * other.denom_);
}

Rational Rational::operator/(const Rational &other) const
{
    return normalized(this->numer_ * other.denom_, this->denom_ * other.numer_);
}

Rational Rational::operator+() const
{
    return *this;
}

Rational Rational::operator-() const
{
    return {this->numer_ * -1, this->denom_};
}

bool Rational::operator==(const Rational &other) const
{
    if ((this->numer_ * other.denom_) == (other.numer_ * this->denom_))
        return true;
    return false;
}

bool Rational::operator!=(const Rational &other) const
{
    return !(*this == other);
}

bool Rational::operator>=(const Rational &other) const
{
    if ((this->numer_ * other.denom_) >= (other.numer_ * this->denom_))
        return true;
    return false;
}

bool Rational::operator<=(const Rational &other) const
{
    if ((this->numer_ * other.denom_) <= (other.numer_ * this->denom_))
        return true;
    return false;
}

bool Rational::operator>(const Rational &other) const
{
    if ((this->numer_ * other.denom_) > (other.numer_ * this->denom_))
        return true;
    return false;
}

bool Rational::operator<(const Rational &other) const
{
    if ((this->numer_ * other.denom_) < (other.numer_ * this->denom_))
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << "(" << r.numer_ << "/" << r.denom_ << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Rational &r)
{
    std::cout << "Numerator = ";
    is >> r.numer_;
    std::cout << "Denominator = ";
    is >> r.denom_;
    return is;
}

Rational operator+(const Rational &r, int i)
{
    int x = r.numerator();
    int y = r.denominator();
    x += i * y;
    return Rational::normalized(x, y);
}

Rational operator+(int i, const Rational &r)
{
    int x = r.numerator();
    int y = r.denominator();
    x += i * y;
    return Rational::normalized(x, y);
}

Rational operator-(const Rational &r, int i)
{
    int x = r.numerator();
    int y = r.denominator();
    x -= i * y;
    return Rational::normalized(x, y);
}

Rational operator-(int i, const Rational &r)
{
    int x = r.numerator();
    int y = r.denominator();
    x -= i * y;
    return Rational::normalized(x, y);
}

Rational operator*(const Rational &r, int i)
{
    return Rational::normalized(r.numerator() * i, r.denominator());
}

Rational operator*(int i, const Rational &r)
{
    return Rational::normalized(r.numerator() * i, r.denominator());
}

Rational operator/(const Rational &r, int i)
{
    return Rational::normalized(r.numerator(), r.denominator() * i);
}

Rational operator/(int i, const Rational &r)
{
    return Rational::normalized(r.numerator(), r.denominator() * i);
}