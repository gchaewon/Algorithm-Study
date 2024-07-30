#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    int answer = 0;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> dp(n + 1,
                   0); // dp[i] = arr[i]를 포함하는 arr[i]보다 작은 원소의 총합

    for (int i = 0; i < n; i++) {
        cin >> arr[i + 1];
    }
    dp[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        // do[i] = arr[i]보다 작은 원소 arr[j] 중 가장 큰 dp[j] + arr[i]
        for (int j = i - 1; j >= 1; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += arr[i];
    }

    sort(dp.rbegin(), dp.rend());
    cout << dp[0];

    return 0;
}