#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> v(100, vector<int>(100, 0));
int n, m;

void bfs(pair<int, int> start) {
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
            if (v[dx][dy] == 1) {
                q.push({dx, dy});
                v[dx][dy] = v[x][y] + 1;
            }
        }
    }
}
int main() {
    cin >> n >> m;

    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            v[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                bfs({i, j});
                break;
            }
        }
    }

    cout << v[n - 1][m - 1] - 1;

    return 0;
}