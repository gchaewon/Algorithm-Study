#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    string temp;
    map<int, string> s;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp >> x;
        s.insert({x, temp});
    }

    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << (s.lower_bound(x))->second << "\n";
    }

    return 0;
}