#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(1000,
                   0); // dp[i] = i개 돌이 있을 때 이기는 사람 상근 1, 창영 0

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for (int i = 5; i <= N; i++) {
        int sum = dp[i - 4] + dp[i - 3] + dp[i - 1];
        if (sum < 3) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
    }

    if (dp[N]) {
        cout << "SK";
    } else {
        cout << "CY";
    }
    return 0;
}
