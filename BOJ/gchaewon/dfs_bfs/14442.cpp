#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
using namespace std;

int n, m, k, ans = INT_MAX;
int board[1004][1004], visited[1004][1004][14];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// {길 동안 부순 벽의 개수, 이전 위치 {x, y}}
struct Path {
    int break_cnt;
    pair<int, int> pre;
};

int bfs() {
    queue<Path> q; // {길 동안 부순 벽의 개수, 이전 위치 {x, y}}
    q.push({0, {0, 0}});
    memset(visited, 0, sizeof(visited));
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int cnt = q.front().break_cnt;
        int x = q.front().pre.X;
        int y = q.front().pre.Y;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return visited[x][y][cnt];
        }

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }

            // 이동할 수 있는 경우 벽 부수지 않음
            if (board[dx][dy] == 0) {
                // 방문한적 있는 경우 제외
                if (visited[dx][dy][cnt]) {
                    continue;
                }
                visited[dx][dy][cnt] = visited[x][y][cnt] + 1;
                q.push({cnt, {dx, dy}});
            }

            // 벽인 경우
            if (board[dx][dy] == 1) {
                // 벽을 부술 수 있는 개수를 넘거나 방문한적 있는 경우 제외
                if (cnt >= k || visited[dx][dy][cnt + 1]) {
                    continue;
                }
                visited[dx][dy][cnt + 1] = visited[x][y][cnt] + 1;
                q.push({cnt + 1, {dx, dy}});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}