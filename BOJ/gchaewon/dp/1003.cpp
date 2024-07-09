#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> dp(41, {-1, -1});

int main() {
    int t;
    cin >> t;

    dp[0] = {1, 0};
    dp[1] = {0, 1};
    dp[2] = {1, 1};
    for (int i = 3; i <= 40; i++) {
        dp[i].first = dp[i - 2].first + dp[i - 1].first;
        dp[i].second = dp[i - 2].second + dp[i - 1].second;
    }

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
    return 0;
}