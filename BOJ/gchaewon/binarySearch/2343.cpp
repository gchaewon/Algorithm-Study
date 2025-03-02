#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100004];

int binarySearch(int mid) {
    int cnt = 0, sum = 0;

    // 블루레이 용량 초과시 개수 더하기
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > mid) {
            sum = 0;
            cnt++;
        }
        sum += arr[i];
    }
    // 남은 영상이 있다면 블루레이 +1
    if (sum != 0) {
        cnt++;
    }

    // 나눌 개수보다 작으면 true
    return cnt <= m;
}
int main() {
    int mid, right, left = 0, ans = INT_MAX;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        left = max(left, arr[i]);
        right += arr[i];
    }

    while (left <= right) {
        mid = (left + right) / 2; // 블루레이 크기

        // 담을 수 있다면 갱신, 용량 줄이기
        if (binarySearch(mid)) {
            right = mid - 1;
            ans = mid;
        } else { // 담을 수 없다면 용량 늘리기
            left = mid + 1;
        }
    }
    cout << ans;

    return 0;
}