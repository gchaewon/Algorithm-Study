#include <iostream>
#include <vector>
using namespace std;

const int MAX_M = 10004;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vector<int> coins(n, 0);
        vector<int> dp(MAX_M, 0); // dp[i] = i를 만드는 최대 방법 수

        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }

        cin >> m;

        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            // dp[j]를 만들 때 coins[i] 를 사용하는 경우의 수 m까지 다 더함
            for (int j = coins[i]; j <= m; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[m] << "\n";
    }
    return 0;
}