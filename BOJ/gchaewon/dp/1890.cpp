#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    // dp[i][j] = {i, j} 위치까지 이동한 경우의 수
    vector<vector<long long>> dp(n, vector<long long>(n, 0LL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = 1LL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n - 1 && j == n - 1) {
                continue;
            }
            int jump = v[i][j];
            int dx = i + jump;
            int dy = j + jump;

            if (dx < n) {
                dp[dx][j] += dp[i][j];
            }
            if (dy < n) {
                dp[i][dy] += dp[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1];
}