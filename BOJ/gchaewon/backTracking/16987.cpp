#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<pair<int, int>> eggs; // {내구도, 무게}

void backTracking(int idx, int cnt) {
    // 제일 오른쪽까지 오면 중단
    if (idx == n) {
        ans = max(ans, cnt);
        return;
    }

    // 들고 있는 계란이 깨졌거나, 남은 계란이 없는 경우
    if (eggs[idx].first <= 0 || cnt == n - 1) {
        backTracking(idx + 1, cnt);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i == idx || eggs[i].first <= 0) {
            continue;
        }
        // 내구도 업데이트
        eggs[idx].first -= eggs[i].second;
        eggs[i].first -= eggs[idx].second;
        // 깨진 계란수 확인
        int temp = 0;
        if (eggs[idx].first <= 0) {
            temp++;
        }
        if (eggs[i].first <= 0) {
            temp++;
        }

        // 백트래킹
        backTracking(idx + 1, cnt + temp);

        // 원복
        eggs[idx].first += eggs[i].second;
        eggs[i].first += eggs[idx].second;
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        eggs.push_back({p, w});
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    backTracking(0, 0);
    cout << ans;

    return 0;
}