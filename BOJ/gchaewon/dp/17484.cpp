#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int a[10][10];
int dp[10][10][3]; // dp[i][j][dir] = 3가지 방향으로 왔을 때 최솟값

int main() {
    int n, m, ans = INT_MAX;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // 초기값
    for (int j = 0; j < m; j++) {
        for (int d = 0; d < 3; d++) {
            dp[0][j][d] = a[0][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 왼쪽 대각선
            if (j == 0) { // 왼쪽 끝 위치면 왼쪽 대각선에서 올 수 없음
                dp[i][j][0] = INT_MAX;
            } else {
                dp[i][j][0] =
                    min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + a[i][j];
            }

            // 직선
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + a[i][j];

            // 오른쪽 대각선
            if (j == m - 1) { // 오른쪽 끝 위치면 오른쪽 대각선에서 올 수 없음
                dp[i][j][2] = INT_MAX;
            } else {
                dp[i][j][2] =
                    min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + a[i][j];
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int d = 0; d < 3; d++) {
            ans = min(ans, dp[n - 1][j][d]);
        }
    }
    cout << ans;
    return 0;
}