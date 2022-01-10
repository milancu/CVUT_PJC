//
// Created by Milan on 18.12.2021.
//
#ifndef VYPOCET_DETERMINANTU_MATRIX_HPP
#define VYPOCET_DETERMINANTU_MATRIX_HPP

#include <vector>
#include <ostream>
#include "Fraction.hpp"

class Matrix {
public:
    explicit Matrix(const std::vector<std::vector<long double>>& inputValues);

    ~Matrix() = default;

    void swap(int row1, int row2);

    void simplify();

    long double compute();

    void changeValue(int x, int y, int newValue);

    void gaus_elimination();

    void gaus_eliminationParralel();

    static void editRow(std::vector<long double> &base, std::vector<long double> &to_change, unsigned long position);

    static void thread_editRow(std::vector<std::vector<long double>>& matrix, int from, int to, unsigned long position);

    const std::vector<std::vector<long double>> &getValues() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);


    int getDimension() const;

private:
    std::vector<std::vector<long double>> values;
    int dimension;
};

#endif
