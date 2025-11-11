#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 4, 0);
    vector<long long> dp(n + 4, 0); // dp[i] = i를 포함하는 점수 최댓값

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
    }

    cout << dp[n];

    return 0;
}