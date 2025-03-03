#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    // 끝나는 시간 기준 라인스위핑
    int r = v[0].first + v[0].second;

    for (int i = 1; i < n; i++) {
        // 도착 시간 > 이전 작업 끝나는 시간
        if (v[i].first > r) {
            r = v[i].first + v[i].second;
            // 도착 시간 <= 이전 작업 끝나는 시간
        } else if (v[i].first <= r) {
            r += v[i].second;
        }
    }

    cout << r;

    return 0;
}