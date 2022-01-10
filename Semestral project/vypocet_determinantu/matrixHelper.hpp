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
        while (number != 0) {
            number = number / 10;
            ++count;
        }
        return count + 2;
    }

    int getSizeofTheBigestValue(const Matrix &matrix, int column) {
        long double max = -std::numeric_limits<int>::infinity();
        long double min = std::numeric_limits<int>::infinity();
        for (int i = 0; i < matrix.getDimension(); i++) {
            if (matrix.getValues().at(i).at(column) > max) {
                max = matrix.getValues().at(i).at(column);
            }
            if (matrix.getValues().at(i).at(column) < min) {
                min = matrix.getValues().at(i).at(column);
            }
        }
        if ((-min) > max) {
            return numDigits(min) + 9;
        }
        return numDigits(max) + 9;
    }

    int get_random_int() {
        static std::mt19937 mt{std::random_device{}()};
        static std::uniform_real_distribution<> dist(-15, 15);
        return dist(mt);
    }

    int get_random_dimension() {
        static std::mt19937 mt{std::random_device{}()};
        static std::uniform_real_distribution<> dist(200, 1000);
        return dist(mt);
    }

    std::vector<std::vector<long double>> generateRandomValues() {
        int dimension = get_random_dimension(); //In future make it random, right now for testing 5 is good

        std::vector<std::vector<long double>> result;
        std::vector<long double> subVector;

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
//                subVector.emplace_back(get_random_int(), 1);
                subVector.push_back(get_random_int());
            }
            result.push_back(subVector);
            subVector.clear();
        }
        return result;
    }
}

#endif
