#include <bits/stdc++.h>

const int MAX = 100004;
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> arr(n, 0), cnt(MAX, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = 0;

    while (l <= r && r < n) {
        // k개 이하, 오른쪽 포인터 이동
        if (cnt[arr[r]] < k) {
            cnt[arr[r]]++;
            r++;
            ans = max(ans, r - l);
            // k개 초과, 중복 카운트 k이하로 줄이고, 왼쪽 포인터 이동
        } else {
            cnt[arr[l]]--;
            l++;
        }
    }
    cout << ans;

    return 0;
}