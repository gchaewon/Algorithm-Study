#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 4, 0);
    vector<int> dp(n + 4, 0); // i번째 원소를 포함하는 최대 증가 부분 수열의 합

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[n - 1] = a[n - 1];

    for (int i = n; i >= 0; i--) {
        dp[i] = a[i];
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    sort(dp.rbegin(), dp.rend());
    cout << dp[0];

    return 0;
}