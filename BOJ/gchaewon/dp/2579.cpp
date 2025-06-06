#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0); // n번째 계단을 포함한 최댓값
    vector<int> stairs(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    // 초깃값 예외 고려 처리
    if (n >= 1) {
        dp[1] = stairs[1];
    }
    if (n >= 2) {
        dp[2] = stairs[1] + stairs[2];
    }
    if (n >= 3) {
        dp[3] = max(stairs[1], stairs[2]) + stairs[3];
    }

    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
    }

    cout << dp[n];

    return 0;
}