#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // 웅덩이 위치는 -1로 표시
    for (auto &p : puddles) {
        dp[p[1] - 1][p[0] - 1] = -1;
    }

    // 시작 위치는 경로 1개
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] == -1) {
                // 웅덩이는 경로가 없음을 의미하므로 0으로 설정
                dp[i][j] = 0;
                continue;
            }
            // 왼쪽에서 오는 경우
            if (j > 0 && dp[i][j - 1] != -1) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            // 위에서 오는 경우
            if (i > 0 && dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }

    return dp[n - 1][m - 1];
}
