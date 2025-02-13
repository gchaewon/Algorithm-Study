#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
using namespace std;

int N;
vector<vector<int>> v(101, vector<int>(101, 0));
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(pair<int, int> start, int height, vector<vector<int>> &m) {
    queue<pair<int, int>> q;
    m[start.X][start.Y] = 0;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;
            if (dx < 0 || dx >= N || dy < 0 || dy >= N) {
                continue;
            }
            if (m[dx][dy] >= height) {
                m[dx][dy] = 0;
                q.push({dx, dy});
            }
        }
    }
}
int main() {
    cin >> N;
    int min_h = 100;
    int max_h = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            max_h = max(max_h, v[i][j]);
            min_h = min(min_h, v[i][j]);
        }
    }

    for (int h = min_h; h <= max_h; h++) {
        int count = 0;
        vector<vector<int>> m = v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (m[i][j] >= h) {
                    bfs({i, j}, h, m);
                    count++;
                }
            }
        }
        ans = max(ans, count);
    }

    cout << ans;
    return 0;
}