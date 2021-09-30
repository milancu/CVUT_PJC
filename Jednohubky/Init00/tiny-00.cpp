#include "tiny-00.hpp"
#include <algorithm>
#include <ostream>
#include <iomanip>

using namespace std;

void write_stats(vector<double> const& data, ostream& out) {
    double min = numeric_limits<double>::infinity();
    double max = - numeric_limits<double>::infinity();

    for (double x : data) {
        if (min > x){min = x;}
        if (max < x){max = x;}
    }

    double sum = 0;

    for (double y : data) {sum += y;}

    out << setprecision(2) << fixed <<"min: "<< min <<'\n'<<"max: "<< max <<'\n'<<"mean: "<< sum/data.size() << endl;
}

