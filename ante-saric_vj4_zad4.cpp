#include <iostream>
#include <string>
using namespace std;

string word_to_pig_latin(const string& rijec) {
	char c = tolower(rijec[0]);
	string samoglasnici = "aeiou";
	if (samoglasnici.find(c) != string::npos) {
		return rijec + "hay";
	}
	else {
		return rijec.substr(1) + rijec[0] + "ay";
	}
}
int main() {
	cout << "apple -> " << word_to_pig_latin("apple") << endl;
	cout << "hay -> " << word_to_pig_latin("hay") << endl;
	cout << "string -> " << word_to_pig_latin("string") << endl;
}