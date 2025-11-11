#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    int max_num = 0;
    cin >> t;
    vector<int> arr;

    while (t--) {
        cin >> n;
        arr.push_back(n);
        max_num = max(max_num, n);
    }
    vector<int> dp(max_num + 4, 0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= max_num; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int a : arr) {
        cout << dp[a] << "\n";
    }
    return 0;
}