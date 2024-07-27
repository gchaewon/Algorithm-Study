#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0); // dp[i] = i 크기 직사각형을 채우는 방법 수

    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] * 2 - 1;
        if (i % 2 == 0) {
            dp[i] += 2;
        }
        dp[i] %= 10007;
    }

    cout << dp[n];

    return 0;
}