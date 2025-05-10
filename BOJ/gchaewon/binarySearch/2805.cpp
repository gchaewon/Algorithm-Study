#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    long long n, m, left = 0LL, right = 0LL, mid = 0LL, ans = 0LL;
    vector<long long> t;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;
        t.push_back(h);
    }

    // 나무 정렬
    sort(t.begin(), t.end());
    // 가장 긴 나무 길이
    right = t.back();

    // 이분탐색
    while (left <= right) {
        mid = (left + right) / 2;

        long long temp = 0; // 잘린 나무의 합
        for (int i = n - 1; i >= 0; i--) {
            if (t[i] <= mid) {
                break;
            }
            temp += t[i] - mid;
        }
        // 잘린 나무가 부족하다면, 더 낮은 위치에서 자름
        if (temp < m) {
            right = mid - 1;
        } else { // 잘린 나무가 충분하다면, 더 높은 위치에서 자름, 위치 갱신
            ans = max(ans, mid);
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}