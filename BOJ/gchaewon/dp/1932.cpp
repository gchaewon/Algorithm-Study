#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long num;
    vector<vector<long long>> dp(n);

    cin >> num;
    dp[0].push_back(num);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> num;
            if (j == 0) {
                dp[i].push_back(dp[i - 1][0] + num);
            } else if (j == i) {
                dp[i].push_back(dp[i - 1][i - 1] + num);
            } else {
                dp[i].push_back(
                    max(dp[i - 1][j - 1] + num, dp[i - 1][j] + num));
            }
        }
    }

    sort(dp[n - 1].rbegin(), dp[n - 1].rend());
    cout << dp[n - 1][0];

    return 0;
}