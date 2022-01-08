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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Fraction::simplify() {
    int divider = gcd(this->numerator, this->denominator);
    this->numerator = this->numerator / divider;
    this->denominator = this->denominator / divider;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    if (fraction.denominator == 1) {
        return os << fraction.numerator;
    } else if (fraction.numerator == 0) {
        return os << 0;
    }
    return os << fraction.numerator << "/" << fraction.denominator;
}

Fraction operator/(const Fraction &rhs, const Fraction &lhs) {
    return {rhs.numerator * lhs.denominator, rhs.denominator * lhs.numerator};
}

bool Fraction::operator==(const int &rhs) const {
    return this->numerator / this->denominator == rhs;
}

bool Fraction::operator!=(const int &rhs) const {
    return this->numerator / this->denominator != rhs;
}

bool Fraction::operator<(const int &rhs) const {
    return this->numerator / this->denominator < rhs;
}

bool Fraction::operator>(const int &rhs) const {
    return this->numerator / this->denominator > rhs;
}

bool Fraction::operator<=(const int &rhs) const {
    return this->numerator / this->denominator <= rhs;
}

bool Fraction::operator>=(const int &rhs) const {
    return this->numerator / this->denominator >= rhs;
}

bool Fraction::operator<(const Fraction &rhs) const {
    return numerator / denominator < rhs.numerator / rhs.denominator;
}

bool Fraction::operator>(const Fraction &rhs) const {
    return numerator / denominator > rhs.numerator / rhs.denominator;
}

bool Fraction::operator<=(const Fraction &rhs) const {
    return numerator / denominator <= rhs.numerator / rhs.denominator;
}

bool Fraction::operator>=(const Fraction &rhs) const {
    return numerator / denominator >= rhs.numerator / rhs.denominator;
}


Fraction Fraction::absoluteFraction(const Fraction &rhs) {
    return {abs(rhs.numerator), rhs.denominator};
}

int Fraction::toInt() const {
    return numerator / denominator;
}

bool operator==(const Fraction &rhs, const Fraction &lhs) {
    return rhs.numerator == lhs.numerator && rhs.denominator == lhs.denominator;
}






