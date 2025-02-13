#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000009LL;
int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<long long> dp(n + 5, 0LL);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            dp[i] %= MOD;
        }
        cout << dp[n] << "\n";
    }

    return 0;
}