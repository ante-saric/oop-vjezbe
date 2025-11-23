#include <iostream>
#include <string>
using namespace std;

void fix_spaces(string& text) {
    for (size_t i = 0; i + 1 < text.size(); )
        if (text[i] == ' ' && text[i + 1] == ' ')
            text.erase(i, 1);
        else
            ++i;

    for (size_t i = 1; i < text.size(); ++i)
        if ((text[i] == ',' || text[i] == '.') && text[i - 1] == ' ')
            text.erase(i - 1, 1);

    for (size_t i = 0; i + 1 < text.size(); ++i)
        if (text[i] == ',' && text[i + 1] != ' ')
            text.insert(i + 1, " ");
}

int main() {
    string s = "Puno   razmaka ,i tocka .";
    cout << "Prije:  \"" << s << "\"\n";
    fix_spaces(s);
    cout << "Poslije: \"" << s << "\"\n";
    return 0;
}
