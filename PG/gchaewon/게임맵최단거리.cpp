#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int visited[104][104];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(vector<vector<int>> maps, int n, int m) {
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            return;
        }

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m || !maps[dx][dy] ||
                visited[dx][dy]) {
                continue;
            }
            visited[dx][dy] = visited[x][y] + 1;
            q.push({dx, dy});
        }
    }
}
int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    int ans = 0;

    visited[0][0] = 1;
    bfs(maps, n, m);

    if (!visited[n - 1][m - 1]) {
        ans = -1;
    } else {
        ans = visited[n - 1][m - 1];
    }

    return ans;
}