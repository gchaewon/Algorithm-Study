#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> num(n + 1, 0);
    vector<int> dp(n + 1, 0); // dp[n] = n까지의 누적합

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        dp[i] = dp[i - 1] + num[i];
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << "\n";
    }
    return 0;
}