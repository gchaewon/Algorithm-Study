#include <algorithm>
#include <iostream>
#include <vector>

#define X first
#define Y second
using namespace std;

int n, m, l, k;
vector<pair<int, int>> star;

int main() {
    cin >> n >> m >> l >> k;
    int x, y, cnt, max_cnt = 0;

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        star.push_back({x, y});
    }

    // 두 별을 가장자리에 두는 경우의 수 구하기
    for (int i = 0; i < k; i++) {
        x = star[i].X; // 별1의 x 좌표

        for (int j = 0; j < k; j++) {
            cnt = 0;
            y = star[j].Y; // 별2의 y좌표

            for (auto s : star) {
                if (x <= s.X && s.X <= x + l && y <= s.Y && s.Y <= y + l) {
                    cnt++;
                }
            }
            max_cnt = max(cnt, max_cnt);
        }
    }
    cout << k - max_cnt;
    return 0;
}