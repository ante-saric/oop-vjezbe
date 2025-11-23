#include <iostream>
#include <cstddef>
using namespace std;

inline bool ascending(int a, int b) {
    return a > b;
}

inline bool descending(int a, int b) {
    return a < b;
}

void sortt(int arr[], size_t n, bool (*cmp)(int, int)) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (cmp(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int niz[] = { 5, 1, 8, 3, 2, 9 };
    size_t vel = sizeof(niz) / sizeof(niz[0]);

    cout << "Pocetni niz: ";
    for (size_t i = 0; i < vel; i++) cout << niz[i] << " ";
    cout << endl;

    sortt(niz, vel, ascending);
    cout << "Uzlazno: ";
    for (size_t i = 0; i < vel; i++) cout << niz[i] << " ";
    cout << endl;

    sortt(niz, vel, descending);
    cout << "Silazno: ";
    for (size_t i = 0; i < vel; i++) cout << niz[i] << " ";
    cout << endl;

    return 0;
}
