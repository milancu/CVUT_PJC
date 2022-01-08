#include <fstream>
#include "catch.hpp"
#include "../matrixHelper.hpp"
#include "../fileReader.hpp"


TEST_CASE("basic matrix") {

    std::vector<std::vector<Fraction>> values;

    std::fstream inFile;
    inFile.open("../files/3.txt");

    std::vector<Fraction> vectorHelper = fileReader::readMatrixFromFile(inFile);
    values = fileReader::fillVector(vectorHelper, matrixHelper::getDimension(vectorHelper.size()));
    inFile.close();

    Matrix matrix = Matrix(values);
    matrix.gaus_elimination();

    Fraction expected = {-47, 1};

    SECTION("determimant"){
        auto result = matrix.compute();
        result.simplify();


        REQUIRE(expected == result);
    }
}