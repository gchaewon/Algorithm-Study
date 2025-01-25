#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
using namespace std;

int m, n;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(pair<int, int> start, vector<vector<int>> &v) {
    queue<pair<int, int>> q;
    q.push(start);
    v[start.X][start.Y] = 2;

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
            if (v[dx][dy] != 1) {
                continue;
            }
            q.push({dx, dy});
            v[dx][dy] = 2;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> v(50, vector<int>(50, 0));
        int k;
        int ans = 0;
        cin >> m >> n >> k;

        while (k--) {
            int x, y;

            cin >> y >> x;
            v[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    bfs({i, j}, v);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}