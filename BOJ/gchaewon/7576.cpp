#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;
using namespace std;

int N, M;
queue<pair<int, int>> q;
vector<vector<int>> boxs(1001, vector<int>(1001, -1));
vector<vector<int>> dist(1001, vector<int>(1001, -1));
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs() {
    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if (nx >= N || nx < 0 || ny >= M || ny < 0)
                continue;
            if (boxs[nx][ny] != 0)
                continue;
            boxs[nx][ny] = 2;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
int main() {
    int answer = 0;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> boxs[i][j];
            if (boxs[i][j] == 1) {
                boxs[i][j] = 2;
                q.push({i, j});
            }
        }
    }

    bfs();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (boxs[i][j] == 0) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    ans == 0 ? cout << 0 : cout << ans + 1;
    return 0;
}