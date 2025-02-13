#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    vector<vector<long long>> dp(
        31, vector<long long>(
                31, 0)); // dp[w][h] = 큰 알약 w, 작은 알약 h개 뽑는 경우의 수

    for (int h = 0; h <= 30; h++) {
        for (int w = 0; w <= 30; w++) {
            if (h > w) {
                continue;
            }
            if (h == 0) {
                dp[w][h] = 1;
            } else {
                dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
            }
        }
    }

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << dp[n][n] << "\n";
    }

    return 0;
}