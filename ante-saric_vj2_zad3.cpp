#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double** alociraj(int m, int n) {
    double** mat = new double* [m];
    for (int i = 0; i < m; i++)
        mat[i] = new double[n];
    return mat;
}

void dealociraj(double** mat, int m) {
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;
}

void unesiMatricu(double** mat, int m, int n) {
    cout << "Unos matrice (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
}

void generirajMatricu(double** mat, int m, int n, double a, double b) {
    srand(time(0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = a + (double)rand() / RAND_MAX * (b - a);
}

void ispisi(double** mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << fixed << setprecision(4) << mat[i][j];
        cout << endl;
    }
}

double** zbroji(double** A, double** B, int m, int n) {
    double** C = alociraj(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** oduzmi(double** A, double** B, int m, int n) {
    double** C = alociraj(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** pomnozi(double** A, int m1, int n1, double** B, int m2, int n2) {
    if (n1 != m2) {
        cout << "Ne mogu se mnoziti te matrice!\n";
        return nullptr;
    }
    double** C = alociraj(m1, n2);
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

double** transponiraj(double** A, int m, int n) {
    double** T = alociraj(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

int main() {
    int m, n;
    cout << "Unesite dimenzije matrice (m n): ";
    cin >> m >> n;

    double** A = alociraj(m, n);
    double** B = alociraj(m, n);

    generirajMatricu(A, m, n, 0, 10);
    generirajMatricu(B, m, n, 0, 10);

    cout << "\nMatrica A:\n";
    ispisi(A, m, n);

    cout << "\nMatrica B:\n";
    ispisi(B, m, n);

    double** Z = zbroji(A, B, m, n);
    cout << "\nA + B:\n";
    ispisi(Z, m, n);

    double** O = oduzmi(A, B, m, n);
    cout << "\nA - B:\n";
    ispisi(O, m, n);

    double** T = transponiraj(A, m, n);
    cout << "\nTransponirana A:\n";
    ispisi(T, n, m);

    dealociraj(A, m);
    dealociraj(B, m);
    dealociraj(Z, m);
    dealociraj(O, m);
    dealociraj(T, n);

    return 0;
}
