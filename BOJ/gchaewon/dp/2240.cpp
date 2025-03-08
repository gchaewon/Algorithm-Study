#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, w;
    cin >> t >> w;
    int v[1004];
    int dp[1004][34]; // dp[i][j] = i초에 j번 이동했을 때의 개수

    for (int i = 1; i <= t; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j > 0) {
                dp[i][j] = max(dp[i][j - 1], dp[i][j]);
            }
            if ((v[i] == 1 && j % 2 == 0) || (v[i] == 2 && j % 2 == 1)) {
                dp[i][j] += 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= w; i++) {
        ans = max(dp[t][i], ans);
    }
    cout << ans;
    return 0;
}