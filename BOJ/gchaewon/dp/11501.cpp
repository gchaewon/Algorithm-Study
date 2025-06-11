#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    while (t--) {
        int n, num;
        long long sum = 0;

        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // 뒤에서부터 최대 주식 가격 갱신하며 수익 더하기
        int max_num = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            // 최대 주식보다 큰 값이면 갱신
            if (max_num < nums[i]) {
                max_num = nums[i];
                continue;
            }
            // 아니면 더하기
            sum += max_num - nums[i];
        }

        cout << sum << "\n";
    }
    return 0;
}