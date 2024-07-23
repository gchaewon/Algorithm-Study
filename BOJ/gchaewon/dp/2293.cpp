#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n, 0);
    vector<int> dp(k + 1, 0); // dp[i] = i원을 만들 수 있는 경우의 수

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    sort(coins.begin(), coins.end());

    // 각 동전에서 만들 수 있는 금액을 순차적으로 계산
    for (auto coin : coins) {
        for (int i = coin; i <= k; i++) {
            dp[i] += dp[i - coin];
        }
    }
    cout << dp[k];
    return 0;
}