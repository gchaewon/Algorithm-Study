#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // dp[i][j] = i번째 집에서 j번째 색으로 칠했을 때 최소 비용

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> dp[i][j];
        }
    }

    // 이전 집과 색 겹치지 않는 색 중 최솟값으로 더하기
    for (int i = 1; i < n; i++) {
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    sort(dp[n - 1].begin(), dp[n - 1].end());
    cout << dp[n - 1][0];
    return 0;
}