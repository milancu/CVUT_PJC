//
// Created by Milan on 24.12.2021.
//

#ifndef VYPOCET_DETERMINANTU_FRACTION_HPP
#define VYPOCET_DETERMINANTU_FRACTION_HPP


#include <ostream>

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);

    int getNumerator() const;

    void setNumerator(int numerator);

    int getDenominator() const;

    void setDenominator(int denominator);

    void simplify();

    int toInt();

    Fraction absoluteFraction(const Fraction &rhs);

    int gcd(int a, int b);

    friend Fraction operator+(const Fraction &rhs, const Fraction &lhs);

    friend Fraction operator-(const Fraction &rhs, const Fraction &lhs);

    friend Fraction operator/(const Fraction &rhs, const Fraction &lhs);

    friend Fraction operator*(const Fraction &rhs, int value);

    friend Fraction operator*(const Fraction &rhs, const Fraction &lhs);

    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

    bool operator==(const int &rhs) const;

    bool operator!=(const int &rhs) const;

    bool operator<(const int &rhs) const;

    bool operator>(const int &rhs) const;

    bool operator<=(const int &rhs) const;

    bool operator>=(const int &rhs) const;

    bool operator<(const Fraction &rhs) const;

    bool operator>(const Fraction &rhs) const;

    bool operator<=(const Fraction &rhs) const;

    bool operator>=(const Fraction &rhs) const;
};


#endif //VYPOCET_DETERMINANTU_FRACTION_HPP
