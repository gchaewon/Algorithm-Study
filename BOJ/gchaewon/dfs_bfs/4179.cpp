#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char v[1004][10004];
int r, c;

int visited1[1004][1004];
int visited2[1004][1004];
queue<pair<int, int>> q1; // 지훈 저장
queue<pair<int, int>> q2; // 불 저장

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs_fire() {
    while (!q2.empty()) {
        int x = q2.front().X;
        int y = q2.front().Y;
        q2.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= r || dy < 0 || dy >= c || visited2[dx][dy] ||
                v[dx][dy] == '#') {
                continue;
            }
            visited2[dx][dy] = visited2[x][y] + 1;
            q2.push({dx, dy});
        }
    }
}
void bfs_jh() {
    int ans = 1000000;
    while (!q1.empty()) {
        int x = q1.front().X;
        int y = q1.front().Y;
        q1.pop();

        // 불보다 늦게 도착하는 경로는 제외
        if (visited1[x][y] >= visited2[x][y] && visited2[x][y] != 0) {
            continue;
        }
        // 가장자리 중 최단경로 구하기
        if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
            ans = min(ans, visited1[x][y]);
        }
        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= r || dy < 0 || dy >= c || visited1[dx][dy] ||
                v[dx][dy] != '.') {
                continue;
            }
            visited1[dx][dy] = visited1[x][y] + 1;
            q1.push({dx, dy});
        }
    }
    if (ans == 1000000) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans;
    }
    cout << "\n";
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'J') {
                q1.push({i, j});
                visited1[i][j] = 1;
            }
            // 시작점이 여러 곳인 bfs
            if (v[i][j] == 'F') {
                q2.push({i, j});
                visited2[i][j] = 1;
            }
        }
    }

    bfs_fire();
    bfs_jh();

    return 0;
}