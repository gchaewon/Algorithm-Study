#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;
using namespace std;

int n, m;
vector<vector<int>> map(1000, vector<int>(1000, 0));
vector<vector<int>> dist(1000, vector<int>(1000, 0));
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        map[x][y] = 2; // 방문처리
        q.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (map[nx][ny] != 1) {
                continue;
            }
            dist[nx][ny] = dist[x][y] + 1;
            map[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}
int main() {
    cin >> n >> m;
    pair<int, int> start;

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                start = make_pair(i, j);
            }
        }
    }

    bfs(start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                cout << -1 << " ";
                continue;
            }
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}