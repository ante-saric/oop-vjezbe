#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
void sortt(T arr[], size_t n, bool (*cmp)(T, T)) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (cmp(arr[i], arr[j])) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename T>
void ispisi(T arr[], size_t n) {
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

inline bool ascendingInt(int a, int b) { return a > b; }
inline bool descendingInt(int a, int b) { return a < b; }

inline bool ascendingDouble(double a, double b) { return a > b; }
inline bool descendingDouble(double a, double b) { return a < b; }

int main() {
    int niz1[] = { 4, 1, 8, 3, 2 };
    double niz2[] = { 2.5, 0.7, 4.3, 1.1, 3.9 };

    size_t n1 = sizeof(niz1) / sizeof(niz1[0]);
    size_t n2 = sizeof(niz2) / sizeof(niz2[0]);

    cout << "Int niz (pocetno): ";
    ispisi(niz1, n1);

    sortt(niz1, n1, ascendingInt);
    cout << "Uzlazno: ";
    ispisi(niz1, n1);

    sortt(niz1, n1, descendingInt);
    cout << "Silazno: ";
    ispisi(niz1, n1);

    cout << "\nDouble niz (pocetno): ";
    ispisi(niz2, n2);

    sortt(niz2, n2, ascendingDouble);
    cout << "Uzlazno: ";
    ispisi(niz2, n2);

    sortt(niz2, n2, descendingDouble);
    cout << "Silazno: ";
    ispisi(niz2, n2);

    return 0;
}
