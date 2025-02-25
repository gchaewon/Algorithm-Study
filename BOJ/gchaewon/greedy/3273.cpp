#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    int arr[100004];
    int ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr + n);

    int l = 0, r = n - 1;

    // 왼쪽, 오른쪽 포인터가 만나기 전까지 반복
    while (r > l) {
        int temp = arr[l] + arr[r];
        // 값이 크면 큰 값 위치 옮기기
        if (temp > x) {
            r--;
            // 값이 작으면 작은 값 위치 옮기기
        } else if (temp < x) {
            l++;
            // 같은 값이면 동시에 옮기기
        } else {
            r--;
            l++;
            ans++;
        }
    }
    cout << ans;
    return 0;
}