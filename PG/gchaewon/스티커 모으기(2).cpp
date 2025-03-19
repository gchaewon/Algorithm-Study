#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker) {
    int n = sticker.size();

    if (n == 1) {
        return sticker[0];
    }
    int dp[n][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = sticker[0]; // dp[i][0] = i번째 스티커 포함
    dp[1][0] = sticker[0];

    dp[0][1] = 0; // dp[i][1] = i번째 스티커 포함 X
    dp[1][1] = sticker[1];

    for (int i = 2; i < n; i++) {
        if (i != n - 1) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + sticker[i]);
        }
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + sticker[i]);
    }

    return max(dp[n - 2][0], dp[n - 1][1]);
}
