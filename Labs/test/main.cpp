#include <iostream>
#include <vector>


class TCosi {
    int hodnota;
    int pocet;
public:
    TCosi(int h, int p) { hodnota = h; pocet = p; }
    int getHodnota(void) { return hodnota; };
    void setHodnota(int h) { hodnota = h; };
};


int main() {
//    TCosi x(7,2);
//    std::cout << x.getHodnota();
//    x.setHodnota(8);
//    std::cout << x.getHodnota();
    int x =0;
    return (x > 50) ? 12 : "chyba";
}


