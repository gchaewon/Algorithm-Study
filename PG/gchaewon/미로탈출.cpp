#include <cstring>
#include <queue>
#include <string>
#include <vector>
#define X first
#define Y second

using namespace std;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pair<int, int> s, e, l;
int n = 0, m = 0;
int dist[104][104];

int bfs(pair<int, int> start, pair<int, int> end, vector<string> maps) {
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.X][start.Y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        if (x == end.X && y == end.Y) {
            return dist[x][y] - 1;
        }

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }
            if (dist[dx][dy] || maps[dx][dy] == 'X') {
                continue;
            }
            dist[dx][dy] = dist[x][y] + 1;
            q.push({dx, dy});
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                s = {i, j};
                continue;
            }
            if (maps[i][j] == 'E') {
                e = {i, j};
                continue;
            }
            if (maps[i][j] == 'L') {
                l = {i, j};
            }
        }
    }

    int t1 = bfs(s, l, maps);
    if (t1 == -1) {
        return -1;
    }

    int t2 = bfs(l, e, maps);
    if (t2 == -1) {
        return -1;
    }

    answer = t1 + t2;

    return answer;
}