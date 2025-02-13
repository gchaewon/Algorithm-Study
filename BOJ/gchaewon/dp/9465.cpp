#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> v(n + 1, vector<int>(3, 0));
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int j = 1; j <= 2; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> v[i][j];
            }
        }

        dp[1] = v[1];
        if (n == 1) {
            cout << max(dp[n][1], dp[n][2]) << "\n";
            continue;
        }
        dp[2][1] = v[1][2] + v[2][1];
        dp[2][2] = v[1][1] + v[2][2];

        for (int i = 3; i <= n; i++) {
            dp[i][1] =
                max(max(dp[i - 2][1], dp[i - 2][2]), dp[i - 1][2]) + v[i][1];
            dp[i][2] =
                max(max(dp[i - 2][1], dp[i - 2][2]), dp[i - 1][1]) + v[i][2];
        }

        cout << max(dp[n][1], dp[n][2]) << "\n";
    }

    return 0;
}
