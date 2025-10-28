#include <iostream>
using namespace std;

int* fibonacci(int n) {
	int* novi = new int[n];

	if (!novi) {
		cout << "Greska pri alokaciji" << endl;
		return 0;
	}
	novi[0] = 1;
	novi[1] = 1;
	for (int i = 2; i < n; i++) {
		novi[i] = novi[i - 2] + novi[i - 1];
	}
	return novi;
}
int main() {
	int n;
	cout << "Unesite n: " << endl;
	cin >> n;
	int* novi = fibonacci(n);
	cout << "Èlanovi niza su: ";
	for (int i = 0; i < n; i++) {
		cout << novi[i] << "  ";
	}
	cout << endl;
	delete[] novi;
}