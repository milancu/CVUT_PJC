//
// Created by Milan on 18.12.2021.
//

#include <iostream>
#include <vector>

#ifndef VYPOCET_DETERMINANTU_FILEREADER_HPP
#define VYPOCET_DETERMINANTU_FILEREADER_HPP

#endif //VYPOCET_DETERMINANTU_FILEREADER_HPP

namespace fileReader {

    std::vector<int> readMatrixFromFile(std::fstream &inputFile) {

        if (!inputFile) {
            std::cout << "Failed to open data file!\n";
            exit(1);
        }

        std::vector<int> result;
        int value = 0;

        while (inputFile >> value) {
            result.push_back(value);
        }
        return result;
    }

    std::vector<std::vector<int>> fillVector(std::vector<int> &values, int dimensions) {
        std::vector<std::vector<int>> result;
        std::vector<int> subVector;
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
