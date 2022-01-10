#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "fileReader.hpp"
#include "matrixHelper.hpp"
#include "Matrix.cpp"


template<typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}

void readFromFile();

void randomChoise();

void readFromTerminal();

void printHelp(){
    std::cout << "Vitejte v kalkulacce ne determinant" << std::endl;
    std::cout << "Vyberte z moznosti, napriklad 1: " << std::endl;
    std::cout << "1 - random" << std::endl;
    std::cout << "2 - vlastní soubor " << std::endl;
    std::cout << "3 - vlastni matice z konzole" << std::endl;
    std::cout << ":";
}

int main(int argc, char *argv[]) {
    if (std::any_of(argv, argv+argc, [](std::string s) {return s.compare("--help") == 0;})) {
        printHelp();
        return 0;
    }


    std::cout << "Vitejte v kalkulacce ne determinant" << std::endl;
    std::cout << "Vyberte z moznosti, napriklad 1: " << std::endl;
    std::cout << "1 - random" << std::endl;
    std::cout << "2 - vlastní soubor " << std::endl;
    std::cout << "3 - vlastni matice z konzole" << std::endl;
    std::cout << ":";

    int input;
    std::cin >> input;

    switch (input) {
        case 1:
            randomChoise();
            break;
        case 2:
            readFromFile();
            break;
        case 3:
            readFromTerminal();
            break;
        default:
            std::cout << "Zvolili jste spatne, vypinam program..." << std::endl;
            exit(0);
    }
    return 0;
}

void readFromTerminal() {
    std::vector<std::vector<long double>> values;

    int velikostMatice;
    std::cout << "Zadejte velikost matice: " << std::endl;
    std::cin >> velikostMatice;

    std::cout << "Zadejte cisla jedno po jednom" << std::endl;

    std::vector<long double> subVector;
    for (int i = 0; i < (velikostMatice * velikostMatice); i++) {
        int v;
        std::cin >> v;
        subVector.push_back(v);
        if ((i + 1) % velikostMatice == 0) {
            values.push_back(subVector);
            subVector.clear();
        }
    }
    Matrix matrix = Matrix(values);
    std::string input = "N";
    while (input != "A") {
        std::cout << "Vase matice:\n" << matrix << std::endl;

        std::cout << "Je tahle matice podle vasich predstav? A/N" << std::endl;
        std::cin >> input;

        if (input == "A") {
            std::cout << "Zacina kalkulace determinantu.\nPockejte, bude to cvhili trvat..." << std::endl;
            auto start = std::chrono::high_resolution_clock::now();
            matrix.gaus_eliminationParralel();
            auto end = std::chrono::high_resolution_clock::now();

            long double result = matrix.compute();
            std::cout << "Determinat : " << result << std::endl;
            std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";
        } else if (input == "N") {
            std::cout << "Zadejte souradnici hodnoty, ktere chcete zmenit" << std::endl;
            size_t x;
            size_t y;
            int newValue;
            std::cout << "x: ";
            std::cin >> x;
            std::cout << "y: ";
            std::cin >> y;
            std::cout << "Zadejte novou hodnotu: ";
            std::cin >> newValue;
            matrix.changeValue(x - 1, y - 1, newValue);
        }
    }

    std::cout << "Chcete videt matici po GM? A/N: ";
    std::cin >> input;
    if(input == "A"){
        std::cout << "matice po uprave:\n" << matrix << std::endl;
    }
}

void randomChoise() {
    std::vector<std::vector<long double>> values;
    values = matrixHelper::generateRandomValues();

    Matrix matrix = Matrix(values);
//    std::cout << "New matrix:\n" << matrix << std::endl;
    std::cout << "Vytvorila se matice: " << values.size() << " X " << values.size() << " o hodnotach od -15 do 15"
              << std::endl;

    std::cout << "Zacina kalkulace determinantu.\nPockejte, bude to cvhili trvat..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    matrix.gaus_eliminationParralel();
    auto end = std::chrono::high_resolution_clock::now();

    long double result = matrix.compute();
    std::cout << "Determinat : " << result << std::endl;
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";

    std::cout << "Chcete videt matici po GM? A/N: ";
    std::string input;
    std::cin >> input;
    if(input == "A"){
        std::cout << "matice po uprave:\n" << matrix << std::endl;
    }
}

void readFromFile() {
    std::fstream inFile;
    std::string fileName;

    std::vector<std::vector<long double>> values;

    std::cerr << "!!!Zvoleny soubor musi byt ulozeny ve slozce files/" << std::endl;
    std::cout << "Zadejte nazev souboru, napriklad 5.txt" << std::endl;
    std::cin >> fileName;
    inFile.open("../files/" + fileName);

    std::vector<long double> vectorHelper = fileReader::readMatrixFromFile(inFile);
    int vectorHelpersSize = vectorHelper.size();
    if (matrixHelper::isMatrixValid(vectorHelpersSize)) {
        values = fileReader::fillVector(vectorHelper, matrixHelper::getDimension(vectorHelpersSize));
        inFile.close();
    } else {
        std::cout << "Matrix is not valid!\n";
        exit(1);
    }

    Matrix matrix = Matrix(values);
    std::cout << "New matrix:\n" << matrix << std::endl;

    std::cout << "Zacina kalkulace determinantu.\nPockejte, bude to cvhili trvat..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    matrix.gaus_eliminationParralel();
    auto end = std::chrono::high_resolution_clock::now();

    long double result = matrix.compute();
    std::cout << "Determinat : " << result << std::endl;
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";

    std::cout << "Chcete videt matici po GM? A/N: ";
    std::string input;
    std::cin >> input;
    if(input == "A"){
        std::cout << "matice po uprave:\n" << matrix << std::endl;
    }
}
