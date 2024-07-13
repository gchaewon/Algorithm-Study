#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int idx = 1;
    int ans = 1;
    for (int i = 0; i < M; i++)
    {
        int vip;
        cin >> vip;
        ans *= dp[vip - idx];
        idx = vip + 1;
    }
    ans *= dp[N + 1 - idx];

    cout << ans;
    return 0;
}