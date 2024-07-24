#include <iostream>
#include <vector>

#define MOD 1000000000;
using namespace std;
int main() {
    int n;
    long long answer = 0;
    cin >> n;

    vector<int> dp(10, 0); // dp[n] n으로 끝나는 수의 개수

    // 초기화
    for (int i = 1; i <= 9; i++) {
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        vector<int> temp(10, 0); // i자리수 중 n으로 끝나는 수의 개수 저장
        for (int j = 0; j <= 9; j++) {
            if (j > 0) {
                temp[j] = (temp[j] + dp[j - 1]) % MOD;
            }
            if (j < 9) {
                temp[j] = (temp[j] + dp[j + 1]) % MOD;
            }
        }
        dp = temp;
    }

    for (auto i : dp) {
        answer = (answer + i) % MOD;
    }

    cout << answer;
    return 0;
}