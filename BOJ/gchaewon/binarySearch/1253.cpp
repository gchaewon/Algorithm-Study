#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<long long> nums(n, 0LL);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    // 투포인터
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;

        // 각 수의 포인터가 만나기 전까지 탐색
        while (left < right) {
            // 찾으려는 수와 같은 인덱스라면 조정
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            // 두 수의 합이 찾으려는 수와 같다면 good
            long long sum = nums[left] + nums[right];
            if (sum == nums[i]) {
                ans++;
                break;
                // 값이 더 크다면 오른쪽 포인터 이동
            } else if (sum > nums[i]) {
                right -= 1;
            } else {
                // 값이 작다면 왼쪽 포인터 이동
                left += 1;
            }
        }
    }
    cout << ans;

    return 0;
}