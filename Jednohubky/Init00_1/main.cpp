#include <sstream>
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void write_stats(std::vector<double> const& data, std::ostream& out) {
    double min = numeric_limits<double>::infinity();
    double max = - numeric_limits<double>::infinity();
    double mean;
    for(double x : data){
        if (x < min){
            min = x;
        }
        if (x > max){
            max = x;
        }
    }
    cout << min << endl;
    cout << max << endl;
}

int main(){
    std::stringstream sstr;
    write_stats({ 1, 2, 3, 4, 5 }, sstr);
}
