#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    cin >> x;
    vector<long long> dp(x + 3, 0);
    vector<vector<int>> nums(x + 3, vector<int>());

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    nums[1] = {1};
    nums[2] = {2, 1};
    nums[3] = {3, 1};

    for (int i = 4; i <= x; i++) {
        dp[i] = dp[i - 1] + 1;
        nums[i] = nums[i - 1];

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            nums[i] = nums[i / 2];
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            nums[i] = nums[i / 3];
        }
        nums[i].push_back(i);
    }

    cout << dp[x] << "\n";

    sort(nums[x].rbegin(), nums[x].rend());
    for (auto num : nums[x]) {
        cout << num << " ";
    }

    return 0;
}