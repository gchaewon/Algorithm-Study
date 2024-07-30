#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> cup(n + 1, 0LL);
    vector<long long> dp(
        n + 1,
        0LL); // dp[i] = i번째 잔까지 마셨을 때, 최대로 마실 수 있는 포도주 양

    for (int i = 1; i <= n; i++) {
        cin >> cup[i];
    }

    dp[1] = cup[1];
    dp[2] = cup[1] + cup[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + cup[i - 1], dp[i - 2]) + cup[i];
        dp[i] = max(dp[i - 1], dp[i]);
    }

    sort(dp.rbegin(), dp.rend()); // 최댓값 찾기

    cout << dp[0]; // 최댓값 출력
    return 0;
}