#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c;
    long long ans = 0;
    cin >> n >> c;
    vector<long long> h(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    long long left = 1, right = h.back() - h.front(),
              mid = 0; // 두 공유기간 거리 차

    while (left <= right) {
        mid = (left + right) / 2;

        int cnt = 1;
        long long pre = h[0]; // 첫 집에는 무조건 공유기 설치

        // 순회하면서 이전 공유기와 집의 거리차가 mid 이상일 때만 설치 가능
        for (int i = 1; i < n; i++) {
            if (h[i] - pre >= mid) {
                pre = h[i];
                cnt++;
            }
        }
        // 가능한 공유기 수가 적다면
        if (cnt < c) {
            right = mid - 1; // 거리 좁힘
        } else {
            // 가능한 수를 만족한다면, 거리를 더 늘려서 최댓값 탐색하기
            ans = max(ans, mid);
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}