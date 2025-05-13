#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, area = 0;
    cin >> n;
    vector<pair<int, int>> m; // {위치, 높이} 위치 오름차순
    int large_idx = -1, large_h = -1;

    for (int i = 0; i < n; i++) {
        int l, h;
        cin >> l >> h;
        m.push_back({l, h});
    }

    sort(m.begin(), m.end());

    // 가장 큰 기둥 위치, 높이 구하기
    for (int i = 0; i < n; i++) {
        int h = m[i].second;
        if (h >= large_h) {
            large_h = h;
            large_idx = i;
        }
    }

    // 가장 큰 기둥 왼쪽, 왼->오 증가
    int pre_h = m[0].second, pre_x = m[0].first;

    for (int i = 1; i <= large_idx; i++) {
        int cur_x = m[i].first;
        int cur_h = m[i].second;

        if (cur_h >= pre_h) {
            area += (cur_x - pre_x) * pre_h;
            pre_h = cur_h;
            pre_x = cur_x;
        }
    }
    // 가장 큰 기둥
    area += large_h;

    // 가장 큰 기둥 기준 오른쪽, 오->왼 증가
    pre_h = m[n - 1].second, pre_x = m[n - 1].first;

    for (int i = n - 2; i >= large_idx; i--) {
        int cur_x = m[i].first;
        int cur_h = m[i].second;

        if (cur_h >= pre_h) {
            area += (pre_x - cur_x) * pre_h;
            pre_h = cur_h;
            pre_x = cur_x;
        }
    }

    cout << area;
    return 0;
}