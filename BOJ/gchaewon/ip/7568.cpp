#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (v[j].first > v[i].first && v[j].second > v[i].second) {
                cnt++;
            }
        }
        cout << cnt << " ";
    }

    return 0;
}