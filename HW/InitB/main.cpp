#include <iostream>
using namespace std;

int factorial (int a);

int main () {
    int a = 10;
    int result;

    result = factorial(a);
    cout << "factorial is : " << result << endl;
    return 0;
}

int factorial(int a){
    if (a <= 1){
        return 1;
    } else {
        return factorial(a-1) * a;
    }
}