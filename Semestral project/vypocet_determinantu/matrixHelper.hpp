//
// Created by Milan on 18.12.2021.
//

#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include "Matrix.hpp"

#ifndef VYPOCET_DETERMINANTU_MATRIXHELPER_HPP
#define VYPOCET_DETERMINANTU_MATRIXHELPER_HPP

#endif //VYPOCET_DETERMINANTU_MATRIXHELPER_HPP

namespace matrixHelper {
    bool isMatrixValid(int size) {
        return std::floor((float) (sqrt(size))) == (float) (sqrt(size));
    }

    int getDimension(int size) {
        return sqrt(size);
    }

    int getSizeofTheBigestValue(const Matrix &matrix, int column) {
        int max = *max_element(matrix.getValues().at(column).begin(), matrix.getValues().at(column).end());
        int min = abs(*min_element(matrix.getValues().at(column).begin(), matrix.getValues().at(column).end()));
        int sizeMax = log10(max);
        int sizeMin = log10(min);

        return sizeMax > sizeMin ? sizeMax + 1 : sizeMin + 1;
    }

    int get_random_int() {
        static std::mt19937 mt{std::random_device{}()};
        static std::uniform_real_distribution<> dist(-1000, 1000);
        return dist(mt);
    }

    std::vector<std::vector<int>> generateRandomValues() {
        int dimension = 5; //In future make it random, right now for testing 5 is good

        std::vector<std::vector<int>> result;
        std::vector<int> subVector;

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                int value = get_random_int();
                std::cout << value << std::endl;
                subVector.push_back(value);
            }
            result.push_back(subVector);
            subVector.clear();
        }
        return result;
    }


}
