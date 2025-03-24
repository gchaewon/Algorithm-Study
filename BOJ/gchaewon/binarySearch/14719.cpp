#include <bits/stdc++.h>
using namespace std;

int h, w;
int a[504];
int main() {
    int ans = 0;
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < w - 1; i++) {
        int l = 0, r = 0;
        // 현 위치의 왼쪽 가장 큰 벽 구하기
        for (int j = 0; j < i; j++) {
            l = max(l, a[j]);
        }
        // 현 위치의 오른쪽 가장 큰 벽 구하기
        for (int j = w - 1; j > i; j--) {
            r = max(r, a[j]);
        }
        // 빗물 구하기
        ans += max(0, min(l, r) - a[i]);
    }
    cout << ans;
    return 0;
}