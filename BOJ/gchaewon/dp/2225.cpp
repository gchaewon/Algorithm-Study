#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000000LL;

int main() {
    int n, k;
    cin >> n >> k;
    // dp[i][j] = 0부터 i까지 정수 k개를 더해 합이 i가 되는 모든 경우의 수
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1LL));

    // 초기화, dp[1][1] = 1, dp[1][2] = 2 (0+1, 1+0), dp[1][3] = 3 (0+1+1 3C1)
    for (int i = 2; i <= k; i++) {
        dp[1][i] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n][k] % MOD;

    return 0;
}