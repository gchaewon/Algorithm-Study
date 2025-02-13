#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> m(h, vector<char>(w, '.'));
    vector<vector<int>> ans(h, vector<int>(w, -1));
    vector<int> cnt(h, 0); // 줄별 구름 갯수 저장

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> m[i][j];
            // 구름 위치인 경우처리
            if (m[i][j] == 'c') {
                ans[i][j] = 0;
                cnt[i]++;
                continue;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        // 구름이 하나도 없는 경우처리
        if (cnt[i] == 0) {
            continue;
        }

        for (int j = 0; j < w; j++) {
            // 초기 구름 위치인 경우
            if (ans[i][j] == 0) {
                continue;
            }
            // 가장 가까운 구름까지 거리 구하기
            for (int k = j; k >= 0; k--) {
                if (m[i][k] == 'c') {
                    ans[i][j] = j - k;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}