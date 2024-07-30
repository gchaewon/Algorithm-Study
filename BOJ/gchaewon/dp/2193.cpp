#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(91, 0LL); // dp[i] = i자리 이친수 개수

    dp[1] = 1LL;
    dp[2] = 1LL;
    dp[3] = 2LL;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] * 2 + (dp[i - 1] - dp[i - 2]);
    }

    cout << dp[n];

    return 0;
}