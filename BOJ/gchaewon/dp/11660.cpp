#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int arr[1028][1028];
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    // 누적합 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= 1) {
                dp[i][j] += dp[i][j - 1];
            }
            if (i >= 1) {
                dp[i][j] += dp[i - 1][j];
            }
            if (i >= 1 && j >= 1) {
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }

    // 입력에 대한 합 구하기
    while (m--) {
        int x1, y1, x2, y2;
        long long temp = 0LL;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1;
        y1 -= 1;
        x2 -= 1;
        y2 -= 1;

        temp = dp[x2][y2];

        // 가로 부분 제거
        if (y1 >= 1) {
            temp -= dp[x2][y1 - 1];
        }
        // 세로 부분 제거
        if (x1 >= 1) {
            temp -= dp[x1 - 1][y2];
        }
        // 공통 부분 더하기
        if (x1 >= 1 && y1 >= 1) {
            temp += dp[x1 - 1][y1 - 1];
        }
        cout << temp << "\n";
    }

    return 0;
}