//
// Created by Milan on 24.12.2021.
//

#include "Fraction.hpp"

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numeratorToSet) {
    Fraction::numerator = numeratorToSet;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominatorToSet) {
    Fraction::denominator = denominatorToSet;
}

Fraction operator+(const Fraction &rhs, const Fraction &lhs) {
    if (rhs.denominator == lhs.denominator) {
        return {rhs.numerator + lhs.numerator, lhs.denominator};
    } else {
        auto rhsHelper = rhs * lhs.denominator;
        auto lhsHelper = lhs * rhs.denominator;
        return {rhsHelper.numerator + lhsHelper.numerator, lhsHelper.denominator};
    }
}

Fraction operator-(const Fraction &rhs, const Fraction &lhs) {
    if (rhs.denominator == lhs.denominator) {
        return {rhs.numerator - lhs.numerator, lhs.denominator};
    } else {
        auto rhsHelper = rhs * lhs.denominator;
        auto lhsHelper = lhs * rhs.denominator;
        return {rhsHelper.numerator - lhsHelper.numerator, lhsHelper.denominator};
    }
}

Fraction operator*(const Fraction &rhs, int value) {
    return {rhs.numerator * value, rhs.denominator * value};
}

Fraction operator*(const Fraction &rhs, const Fraction &lhs) {
    return {rhs.numerator * lhs.numerator, rhs.denominator * lhs.denominator};
}

void Fraction::simplify() {
    int divider = gcd(this->numerator, this->denominator);
    this->numerator = this->numerator / divider;
    this->denominator = this->denominator / divider;
}

int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    if (a > b) return gcd(a - b, b);

    return gcd(a, b - a);
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    return os << fraction.numerator / fraction.denominator;
}

Fraction operator/(const Fraction &rhs, const Fraction &lhs) {
    return {rhs.numerator * lhs.denominator, rhs.denominator * lhs.numerator};
}

bool Fraction::operator==(const int &rhs) const {
    return this->numerator/this->denominator == rhs;
}

bool Fraction::operator!=(const int &rhs) const {
    return this->numerator/this->denominator != rhs;
}






