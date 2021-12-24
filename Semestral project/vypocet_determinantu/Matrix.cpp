//
// Created by Milan on 18.12.2021.
//

#include "Matrix.hpp"
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

void Matrix::swap(int row1, int row2) {
    std::swap(values[row1], values[row2]);
}

int Matrix::compute() {
    int determinant = 1;
    int i = 0;
    for (const auto &row: values) {
        determinant = determinant * row[i];
        i++;
    }
    return determinant;
}

void Matrix::simplify() {

}

Matrix::Matrix(const std::vector<std::vector<int>> &inputValues) : dimension(inputValues.size()) {
    values = inputValues;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {

    std::vector<int> sizeOfValuesInColumn(matrix.dimension, 0);

    for (const auto &row: matrix.values) {

        os << "|";

        int i = 0;
        for (const auto &value: row) {
            if (sizeOfValuesInColumn[i] == 0) {
                sizeOfValuesInColumn[i] = matrixHelper::getSizeofTheBigestValue(matrix, i) + 1;
            }
            os << std::fixed << std::setw(sizeOfValuesInColumn[i]) << value << " ";
            i++;
        }

        os << "|" << std::endl;
    }

    return os;
}

const std::vector<std::vector<int>> &Matrix::getValues() const {
    return values;
}

void Matrix::gaus_elimination() {

}



