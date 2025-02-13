#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string name;
    string output;
    char odd = ' ';
    vector<int> alpha(26, 0);
    cin >> name;
    sort(name.begin(), name.end());

    for (auto i : name) {
        alpha[i - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 != 0) {
            if (odd != ' ') {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            odd = char(i + 'A');
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alpha[i] / 2; j++) {
            output += char(i + 'A');
            cout << char(i + 'A');
        }
    }
    if (odd != ' ') {
        cout << odd;
    }

    sort(output.rbegin(), output.rend());
    for (auto i : output) {
        cout << i;
    }

    return 0;
}