#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp[0] = v[0];
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max(v[1], v[2]) + v[3];

    for (int i = 4; i <= n; i++) {
        dp[i] = max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i];
    }
    cout << dp[n];

    return 0;
}