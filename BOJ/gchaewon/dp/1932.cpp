#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> num(n);
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        vector<long long> floor(i + 1, 0);
        for (int j = 0; j <= i; j++) {
            cin >> floor[j];
        }
        num[i] = floor;
    }

    // dp = num;
    dp[0][0] = num[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // 왼쪽 가장 자리인 경우
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + num[i][j];
                // 오른쪽 가장 자리인 경우
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + num[i][j];
            }
            // 중앙인 경우, 대각선 왼쪽, 오른쪽 중 큰 것 선택
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + num[i][j];
            }
        }
    }

    sort(dp[n - 1].rbegin(), dp[n - 1].rend());

    cout << dp[n - 1][0];

    return 0;
}