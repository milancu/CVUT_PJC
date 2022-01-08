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
    explicit Matrix(const std::vector<std::vector<Fraction>>& inputValues);

    ~Matrix() = default;

    void swap(int row1, int row2);

    void simplify();

    Fraction compute();

    void gaus_elimination();
    
    const std::vector<std::vector<Fraction>> &getValues() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);


    int getDimension() const;

private:
    std::vector<std::vector<Fraction>> values;
    int dimension;
};

#endif //VYPOCET_DETERMINANTU_MATRIX_HPP
