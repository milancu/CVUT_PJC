#include <iostream>
#include <iomanip>

using namespace std;

double readDouble() {
    double d;
    cin >> d;

    if (cin.good()) {
        return d;
    } else if (cin.bad() || cin.eof()) {
        throw runtime_error("readDouble() failed");
    } else {
        cin.clear();
        cin.ignore(1, '\n');
        return readDouble();
    }
}

void hline(int W){
    for (int i = 0; i < W; ++i) {
        cout << '-';
    }
    cout << '\n';
}

int main() {
    const int W = 8;

    hline(W);
    cout << hex;
    cout << setw(W) << 255 << endl;
    cout << showbase;
    cout << setw(W) << 255 << endl;

//    double a = readDouble();
//    double b = readDouble();
//    double c = readDouble();
//
//    cout << a << ", " << b << ", " << c << endl;
//    cout << a + b + c << endl;
}

