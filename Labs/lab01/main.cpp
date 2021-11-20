#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    cout << "Napis 5 cisel.\n";
    for (int i = 0; i < 5; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    cout << "Cisla byla: \n";
    for (int number:numbers) {
        cout << number << '\n';
    }
}
