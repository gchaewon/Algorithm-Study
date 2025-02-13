#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, 1);
    long long ans = 1LL;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int temp = 1;
    for (int i = 0; i < m; i++) {
        int vip;
        cin >> vip;
        ans *= dp[vip - temp]; // vip 좌석 전까지 가짓수
        temp = vip + 1;        // vip 다음 좌석 번호
    }
    // dp[4-1], temp = 4+1 (3자리)
    // dp[7-5], temp = 7+1 (2자리)
    // dp[10-8] (2자리)

    ans *= dp[n + 1 - temp];
    cout << ans;

    return 0;
}