//
// Created by Milan on 18.12.2021.
//
#ifndef VYPOCET_DETERMINANTU_MATRIXHELPER_HPP
#define VYPOCET_DETERMINANTU_MATRIXHELPER_HPP

#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include "Matrix.hpp"
#include "Fraction.cpp"

namespace matrixHelper {
    bool isMatrixValid(int size) {
        return std::floor((float) (sqrt(size))) == (float) (sqrt(size));
    }

    int getDimension(int size) {
        return sqrt(size);
    }

    int numDigits(int number) {
        int count = 0;
        while (number != 0)
        {
            number = number / 10;
            ++count;
        }
        return count+2;
    }

    int getSizeofTheBigestValue(const Matrix &matrix, int column) {
        Fraction max = {-std::numeric_limits<int>::infinity(), 1};
        Fraction min = {std::numeric_limits<int>::infinity(), 1};
        for (int i = 0; i < matrix.getDimension(); i++) {
            if (matrix.getValues().at(i).at(column) > max) {
                max = matrix.getValues().at(i).at(column);
            }
            if (matrix.getValues().at(i).at(column) < min) {
                min = matrix.getValues().at(i).at(column);
            }
        }
        if (min.absoluteFraction(min) > max) {
            return numDigits(min.toInt());
        }
        return numDigits(max.toInt());
    }

    int get_random_int() {
        static std::mt19937 mt{std::random_device{}()};
        static std::uniform_real_distribution<> dist(-10, 10);
        return dist(mt);
    }

    std::vector<std::vector<Fraction>> generateRandomValues() {
        int dimension = 3; //In future make it random, right now for testing 5 is good

        std::vector<std::vector<Fraction>> result;
        std::vector<Fraction> subVector;

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                subVector.emplace_back(get_random_int(), 1);
            }
            result.push_back(subVector);
            subVector.clear();
        }
        return result;
    }
}

#endif
