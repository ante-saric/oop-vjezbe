#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void filter_students(Student arr[], size_t n,
    void (*akcija)(Student&),
    bool (*filter)(Student&)) {
    for (size_t i = 0; i < n; i++) {
        if (filter(arr[i]))
            akcija(arr[i]);
    }
}

void ispisiStudenta(Student& s) {
    cout << s.ime << " (" << s.jmbag << "), "
        << s.godina << ". godina, "
        << s.ects << " ECTS, prosjek " << s.prosjek << endl;
}

void povecajGodinu(Student& s) {
    s.godina++;
}

int main() {
    Student studenti[] = {
        {"Ana Horvat", "001", 1, 30, 4.2},
        {"Ivan Iviæ", "002", 1, 0, 2.8},
        {"Petra Kovaè", "003", 2, 50, 3.9},
        {"Marko Periæ", "004", 3, 45, 3.3},
        {"Lana Mariæ", "005", 1, 20, 3.7}
    };
    size_t n = sizeof(studenti) / sizeof(studenti[0]);

    cout << "Studenti 1. godine koji su polozili barem jedan ispit:\n";
    auto uvjet1 = [](Student& s) { return s.godina == 1 && s.ects > 0; };
    filter_students(studenti, n, ispisiStudenta, uvjet1);

    cout << "\nStudenti s prosjekom > 3.5:\n";
    auto uvjet2 = [](Student& s) { return s.prosjek > 3.5; };
    filter_students(studenti, n, ispisiStudenta, uvjet2);

    cout << "\nPovecavanje godine studentima s >= 45 ECTS...\n";
    auto uvjet3 = [](Student& s) { return s.ects >= 45; };
    filter_students(studenti, n, povecajGodinu, uvjet3);

    cout << "\nStudenti nakon povecanja godine:\n";
    for (size_t i = 0; i < n; i++)
        ispisiStudenta(studenti[i]);

    return 0;
}
