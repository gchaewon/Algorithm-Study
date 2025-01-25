#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;

using namespace std;

int r, c;
vector<vector<char>> map(1000, vector<char>(1000, ' '));
vector<vector<int>> dist1(1000, vector<int>(1000, 1));
vector<vector<int>> dist2(1000, vector<int>(1000, 1));
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q1; // 불, x, y 좌표 저장용
queue<pair<int, int>> q2; // 지훈이,  x, y 좌표 저장용

void bfs() {
    // 불 이동 경로 및 시간 측정
    while (!q1.empty()) {
        int x = q1.front().X;
        int y = q1.front().Y;
        q1.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            // 맵 범위 벗어난 이동 불가
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                continue;
            }
            // 벽이거나 불이 지나갔으면 이동 불가
            if (map[nx][ny] == '#' || map[nx][ny] == 'F') {
                continue;
            }
            dist1[nx][ny] = dist1[x][y] + 1;
            map[nx][ny] = 'F'; // 방문처리
            q1.push({nx, ny});
        }
    }

    // 지훈이 이동
    while (!q2.empty()) {
        int x = q2.front().X;
        int y = q2.front().Y;
        q2.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            // 범위를 벗어나는 경우 탈출
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                if (nx < 0) {
                    cout << dist2[0][ny];
                } else if (nx >= r) {
                    cout << dist2[r - 1][ny];
                } else if (ny < 0) {
                    cout << dist2[nx][0];
                } else {
                    cout << dist2[nx][c - 1];
                }
                return;
            }

            // 방문한적 있거나, 벽이면 이동 불가
            if (dist2[nx][ny] != 1 || map[nx][ny] == '#') {
                continue;
            }
            // 불의 경로이고, 불보다 늦게 도착하면 이동 불가
            if (map[nx][ny] == 'F' && dist1[nx][ny] <= dist2[x][y] + 1) {
                continue;
            }
            dist2[nx][ny] = dist2[x][y] + 1;
            q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    return;
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'F') {
                q1.push({i, j});
            }
            if (map[i][j] == 'J') {
                q2.push({i, j});
            }
        }
    }

    bfs();

    return 0;
}