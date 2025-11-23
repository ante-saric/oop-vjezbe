#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cmath>


using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesite broj:" << endl;
	while (true) {
		cin >> broj;
		if (broj == 0) break;


		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<<" ";
	}
	cout << endl;
}
int main() {
    vector<int> v;
    input_vector(v);

    cout << "Originalni vektor: ";
    print_vector(v);

    vector<int> unique;
    for (int x : v)
        if (find(unique.begin(), unique.end(), x) == unique.end())
            unique.push_back(x);

    cout << "Jedinstveni elementi: ";
    print_vector(unique);

    sort(unique.begin(), unique.end(),
        [](int a, int b) { return abs(a) < abs(b); });

    cout << "Sortirani po apsolutnoj vrijednosti: ";
    for (int x : unique)
        cout << x << " (" << abs(x) << ") ";
    cout << endl;

    return 0;
}