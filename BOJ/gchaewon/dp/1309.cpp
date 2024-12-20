#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long ans = 0LL;
    long long mod = 9901LL;
    cin >> n;
    // dp[n][1] n번째 줄의 첫번째칸에 사자를 둘 때 최대 경우의 수,
    // dp[n][0] = 배치하지 않은 수
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 1LL));

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];

        for (int j = 0; j < 3; j++) {
            dp[i][j] %= mod;
        }
    }

    for (int i = 0; i < 3; i++) {
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans;

    return 0;
}