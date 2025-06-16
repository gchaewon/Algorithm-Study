#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = 0, right = n - 1;
    int min_left = 0, min_right = n - 1;
    long long min_diff = __LONG_LONG_MAX__;

    while (left < right) {
        long long sum = v[left] + v[right];
        long long diff = abs(0 - sum);

        // 0으로부터 차이가 최소라면 갱신
        if (diff < min_diff) {
            min_diff = diff;
            min_left = left;
            min_right = right;
        }

        // 0보다 크거나 같으면 오른쪽 포인터 당김 (더 작은값)
        if (sum >= 0) {
            right -= 1;
        } else {
            // 작으면 왼쪽 포인터 밀기 (더 큰값)
            left += 1;
        }
    }

    // 차이가 최소일 때 두 용액
    cout << v[min_left] << " " << v[min_right];

    return 0;
}