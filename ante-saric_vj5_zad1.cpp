#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
using namespace std;

class Karta {
public:
    int broj;
    string zog;
    Karta(int b, string z) : broj(b), zog(z) {}
    string naziv() const {
        static map<int, string> imena = {
            {1, "As"}, {2, "Duja"}, {3, "Trica"}, {4, "Cetvorka"},
            {5, "Petica"}, {6, "Sestica"}, {7, "Sedmica"},
            {8, "Fanta"}, {9, "Kaval"}, {10, "Kralj"}
        };
        return imena[broj] + " od " + zog;
    }
};

class Mac {
public:
    vector<Karta> karte;
    Mac() {
        vector<string> zogovi = { "bastoni", "dinari", "spade", "coppe" };
        for (auto& z : zogovi)
            for (int b = 1; b <= 10; b++)
                karte.emplace_back(b, z);
    }
    void promijesaj() {
        srand(time(nullptr));
        shuffle(karte.begin(), karte.end(), default_random_engine(rand()));
    }
    vector<vector<Karta>> podijeli(int n) {
        vector<vector<Karta>> podjela(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 10; j++)
                podjela[i].push_back(karte[i * 10 + j]);
        return podjela;
    }
};

class Igrac {
public:
    string ime;
    vector<Karta> karte;
    int bodovi = 0;
    Igrac(string i, vector<Karta> k) : ime(i), karte(k) {}
    void provjeriAkuzu() {
        map<string, vector<int>> poZogu;
        map<int, int> brojIstih;
        for (auto& k : karte) {
            poZogu[k.zog].push_back(k.broj);
            brojIstih[k.broj]++;
        }
        for (auto& p : poZogu) {
            bool ima1 = false, ima2 = false, ima3 = false;
            for (int x : p.second) {
                if (x == 1) ima1 = true;
                if (x == 2) ima2 = true;
                if (x == 3) ima3 = true;
            }
            if (ima1 && ima2 && ima3) bodovi += 3;
        }
        for (int broj : {1, 2, 3}) {
            if (brojIstih[broj] == 3) bodovi += 3;
            else if (brojIstih[broj] == 4) bodovi += 4;
        }
    }
    void ispisiKarte() {
        cout << "Karte igraca " << ime << ":\n";
        for (auto& k : karte)
            cout << "  - " << k.naziv() << "\n";
    }
};

int main() {
    int brojIgraca;
    cout << "Unesite broj igraca (2 ili 4): ";
    cin >> brojIgraca;
    if (brojIgraca != 2 && brojIgraca != 4) {
        cout << "Mora biti 2 ili 4 igraca!\n";
        return 0;
    }

    vector<Igrac> igraci;
    for (int i = 0; i < brojIgraca; i++) {
        string ime;
        cout << "Unesite ime igraca " << i + 1 << ": ";
        cin >> ime;
        igraci.push_back(Igrac(ime, {}));
    }

    Mac mac;
    mac.promijesaj();
    auto podjela = mac.podijeli(brojIgraca);

    for (int i = 0; i < brojIgraca; i++) {
        igraci[i].karte = podjela[i];
        igraci[i].provjeriAkuzu();
    }

    cout << "\n------------------------------\n";
    cout << "Rezultati akuze:\n";
    cout << "------------------------------\n";

    for (auto& ig : igraci) {
        cout << ig.ime << " ima " << ig.bodovi << " bodova iz akuze.\n";
        ig.ispisiKarte();
        cout << "------------------------------\n";
    }

    return 0;
}
