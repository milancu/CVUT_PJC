//
// Created by Milan on 18.12.2021.
//

#ifndef VYPOCET_DETERMINANTU_MATRIX_HPP
#define VYPOCET_DETERMINANTU_MATRIX_HPP

#include <vector>
#include <ostream>

class Matrix {
public:
    explicit Matrix(const std::vector<std::vector<int>>& inputValues);

    ~Matrix() = default;

    void swap(int row1, int row2);

    int compute();

    void gaus_elimination();

    void simplify();

    const std::vector<std::vector<int>> &getValues() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

private:
    std::vector<std::vector<int>> values;
    int dimension;
};

#endif //VYPOCET_DETERMINANTU_MATRIX_HPP
