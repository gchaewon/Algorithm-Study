#include <iostream>
#include <vector>

#define MOD 10007
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(
        n + 1,
        vector<int>(10, 0)); // dp[i][j] i자리수 중 j로 시작하는 수의 개수

    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int sum = 0;
    for (auto i : dp[n]) {
        sum = (sum + i) % MOD;
    }

    cout << sum;
    return 0;
}