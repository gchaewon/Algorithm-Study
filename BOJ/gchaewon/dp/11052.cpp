#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> card(n + 1, 0);
    vector<int> dp(n + 1,
                   0); // dp[i] = 카드 i개를 갖기 위해 지불해야하는 최대 금액

    for (int i = 1; i <= n; i++) {
        cin >> card[i];
        dp[i] = card[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
        }
    }

    cout << dp[n];
    return 0;
}