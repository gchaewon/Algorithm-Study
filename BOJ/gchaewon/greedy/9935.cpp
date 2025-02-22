#include <bits/stdc++.h>

using namespace std;

string s, bomb, temp;

int main() {
    cin >> s >> bomb;
    int n = bomb.size();

    for (char a : s) {
        temp += a;
        if (temp.size() >= n) {
            if (temp.substr(temp.size() - n, n) == bomb) {
                temp.erase(temp.end() - n, temp.end());
            }
        }
    }

    if (temp.size()) {
        cout << temp;
    } else {
        cout << "FRULA";
    }

    return 0;
}