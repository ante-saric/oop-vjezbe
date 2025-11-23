#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverse_string(vector<string>& words) {
	for (string& w : words) {
		reverse(w.begin(), w.end());
}
}

void print_string(vector<string>& words) {
	cout << "[";
	for (string& s : words) {
		cout << "\"" << s << "\" ";
	}
	cout << "]" << endl;
}

int main() {
	vector <string> words = { "word", "apple", "string" };
	cout << "Prije: ";
	print_string(words);

	reverse_string(words);
	cout << "Poslije: ";
	print_string(words);
	cout << endl;
}