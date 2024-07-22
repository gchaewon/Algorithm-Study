#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, h;
// {x, y, z}
vector<vector<int>> dir = {{-1, 0, 0}, {1, 0, 0},  {0, 1, 0},
                           {0, -1, 0}, {0, 0, -1}, {0, 0, 1}};
vector<vector<vector<int>>> map(100,
                                vector<vector<int>>(100, vector<int>(100, 0)));
queue<vector<int>> q;

void bfs() {
    while (!q.empty()) {
        int z = q.front()[0];
        int x = q.front()[1];
        int y = q.front()[2];
        q.pop();

        for (auto d : dir) {
            int nz = z + d[0];
            int nx = x + d[1];
            int ny = y + d[2];

            if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (map[nz][nx][ny] != 0) {
                continue;
            }
            map[nz][nx][ny] = map[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;
    int count = 0;
    int day = 0;
    // 입력
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    q.push({i, j, k});
                } else if (map[i][j][k] == 0) {
                    count++;
                }
            }
        }
    }

    // 이미 다 익은 경우 예외처리
    if (count == 0) {
        cout << 0;
        return 0;
    }

    bfs();
    // 안 익은 토마토가 있으면 -1, 다 익었으면 소요 시간 출력
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                day = max(day, map[i][j][k]);
                if (map[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << day - 1;

    return 0;
}