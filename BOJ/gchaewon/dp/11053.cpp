#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> dp(n + 1,
                   1); // dp[i] == i번째 원소부터 시작하여 증가하는 부분 수열

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (n == 1) { // 수열 길이가 1일 때 예외처리
        cout << 1;
        return 0;
    }

    dp[n] = 1;
    if (arr[n] > arr[n - 1]) {
        dp[n - 1] = dp[n] + 1;
    } else {
        dp[n - 1] = 1;
    }

    for (int i = n - 2; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    sort(dp.rbegin(), dp.rend());

    cout << dp[0];

    return 0;
}