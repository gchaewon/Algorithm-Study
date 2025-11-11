#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    vector<vector<int>> arr(n + 4, vector<int>(3, 0));
    vector<vector<long long>> dp(n + 4, vector<long long>(3, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }

    answer = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << answer;

    return 0;
}