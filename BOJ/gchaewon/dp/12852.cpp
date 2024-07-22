#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0 && i % 3 == 0) {
            dp[i] = min(dp[i], min(dp[i / 2], dp[i / 3]) + 1);
        } else if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        } else if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[n] << "\n";

    // 역순으로 출력하면서 n 값 줄이기
    while (n > 0) {
        cout << n << " ";
        if (n == 1) {
            break;
        }
        if (dp[n] == dp[n - 1] + 1) {
            n--;
        } else if ((n % 3 == 0) && (dp[n] == dp[n / 3] + 1)) {
            n /= 3;
        } else if ((n % 2 == 0) && (dp[n] == dp[n / 2] + 1)) {
            n /= 2;
        }
    }
    return 0;
}
