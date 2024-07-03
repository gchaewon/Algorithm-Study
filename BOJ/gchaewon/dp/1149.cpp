#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, {0, 0, 0});

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

        // 이전 값과 다른 색을 칠할 때 최소값, 경우에 따라 구하기
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}