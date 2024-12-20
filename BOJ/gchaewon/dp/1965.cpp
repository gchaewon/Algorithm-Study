#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    vector<int> v(n + 1, 0);
    vector<int> dp(n + 1, 1); // i번째 상지를 포함하는 최대 상자 개수

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }

    cout << ans;
    return 0;
}