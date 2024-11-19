#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int M, N;
vector<vector<int>> v(100, vector<int>(100, 1));
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<int> ans;

void bfs(pair<int, int> start) {
    int count = 0;
    queue<pair<int, int>> q;
    v[start.X][start.Y] = 2;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        v[x][y] = 2;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= M || dy < 0 || dy >= N) {
                continue;
            }
            if (v[dx][dy] == 1) {
                v[dx][dy] = 2;
                q.push({dx, dy});
                count++;
            }
        }
    }
    ans.push_back(count);
}
int main() {
    int K;
    cin >> M >> N >> K;

    while (K--) {
        int start_x, start_y, end_x, end_y;
        cin >> start_y >> start_x >> end_y >> end_x;

        for (int i = start_x; i < end_x; i++) {
            for (int j = start_y; j < end_y; j++) {
                v[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 1) {
                bfs({i, j});
            }
        }
    }

    cout << ans.size() << "\n";

    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a + 1 << " ";
    }
    return 0;
}