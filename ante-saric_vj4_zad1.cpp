#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void input_vector(vector<int>& v) {
	int broj;
	cout << "Unesite broj:"<<endl ;
	while (true) {
		cin >> broj;
		if (broj == 0) break;
			
		
		v.push_back(broj);
	}
 }

void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
}

int	main() {
	vector<int> v;
	input_vector(v);
	print_vector(v);
}


