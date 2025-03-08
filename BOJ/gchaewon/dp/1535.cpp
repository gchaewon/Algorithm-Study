#include <bits/stdc++.h>

using namespace std;

int n;
int health[24], joy[24], dp[101]; // dp[n] = 체력 n일 때 최대 joy

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> joy[i];
    }

    for (int i = 0; i < n; i++) {
        // 체력이 0 이상일 때까지만 반복
        for (int j = 100; j > health[i]; j--) {
            // 악수하지 않는 경우, 하는 경우
            dp[j] = max(dp[j], dp[j - health[i]] + joy[i]);
        }
    }
    cout << dp[100];

    return 0;
}