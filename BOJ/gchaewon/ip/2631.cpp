#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n, 0);
    vector<int> dp(n, 1); // dp[i] = dp[i]부터 시작해서 최대 증가 부분 수열 길이

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 뒤에서부터 구하기
    for (int cur = n - 2; cur >= 0; cur--) {
        // 뒤의 값이 더 크다면, 해당 값의 최대 증가 부분 수열 길이와 비교해서
        // 갱신
        for (int next = cur; next < n; next++) {
            if (v[cur] < v[next]) {
                dp[cur] = max(dp[cur], dp[next] + 1);
                ans = max(ans, dp[cur]);
            }
        }
    }

    // 최대 증가 부분 수열은 이동안해도됨, 그 외는 이동
    cout << n - ans;

    return 0;
}