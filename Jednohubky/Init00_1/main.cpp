#include <sstream>
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void write_stats(std::vector<double> const& data, std::ostream& out) {
    double min = numeric_limits<double>::infinity();
    double max = - numeric_limits<double>::infinity();
    double mean;

    for (double x : data) {
        if (min > x){
            min = x;
        }
        if (max < x){
            max = x;
        }
    }

    double sum;

    for (double x:data) {
        sum = sum + x;
    }

    mean = sum/data.size();

    out << setprecision (2) << fixed <<"min: "<<min <<"\n"<<"max: "<< max <<"\n"<<"mean: "<< mean << endl;

    cout << setprecision (2) << fixed <<"min: "<<min <<"\n"<<"max: "<< max <<"\n"<<"mean: "<< mean << endl;
}

int main(){
    std::stringstream sstr;
    write_stats({91.03, 20.76, 10.63, 74.73,  5.68,
                 24.55, 17.23, 72.42, 54.38, 75.38,
                 53.33, 43.11, 77.58, 89.91,  8.23}, sstr);
}
