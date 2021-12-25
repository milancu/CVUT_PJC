//
// Created by Milan on 18.12.2021.
//

#include "Matrix.hpp"
#include "Fraction.hpp"
#include "Fraction.cpp"
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

void Matrix::swap(int row1, int row2) {
    std::swap(values[row1], values[row2]);
}

Fraction Matrix::compute() {
    Fraction determinant = {1, 1};
    int i = 0;
    for (const auto &row: values) {
        determinant = determinant * row[i];
        i++;
    }
    return determinant;
}

Matrix::Matrix(const std::vector<std::vector<Fraction>> &inputValues) : dimension(inputValues.size()) {
    values = inputValues;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {

    std::vector<int> sizeOfValuesInColumn(matrix.dimension, 0);

    for (const auto &row: matrix.values) {

        os << "|";

        int i = 0;
        for (const auto &value: row) {
            os << std::fixed << value << " ";
            i++;
        }

        os << "|" << std::endl;
    }

    return os;
}

const std::vector<std::vector<Fraction>> &Matrix::getValues() const {
    return values;
}

void Matrix::gaus_elimination() {
    for (int i = 1; i < dimension; i++) {
        if (values.at(i - 1).at(i - 1) == 0) {
            std::cerr << "Mathematical Error!";
            exit(0);
        }
        for (int j = i; j < dimension; j++) {
            Fraction ratio = values.at(j).at(i - 1) / values.at(i - 1).at(i - 1);

            for (int k = 0; k < dimension; k++) {
                values.at(j).at(k) = values.at(j).at(k) - ratio * values.at(i - 1).at(k);
            }
        }
    }
}

void Matrix::simplify() {
    std::vector<int> helper(dimension, 0);

    for (int i = 0; i < dimension; i++) {
        int c = 0;
        for (int j = 0; j < dimension; j++) {
            if (values.at(i).at(j) != 0) {
                break;
            } else {
                c++;
            }
        }
        helper[i] = (c);
    }

    for (size_t i = 0; i < helper.size() - 1; ++i) {
        for (size_t j = 0; j < helper.size() - i - 1; ++j) {
            if (helper.at(j) > helper.at(j + 1)) {
                std::swap(helper.at(j), helper.at(j + 1));
                swap(j, j + 1);
            }
        }
    }
}



