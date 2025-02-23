#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> tmp[j];
        }
        arr[i] = tmp;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = arr[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    while (m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
    }
}