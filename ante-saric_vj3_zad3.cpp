#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> niz = { 1, 2, 3, 4, 5, 6 };

    auto parni = [](int x) { return x % 2 == 0; };
    auto neparni = [](int x) { return x % 2 != 0; };

    auto udvostruci = [](int x) { return x * 2; };
    auto prepolovi = [](int x) { return x / 2; };

    int suma = 0, produkt = 1;
    auto dodajUSumu = [&](int x) { suma += x; };
    auto pomnoziUProdukt = [&](int x) { produkt *= x; };

    int prag = 3;
    int sumaVecih = 0;
    auto dodajAkoVeciOdPraga = [prag, &sumaVecih](int x) {
        if (x > prag) sumaVecih += x;
        };

    for (int& x : niz) {
        if (parni(x)) x = prepolovi(x);
        else x = udvostruci(x);
    }

    cout << "Niz nakon promjene: ";
    for (int x : niz) cout << x << " ";
    cout << endl;

    for (int x : niz) {
        dodajUSumu(x);
        pomnoziUProdukt(x);
    }
    cout << "Suma: " << suma << endl;
    cout << "Produkt: " << produkt << endl;

    for (int x : niz)
        dodajAkoVeciOdPraga(x);

    cout << "Suma brojeva vecih od " << prag << ": " << sumaVecih << endl;

    return 0;
}
