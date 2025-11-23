#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Unesite tekst: " << endl;
	getline(cin, s);
	for (char &c: s) {
		if (isalpha(c)) {
			c = toupper(c);
		}
		else if (isdigit(c)) {
			c= '*';
		}
		else if (c==' '|| c=='\t') {
			c = '_';
		}
	}
	cout << "Prepravljeni tekst: " << s << endl;
}