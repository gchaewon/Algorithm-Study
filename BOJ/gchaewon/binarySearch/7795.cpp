#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int a[20004], b[20004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + m);

        for (int i = 0; i < n; i++) {
            // a[i] 이상인 첫 값의 위치
            auto pos = lower_bound(b, b + m, a[i]);
            // 시작 위치를 빼서 a[i] 이하인 개수 구하기
            ans += (int)(pos - b);
        }
        cout << ans << "\n";
    }
    return 0;
}