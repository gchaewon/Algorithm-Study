#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int answer = -1001;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        answer = max(answer, nums[i]);
    }

    dp = nums;

    for (int i = 1; i < n; i++) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        answer = max(answer, dp[i]);
    }
    cout << answer;

    return 0;
}
