#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;

    cin >> n >> m;
    long long ans = LLONG_MAX;

    vector<long long> nums(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    // 투포인터
    int left = 0, right = 0;

    while (left <= right && left >= 0 && right < n) {
        long long diff = abs(nums[right] - nums[left]);
        // 값 차이가 크다면 왼쪽 포인터 이동 (diff 감소)
        if (diff >= m) {
            left += 1;
            ans = min(ans, diff);
            // 값 차이가 작다면 오른쪽 포인터 이동 (diff 증가)
        } else {
            right += 1;
        }
    }

    cout << ans;
    return 0;
}