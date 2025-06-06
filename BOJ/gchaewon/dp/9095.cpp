#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    vector<int> dp(12, 0);
    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 12; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}