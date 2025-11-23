#include <iostream>

using namespace std;
int interval(int n, int low = 0, int high = 100) {
	if (n < low)return low;
	if (n > high)return high;
	return n;
}
double interval(double n, double low = 0.0, double high = 100.0) {
	if (n < low)return low;
	if (n > high)return high;
	return n;
}

int main() {
	cout << "Za -10  -  " << interval(-10) << endl;
	cout << "Za 50  -  " << interval(50) << endl;
	cout << "Za 120   -  " << interval(120) << endl;

	cout << "Za -23.5  -  " << interval(-23.5) << endl;
	cout << "Za 55.2  -  " << interval(55.2) << endl;
	cout << "Za 115.4  -  " << interval(115.4) << endl;

	cout << "Za (120, 50, 200)  -  " << interval(120, 50, 200) << endl;
	cout << "Za (50.5, 22.3, 67.5)  -  " << interval(50.5, 22.3, 67.5) << endl;

}