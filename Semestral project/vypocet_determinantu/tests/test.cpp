#include <fstream>
#include "catch.hpp"
#include "../matrixHelper.hpp"
#include "../fileReader.hpp"


TEST_CASE("basic matrix") {

    SECTION("determimant"){

        std::vector<std::vector<long double>> values;

        std::fstream inFile;
        inFile.open("../files/3.txt");

        std::vector<long double> vectorHelper = fileReader::readMatrixFromFile(inFile);
        values = fileReader::fillVector(vectorHelper, matrixHelper::getDimension(vectorHelper.size()));
        inFile.close();

        Matrix matrix = Matrix(values);
        matrix.gaus_elimination();

        long double expected = -47;

        auto result = matrix.compute();


        REQUIRE(expected == result);
    }

    SECTION("determimant1"){

        std::vector<std::vector<long double>> values;

        std::fstream inFile;
        inFile.open("../files/5.txt");

        std::vector<long double> vectorHelper = fileReader::readMatrixFromFile(inFile);
        values = fileReader::fillVector(vectorHelper, matrixHelper::getDimension(vectorHelper.size()));
        inFile.close();

        Matrix matrix = Matrix(values);
        matrix.gaus_elimination();

        long double expected = -1097414;

        auto result = matrix.compute();


        REQUIRE(expected == result);
    }
}