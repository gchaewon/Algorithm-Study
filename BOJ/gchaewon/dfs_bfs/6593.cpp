#include <bits/stdc++.h>

using namespace std;

int l, r, c;
char a[34][34][34];
int visited[34][34][34];
vector<vector<int>> dir = {{0, 1, 0},  {0, -1, 0}, {0, 0, 1},
                           {0, 0, -1}, {-1, 0, 0}, {1, 0, 0}};

int bfs(int z, int x, int y) {
    queue<vector<int>> q;
    q.push({z, x, y});
    visited[z][x][y] = 1;

    while (!q.empty()) {
        int z = q.front()[0];
        int x = q.front()[1];
        int y = q.front()[2];
        q.pop();

        if (a[z][x][y] == 'E') {
            return visited[z][x][y];
        }
        for (auto &d : dir) {
            int dz = z + d[0];
            int dx = x + d[1];
            int dy = y + d[2];

            if (dz < 0 || dz >= l || dx < 0 || dx >= r || dy < 0 || dy >= c ||
                visited[dz][dx][dy] || a[dz][dx][dy] == '#') {
                continue;
            }

            visited[dz][dx][dy] = visited[z][x][y] + 1;
            q.push({dz, dx, dy});
        }
    }
    return 0;
}
int main() {
    while (true) {
        int x, y, z;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) {
            break;
        }

        memset(a, 'X', sizeof(a));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S') {
                        z = i, x = j, y = k;
                    }
                }
            }
        }

        int temp = bfs(z, x, y);
        if (temp) {
            cout << "Escaped in " << temp - 1 << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}