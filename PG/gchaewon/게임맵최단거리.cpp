#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int n, m;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<vector<int>> &maps) {
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    maps[0][0] = -1; // 방문처리;
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;

        q.pop();
        maps[x][y] = -1;

        if (x == n - 1 && y == m - 1) {
            return dist[x][y];
        }

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }

            if (maps[dx][dy] != 1) {
                continue;
            }
            // 큐에 넣기 전 방문처리하여, for문 수행 중 위치가 중복으로 들어가지
            // 않도록 함 (효율성)
            maps[dx][dy] = -1;
            dist[dx][dy] = dist[x][y] + 1;
            q.push({dx, dy});
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();

    answer = bfs(maps);

    return answer;
}