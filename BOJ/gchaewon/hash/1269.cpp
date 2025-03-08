#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, temp, ans = 0;
    map<int, int> m;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> temp;
        m[temp] += 1;
    }
    for (int i = 0; i < b; i++) {
        cin >> temp;
        m[temp] += 1;
    }

    for (auto i : m) {
        if (i.second == 2) {
            ans++;
        }
    }
    cout << m.size() - ans;

    return 0;
}