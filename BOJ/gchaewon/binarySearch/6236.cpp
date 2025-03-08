#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100004];

int check(int mid) {
    int cnt = 1;
    int ret = mid;

    for (int i = 0; i < n; i++) {
        if (ret < 0) {
            return 0;
        }
        if (ret < arr[i]) {
            ret = mid;
            cnt++;
        }
        ret -= arr[i];
    }
    return cnt <= m;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k = 10001, left = 0, right = 1000000004; // 금액 * N  최대값
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        left = max(left, arr[i]);
    }

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            right = mid - 1;
            k = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << k;
    return 0;
}