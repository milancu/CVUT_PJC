//
// Created by Milan on 18.12.2021.
//
#include "Matrix.hpp"
#include "Fraction.hpp"
#include "tests/catch.hpp"
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <thread>

void Matrix::swap(int row1, int row2) {
    std::swap(values[row1], values[row2]);
}

long double Matrix::compute() {
//    Fraction determinant = {1, 1};
    long double determinant = 1;
    int i = 0;
    for (const auto &row: values) {
        determinant = determinant * row[i];
        i++;
    }
    return determinant;
}

Matrix::Matrix(const std::vector<std::vector<long double>> &inputValues) : dimension(inputValues.size()) {
    values = inputValues;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {


    int *sizeOfValuesInColumn = new int[matrix.dimension];


    for (int i = 0; i < matrix.dimension; i++) {
        sizeOfValuesInColumn[i] = (matrixHelper::getSizeofTheBigestValue(matrix, i));
    }

    for (const auto &row: matrix.values) {

        os << "|";

        int i = 0;
        for (const auto &value: row) {
            os << std::fixed << std::setw(sizeOfValuesInColumn[i]) << value << " ";
        }

        os << "|" << std::endl;
    }
    delete[] sizeOfValuesInColumn;
    return os;
}

const std::vector<std::vector<long double>> &Matrix::getValues() const {
    return values;
}

void printHelper(const std::vector<std::vector<long double>> &inputValues) {
    int i = 0;
    for (const auto &row: inputValues) {
        std::cout << "|";
        for (const auto &value: row) {
            std::cout << std::fixed << std::setw(3) << value << " ";
            i++;
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "\n" << std::endl;
}


void Matrix::gaus_elimination() {
    for (int i = 0; i < values.size() - 1; i++) {
        for (int j = i + 1; j < values.size(); j++) {
            if (values.at(i).at(i) == 0) {
                throw ("NaN");
            }
//            Fraction ratio = values.at(j).at(i) / values.at(i).at(i);
            long double ratio = values.at(j).at(i) / values.at(i).at(i);
//            ratio.simplify();
            for (int k = i; k < values.size(); k++) {
                values.at(j).at(k) = values.at(j).at(k) - (ratio * values.at(i).at(k));
//                values.at(j).at(k).simplify();
            }
        }
//        printHelper(values);
    }
}


void Matrix::editRow(std::vector<long double> &base, std::vector<long double> &to_change, unsigned long position) {
//    Fraction ratio = to_change.at(position - 1) / base.at(position - 1);
    long double ratio = to_change.at(position - 1) / base.at(position - 1);
//    ratio.simplify();
    bool first = true;
    for (unsigned long i = position - 1; i < base.size(); ++i) {
        if (first) {
//            to_change.at(i) = {0, 1};
            to_change.at(i) = 0;
            first = false;
        } else {
            to_change.at(i) = to_change.at(i) - (ratio * base.at(i));
//            to_change.at(i).simplify();
        }
    }
}


void Matrix::thread_editRow(std::vector<std::vector<long double>> &matrix, int from, int to, unsigned long position) {
    for (int i = from; i < to + 1; ++i) {
        editRow(matrix.at(position - 1), matrix.at(static_cast<unsigned long>(i)), position);
    }
}

void Matrix::gaus_eliminationParralel() {
    if (values.size() < 10) {
        gaus_elimination();
    } else {
        unsigned position = 1;
        while (position != values.size()) {
//            printHelper(values);
            unsigned long count = values.size() - position;
            if (count % 2 == 0) {
                std::thread t1(thread_editRow, std::ref(values), position, (count / 2) + (position - 1), position);
                std::thread t2(thread_editRow, std::ref(values), (count / 2) + 1 + (position - 1),
                               count + (position - 1), position);
                t1.join();
                t2.join();
            } else {
                std::thread t1(thread_editRow, std::ref(values), position, (count / 2) + (position - 1), position);
                std::thread t2(thread_editRow, std::ref(values), (count / 2) + 1 + (position - 1),
                               count + (position - 1) - 1, position);
                t1.join();
                t2.join();
                editRow(values.at(position - 1), values.at(count + (position - 1)), position);
            }
            position++;
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

void Matrix::changeValue(int x, int y, int newValue) {
    values.at(x).at(y) = newValue;
}



