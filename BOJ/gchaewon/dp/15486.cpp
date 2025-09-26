#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    vector<int> t(n + 1, 0), p(n + 1, 0);
    vector<int> dp(n + 2, 0); // dp[i] = i일째 받을 수 있는 최대 금액

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n + 1; i++) {
        // i번째 일을 안 하는 경우, (이전 누적 값과 비교하여 갱신)
        dp[i] = max(dp[i], dp[i - 1]);

        // i번째 일을 할 경우, (i + t[i] = i번째 일하고 난 후 날짜일때 값 갱신)
        if (i <= n && i + t[i] <= n + 1) {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
        }
    }

    cout << dp[n + 1];
    return 0;
}