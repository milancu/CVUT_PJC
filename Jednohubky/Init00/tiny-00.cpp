#include "tiny-00.hpp"
#include <sstream>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

void write_stats(std::vector<double> const& data, std::ostream& out) {
    double min;
    double max;
    double mean;
//    for(double x : data){
//        cout << x << endl;
//    }
    out << "cau" << endl;
}

int main(){
    std::stringstream sstr;
    write_stats({ 1, 2, 3, 4, 5 }, sstr);
}
