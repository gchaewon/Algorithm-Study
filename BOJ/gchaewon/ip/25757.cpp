#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, count = 0;
    char type;
    map<char, int> game = {{'Y', 1}, {'F', 2}, {'O', 3}};
    set<string> s;
    cin >> n >> type;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        s.insert(name);
    }

    count = s.size() / game[type];
    cout << count;
    return 0;
}