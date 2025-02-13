#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n, len;
    string pattern;
    string s1, s2;
    cin >> n;
    cin >> pattern;
    len = pattern.size();

    for (int i = 0; i < len; i++) {
        if (pattern[i] == '*') {
            s1 = pattern.substr(0, i);
            s2 = pattern.substr(i + 1, len - i);
            break;
        }
    }

    while (n--) {
        string input;
        cin >> input;

        if (input.size() < s1.size() + s2.size()) {
            cout << "NE\n";
            continue;
        }

        string first = input.substr(0, s1.size());
        string second = input.substr(input.size() - s2.size(), s2.size());

        if (first == s1 && second == s2) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }

    return 0;
}