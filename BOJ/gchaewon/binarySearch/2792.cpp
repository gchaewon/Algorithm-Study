#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[300004];

int binarySearch(int mid) {
    int ret = 0; // mid 개수로 나눌 수 있는 명수
    for (int i = 0; i < m; i++) {
        ret += arr[i] / mid;

        if (arr[i] % mid) {
            ret += 1;
        }
    }
    // 학생수보다 작을 때
    return ret <= n;
}

int main() {
    int mid, left = 1, right = 0, ans = INT_MAX;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        right = max(right, arr[i]);
    }

    // 형광펜 최대 개수까지
    while (left <= right) {
        // 한 사람당 나눠줄 갯수
        mid = (left + right) / 2;

        // 나눠줄 수 있으면 갱신, 갯수 더 작게 탐색
        if (binarySearch(mid)) {
            ans = min(ans, mid);
            right = mid - 1;
        } else { // 불가능하면, 갯수 더 크게 탐색
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}