#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
    int n, m;
    int start_x, start_y, end_x, end_y;
    int ans = 0;
    int visited[304][304];
    char c[304][304];
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    cin >> n >> m;
    cin >> start_x >> start_y >> end_x >> end_y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = 1;

    // 범위 위치에 도달할 때까지 반복
    while (c[end_x][end_y] == '#') {
        ans++;
        queue<pair<int, int>> next;

        while (!q.empty()) {
            int x = q.front().X;
            int y = q.front().Y;
            q.pop();

            // 범인 위치 도달 시 중단
            if (x == end_x && y == end_y) {
                c[x][y] = '0';
                break;
            }

            for (auto d : dir) {
                int dx = x + d.X;
                int dy = y + d.Y;

                if (dx <= 0 || dx > n || dy <= 0 || dy > m || visited[dx][dy]) {
                    continue;
                }
                visited[dx][dy] = 1;

                // 0이 아닌 경우 (1, #) 다음에 방문할 큐에 저장
                if (c[dx][dy] != '0') {
                    c[dx][dy] = '0';
                    next.push({dx, dy});
                } else { // 0인 경우 지금 방문할 큐에 저장
                    q.push({dx, dy});
                }
            }
        }
        // q 다음걸로 갱신
        q = next;
    }

    cout << ans;

    return 0;
}