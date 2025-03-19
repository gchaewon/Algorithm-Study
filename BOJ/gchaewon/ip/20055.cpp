#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<pair<int, bool>> v, temp; // 내구성, 로봇 여부

    for (int i = 0; i < (2 * n); i++) {
        int num;
        cin >> num;
        v.push_back({num, false});
    }

    while (true) {
        ans++;
        // 회전
        temp = v;
        for (int i = 0; i < 2 * n; i++) {
            v[(i + 1) % (2 * n)] = temp[i];
        }
        // 내리는 위치에서 로봇 제거
        v[n - 1].second = false;

        // 로봇 이동하기
        for (int i = n - 2; i > 0; i--) {
            int next = (i + 1) % (2 * n);
            if (v[i].second && !v[next].second && v[next].first >= 1) {
                // 현 위치에서 로봇 제거
                v[i].second = false;

                // 내리는 위치인 경우 로봇 제거
                if (i + 1 == n - 1) {
                    v[next] = {v[next].first - 1, false};
                } else {
                    // 다음 위치에 로봇 추가
                    v[next] = {v[next].first - 1, true};
                }
            }
        }
        // 로봇 올리기
        if (v[0].first >= 1 && !v[0].second) {
            v[0] = {v[0].first - 1, true};
        }
        // 0인칸 체크
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (v[i].first == 0) {
                cnt++;
            }
        }

        if (cnt >= k) {
            cout << ans;
            break;
        }
    }

    return 0;
}