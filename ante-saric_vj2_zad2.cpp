#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;
const int INIT_CAPACITY = 10;

struct Vector {
    int* elements;
    int logical_size;
    int physical_size;
};

Vector vector_new(int capacity = INIT_CAPACITY) {
    Vector v;
    v.elements = new int[capacity];
    v.logical_size = 0;
    v.physical_size = capacity;
    return v;
}

void vector_delete(Vector& v) {
    delete[] v.elements;
    v.elements = nullptr;
    v.logical_size = 0;
    v.physical_size = 0;
}

void vector_push_back(Vector& v, int value) {
    if (v.logical_size == v.physical_size) {
        int new_capacity = v.physical_size * 2;
        int* new_elements = new int[new_capacity];

        for (int i = 0; i < v.logical_size; ++i) {
            new_elements[i] = v.elements[i];
        }

        delete[] v.elements;
        v.elements = new_elements;
        v.physical_size = new_capacity;
    }

    v.elements[v.logical_size] = value;
    v.logical_size++;
}

void vector_pop_back(Vector& v) {
    if (v.logical_size > 0) {
        v.logical_size--;
    }
    else {
        throw out_of_range("Vector is empty: cannot pop_back.");
    }
}

int vector_front(const Vector& v) {
    if (v.logical_size > 0) {
        return v.elements[0];
    }
    else {
        throw out_of_range("Vector is empty: no front element.");
    }
}

int vector_back(const Vector& v) {
    if (v.logical_size > 0) {
        return v.elements[v.logical_size - 1];
    }
    else {
        throw out_of_range("Vector is empty: no back element.");
    }
}

int vector_size(const Vector& v) {
    return v.logical_size;
}

void print_vector(const Vector& v) {
    cout << "Vector (Size: " << v.logical_size
        << ", Capacity: " << v.physical_size << ") [";
    for (int i = 0; i < v.logical_size; ++i) {
        cout << v.elements[i] << (i < v.logical_size - 1 ? ", " : "");
    }
    
    cout << "]" << std::endl;
}

int main() {
    Vector mojVektor = vector_new();
    cout << "1. Kreiran vektor (Pocetni kapacitet: " << mojVektor.physical_size << ")" << std::endl;

    for (int i = 0; i < 12; ++i) {
        vector_push_back(mojVektor, i + 1);
    }
    print_vector(mojVektor);

    cout << "2. Logicka velicina: " << vector_size(mojVektor) << std::endl;
    cout << "3. Prvi element (front): " << vector_front(mojVektor) << std::endl;
    cout << "4. Zadnji element (back): " << vector_back(mojVektor) << std::endl;

    vector_pop_back(mojVektor);
    vector_pop_back(mojVektor);
    cout << "5. Nakon dva pop_back: ";
    print_vector(mojVektor);
    cout << "   Nova logicka velicina: " << vector_size(mojVektor) << std::endl;
    cout << "   Novi zadnji element (back): " << vector_back(mojVektor) << std::endl;

    vector_delete(mojVektor);
    cout << "6. Vektor je obrisan. Kapacitet: " << mojVektor.physical_size << std::endl;

    return 0;
}