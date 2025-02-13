#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int arr[1004][1004];
    int dp[1004][1004];
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= 1) {
                dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][j]);
            }
            if (j >= 1) {
                dp[i][j] = max(dp[i][j], arr[i][j] + dp[i][j - 1]);
            }
            if (i >= 1 && j >= 1) {
                dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][j - 1]);
            }
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}