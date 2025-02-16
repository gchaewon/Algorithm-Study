#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (auto p : puddles) {
        dp[p[1] - 1][p[0] - 1] = -1;
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 웅덩이라면 제외
            if (dp[i][j] == -1) {
                continue;
            }
            // 아래
            if (i >= 1 && dp[i - 1][j] != -1) {
                dp[i][j] += dp[i - 1][j];
            }
            // 오른쪽
            if (j >= 1 && dp[i][j - 1] != -1) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }
    answer = dp[n - 1][m - 1];
    return answer;
}