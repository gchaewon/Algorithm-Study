#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    int result = 0;
    int cur = 0;
    for (int i = 0; i < N; i++)
    {
        int date, cost;
        cin >> date >> cost;
        cur = max(cur, dp[i]);
        if (i + date <= N)
        {
            dp[i + date] = max(dp[i + date], cur + cost);
            result = max(dp[i + date], result);
        }
    }
    cout << result;
    return 0;
}