#include <bits/stdc++.h>

const int MOD = 15746;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 4, 0);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        dp[i] %= MOD;
    }
    cout << dp[n];
    return 0;
}