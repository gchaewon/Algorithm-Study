#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + v[i];
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << "\n";
    }
}