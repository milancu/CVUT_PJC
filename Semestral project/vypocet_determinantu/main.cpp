#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "fileReader.hpp"
#include "matrixHelper.hpp"
#include "Matrix.hpp"
#include "Matrix.cpp"

template <typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<Fraction>> values;

    std::fstream  inFile;
    std::string fileName = "2.txt";
    std::string source = R"(files\)";
    inFile.open("D:\\Vysoka_Skola\\3.Semestr\\PJC\\Projekty\\b211_bd6b36pjc\\Semestral project\\vypocet_determinantu\\files\\4.txt");

    std::vector<Fraction> vectorHelper = fileReader::readMatrixFromFile(inFile);
    int vectorHelpersSize = vectorHelper.size();
    if (matrixHelper::isMatrixValid(vectorHelpersSize)) {
        values = fileReader::fillVector(vectorHelper, matrixHelper::getDimension(vectorHelpersSize));
    } else {
        std::cout << "Matrix is not valid!\n";
        exit(1);
    }

//    values = matrixHelper::generateRandomValues();

    Matrix matrix = Matrix(values);
    std::cout << "New Matrix created: " << '\n' << matrix << std::endl;

    std::cout << "After gaus elimination: " << std::endl;
    matrix.gaus_elimination();
    std::cout << matrix << std::endl;

    std::cout << "Determinat : " << matrix.compute() << std::endl;

//    inFile.close();



    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";
    return 0;
}
