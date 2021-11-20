#include <iostream>
#include <vector>
#include "vector.hpp"

vector get() {
    vector tmp(3, 5.1);
    tmp.push_back(4.5);
    return tmp;
}
int main() {
    vector Honza(5, 1.5);
    Honza.push_back(1.2);
    Honza.push_back(2.3);
    Honza.push_back(3.5);
    Honza.print_vector();
    Honza.at(1) = 3.14;
    Honza.at(2) += 2.7;
    Honza.print_vector();
    vector Vera = Honza;            // kopirujicii konstruktor
    std::cout << "Kopie pres konstruktor:" << std::endl;
    Vera.print_vector();
    vector Zuzana;
    std::cout << "Kopie pres prirazeni:" << std::endl;
    Zuzana = Honza;                 // kopirujicici prirazeni
    Zuzana.print_vector();
    vector Ivana = std::move(Vera); // presunujici konstruktor
    std::cout << "Presun pres kontruktor:" << std::endl;
    Ivana.print_vector();
    std::cout << "Puvodni objekt je prazdny:" << std::endl;
    Vera.print_vector();            // Vera zustala prazdna
    std::cout << "Presun pres prirazeni:" << std::endl;
    vector Ursula = get();
    Ursula.print_vector();
    Ursula[1] = 8.7;

//    Ursula = get();                 // presunujici prirazeni
//    Ursula.print_vector();
    std::cout << Ursula;
    std:: cout << sort(Ursula.begin(), Ursula.end());
    std::cout << Ursula;
    return 0;
}