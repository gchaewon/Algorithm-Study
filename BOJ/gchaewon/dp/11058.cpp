#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long dp[104];
    // dp[1] = 1번일 때 최대 출력할 수 있는 A 개수

    // 3가지 경우의 수
    // dp[i-3] 에서 전체 선택 + 복사 + 붙여넣기 (키 3번 누르기)
    // dp[i-4] 에서 전체 선택 + 복사 + 붙여넣기 + 붙여넣기 (키 4번 누르기)
    // dp[i-5] 에서 전체 선택 + 복사 + 붙여넣기 + 붙여넣기 + 붙여넣기 (키 5번
    // 누르기)
    // 6번 전은 dp[i-3]에서 구하는 것과 동일하므로 제외

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;

    for (int i = 5; i <= n; i++) {
        dp[i] = max(dp[i - 1] + 1,
                    max(dp[i - 3] * 2, max(dp[i - 4] * 3, dp[i - 5] * 4)));
    }

    cout << dp[n];
    return 0;
}