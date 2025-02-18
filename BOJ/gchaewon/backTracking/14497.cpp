#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
int start_x, start_y, end_x, end_y;
int ans = 0;
char c[304][304];

bool is_valid = false;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    int visited[304][304];
    memset(visited, 0, sizeof(visited));

    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy]) {
                continue;
            }
            if (c[dx][dy] == '#') {
                is_valid = true;
                return;
            }

            visited[dx][dy] = 1;

            if (c[dx][dy] == '1') {
                c[dx][dy] = '0';
            } else if (c[dx][dy] == '0') {
                q.push({dx, dy});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    cin >> start_x >> start_y >> end_x >> end_y;
    start_x -= 1;
    start_y -= 1;
    end_x -= 1;
    end_y -= 1;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            c[i][j] = line[j];
        }
    }

    while (true) {
        ans++;
        bfs(start_x, start_y);
        if (is_valid) {
            break;
        }
    }

    cout << ans;

    return 0;
}