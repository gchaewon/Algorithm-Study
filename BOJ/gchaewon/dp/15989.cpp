#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, max_num = 0;
    cin >> t;
    int num[t];

    memset(num, 0, sizeof(num));

    for (int i = 0; i < t; i++) {
        cin >> num[i];
        max_num = max(max_num, num[i]);
    }

    int dp[max_num + 1];
    memset(dp, 0, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= max_num; i++) {
        dp[i] = dp[i - 3] + floor(i / 2) + 1; // 3 넣는 경우, 2를 포함하는 경우
                                              // 경우, 1로만 표현하는 경우
    }

    for (auto n : num) {
        cout << dp[n] << "\n";
    }

    return 0;
}
