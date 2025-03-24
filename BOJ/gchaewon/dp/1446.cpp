#include <bits/stdc++.h>

using namespace std;

struct path {
    int x;
    int y;
    int dist;
};

int main() {
    int n, d, ans = INT_MAX;
    cin >> n >> d;
    vector<path> v;
    vector<int> dp(d + 1, 0); // dp[i] = i 위치까지 최단 경로 길이

    for (int i = 0; i < n; i++) {
        int x, y, dist;
        cin >> x >> y >> dist;
        if (y > d) {
            continue;
        }
        v.push_back({x, y, dist});
    }

    for (int i = 1; i <= d; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].y == i) {
                dp[i] = min(dp[i], dp[v[j].x] + v[j].dist);
            }
        }
    }

    cout << dp[d];
    return 0;
}