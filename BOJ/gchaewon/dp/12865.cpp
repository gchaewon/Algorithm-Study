#include <bits/stdc++.h>

using namespace std;

int n, k;
int w[104], v[104];
int dp[100001]; // dp[i] = 가방에 i무게 만큼 담았을 때 최대 가치

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[k];
    return 0;
}