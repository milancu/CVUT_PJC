//
// Created by Milan on 24.12.2021.
//
#ifndef VYPOCET_DETERMINANTU_FRACTION_HPP
#define VYPOCET_DETERMINANTU_FRACTION_HPP

#include <ostream>

class Fraction {
    long long int numerator;
    long long int denominator;

public:
    Fraction(long long int numerator, long long int denominator);

    long long int getNumerator() const;

    void setNumerator(long long int numerator);

    long long int getDenominator() const;

    void setDenominator(long long int enominator);

    void simplify();

    int toInt() const;

    static Fraction absoluteFraction(const Fraction &rhs);

    friend Fraction operator+(const Fraction &rhs, const Fraction &lhs);

    friend Fraction operator-(const Fraction &rhs, const Fraction &lhs);

    friend Fraction operator/(const Fraction &rhs, const Fraction &lhs);

    friend Fraction operator*(const Fraction &rhs, int value);

    friend Fraction operator*(const Fraction &rhs, const Fraction &lhs);

    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

    friend bool operator==(const Fraction &rhs, const Fraction &lhs);

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

#endif
