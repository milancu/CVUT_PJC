//
// Created by Milan on 18.12.2021.
//
#include "Matrix.hpp"
#include "Fraction.hpp"
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

    std::vector<int> sizeOfValuesInColumn{matrix.dimension, 0};

//    for (int i = 0; i < matrix.dimension; i++) {
//        sizeOfValuesInColumn[i] = (matrixHelper::getSizeofTheBigestValue(matrix, i));
//    }

    for (const auto &row: matrix.values) {

        os << "|";

        int i = 0;
        for (const auto &value: row) {
//            os << std::fixed << std::setw(sizeOfValuesInColumn[i]) << value << " ";
            os << std::fixed << std::setw(3) << value << " ";
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
        simplify();
        if (values.at(i - 1).at(i - 1) == 0) {
            std::cerr << "Mathematical Error!";
            exit(0);
        }
        for (int j = i; j < dimension; j++) {
            Fraction ratio = values.at(j).at(i - 1) / values.at(i - 1).at(i - 1);

            std::cout << "  ";
            for (auto &value: values.at(i - 1)) {
                std::cout << std::fixed << std::setw(5) << value << " ";
            }
            std::cout << " *" << ratio << std::endl;
            std::cout << " -";
            for (auto &value: values.at(j)) {
                std::cout << std::fixed << std::setw(5) << value << " ";
            }

            std::cout << '\n';
            for (auto &value: values.at(j)) {
                std::cout << std::fixed << std::setw(5) << "--------";
            }
            std::cout << '\n';
            std::cout << "  ";

            for (int k = 0; k < dimension; k++) {
                values.at(j).at(k) = values.at(j).at(k) - ratio * values.at(i - 1).at(k);
                 std::cout << std::fixed << std::setw(5) << values.at(j).at(k) << " ";
            }

            std::cout << '\n';
            std::cout << '\n';
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

int Matrix::getDimension() const {
    return dimension;
}



