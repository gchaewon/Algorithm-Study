#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int ans = 0;
char v[52][52];
int visited[52][52];
vector<pair<int, int>> land;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    visited[start.X][start.Y] = 1;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }

            if (v[dx][dy] == 'L' && visited[dx][dy] == 0) {
                visited[dx][dy] = visited[x][y] + 1;
                ans = max(ans, visited[dx][dy]);
                q.push({dx, dy});
            }
        }
    }
}
int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            v[i][j] = line[j];
            if (v[i][j] == 'L') {
                land.push_back({i, j});
            }
        }
    }

    for (auto l : land) {
        bfs(l);
    }
    cout << ans - 1;

    return 0;
}