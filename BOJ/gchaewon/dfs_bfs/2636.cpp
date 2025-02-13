#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
int cnt = 0, area = 0;
int v[101][101];
int visited[101][101];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;   // 탐색할 자리
    queue<pair<int, int>> tmp; // 가장자리 치즈 저장 (다음에 탐색)

    q.push(start);

    while (!q.empty()) {
        area = q.size();
        // 0인 곳은 q에 넣어 탐색하고, 1인곳은 다음에 탐색하게 tmp에 넣음
        while (!q.empty()) {
            int x = q.front().X;
            int y = q.front().Y;
            q.pop();

            for (auto d : dir) {
                int dx = x + d.X;
                int dy = y + d.Y;

                if (dx < 0 || dx >= n || dy < 0 || dy >= m ||
                    visited[dx][dy] == 1) {
                    continue;
                }

                if (v[dx][dy] == 0) {
                    q.push({dx, dy});
                }

                else if (v[dx][dy] == 1) {
                    tmp.push({dx, dy});
                }
                visited[dx][dy] = 1;
            }
        }
        // 가장자리 치즈를 q로 옮김 (다음에 탐색)
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
        cnt++;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    visited[0][0] = 1;
    v[0][0] = 2;
    bfs({0, 0});

    cout << cnt - 1 << "\n";
    cout << area;
    return 0;
}