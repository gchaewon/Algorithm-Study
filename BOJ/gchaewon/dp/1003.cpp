#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 41;
int main() {
    int t;
    cin >> t;
    vector<int> dp_zero(MAX_N + 1,
                        0); // dp[i] i를 호출 했을 때 0이 호출되는 횟수
    vector<int> dp_one(MAX_N + 1,
                       0); // dp[i] i를 호출 했을 때 1이 호출되는 횟수

    dp_zero[0] = 1;
    dp_zero[1] = 0;

    dp_one[0] = 0;
    dp_one[1] = 1;

    for (int i = 2; i <= MAX_N; i++) {
        dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
        dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
    }

    while (t--) {
        int n;
        cin >> n;
        cout << dp_zero[n] << " " << dp_one[n] << "\n";
    }
    return 0;
}