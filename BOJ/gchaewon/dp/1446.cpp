#include <bits/stdc++.h>

using namespace std;

int n, d;

struct s {
    int x, y, l;
};

int main() {
    cin >> n >> d;
    vector<int> dp(d + 4, 0); // dp[n] = 위치가 n일 때 최소 이동 거리
    vector<struct s> v;

    for (int i = 0; i < n; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        v.push_back({x, y, l});
    }

    for (int i = 1; i <= d; i++) {
        dp[i] = dp[i - 1] + 1; // 그냥 이동

        for (int j = 0; j < n; j++) {
            if (v[j].y == i) { // 지름길 있을 때, 지름길 길이 + 시작점까지 이동
                               // 거리 더하기
                dp[i] = min(dp[i], v[j].l + dp[v[j].x]);
            }
        }
    }

    cout << dp[d];
    return 0;
}