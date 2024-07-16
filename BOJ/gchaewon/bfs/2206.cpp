#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;
int n, m;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> map(1000, vector<int>(1000, 0));
vector<vector<vector<int>>> dist(1000,
                                 vector<vector<int>>(1000, vector<int>(2, -1)));

void bfs() {
    queue<vector<int>> q;
    q.push({0, 0, 0}); // x, y, broken (0, 1)
    dist[0][0][0] = 1;

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int broken = q.front()[2];
        q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << dist[x][y][broken];
            return;
        }
        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            // 부순적 없고, 벽일 때 -> 부수고 업데이트
            if (map[nx][ny] == 1 && broken == 0 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1});
                // 벽이 아닐 때 -> 부순 적 있는지 (broken)에 따라 거리 업데이트
            } else if (map[nx][ny] == 0 && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }
        }
    }
    cout << "-1";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < m; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    bfs();
    return 0;
}