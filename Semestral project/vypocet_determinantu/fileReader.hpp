//
// Created by Milan on 18.12.2021.
//
#ifndef VYPOCET_DETERMINANTU_FILEREADER_HPP
#define VYPOCET_DETERMINANTU_FILEREADER_HPP

#include <iostream>
#include <vector>
#include "Fraction.hpp"

namespace fileReader {

    std::vector<long double> readMatrixFromFile(std::fstream &inputFile) {

        if (!inputFile) {
            std::cout << "Failed to open data file!\n";
            exit(1);
        }

        std::vector<long double> result;
        int value = 0;

        while (inputFile >> value) {
//            result.emplace_back(value, 1);
            result.push_back(value);
        }
        return result;
    }

    std::vector<std::vector<long double>> fillVector(std::vector<long double> &values, int dimensions) {
        std::vector<std::vector<long double>> result;
        std::vector<long double> subVector;
        for (int i = 0; i < values.size(); i++) {
            subVector.push_back(values.at(i));
            if ((i + 1) % dimensions == 0) {
                result.push_back(subVector);
                subVector.clear();
            }
        }
        return result;
    }
}


#endif