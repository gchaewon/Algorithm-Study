#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    long long ans = 0LL;

    cin >> n;

    vector<int> nums(n, 0);
    vector<int> include(n, 0); // 수 포함 여부 저장

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 투포인터 기준점 left -> right까지 수열 확인
    int right = 0;
    for (int left = 0; left < n; left++) {
        // 마지막 전까지 탐색
        while (right < n) {
            // 만약 중복 숫자가 나와서 연속 수열 만족하지 않으면 중지
            if (include[nums[right]]) {
                break;
            }
            // 포함처리, 포인터 이동
            include[nums[right]] = 1;
            right++;
        }
        // 12345 에서 구할 수 있는 경우 1, 12, 123, 1234, 12345
        // 즉, right(5)-left(0)개
        ans += (right - left);

        // 제일 왼쪽 수열 제외
        include[nums[left]] = 0;
    }
    cout << ans;
    return 0;
}