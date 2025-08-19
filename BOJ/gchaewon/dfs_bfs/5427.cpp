#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int w, h, t;
int start_x, start_y;
int board[1004][1004];
int visited_f[1004][1004];
int visited_s[1004][1004];

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;

int bfs(int option) {
    // 상근이면 초기 위치 저장
    if (option) {
        q.push({start_x, start_y});
        visited_s[start_x][start_y] = 1;
    }

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            // 범위 넘어 가는 경우
            if (dx < 0 || dx >= h || dy < 0 || dy >= w) {
                // 상근이의 경우 탈출 성공, 시간 리턴
                if (option) {
                    return visited_s[x][y];
                }
                continue;
            }
            // 벽인 경우 제외
            if (board[dx][dy] == '#') {
                continue;
            }

            // 상근인 경우
            if (option) {
                // 방문한 적 있거나, 불보다 늦게 도착하는 경우 제외
                if (visited_s[dx][dy] ||
                    (visited_s[x][y] + 1 >= visited_f[dx][dy] &&
                     visited_f[dx][dy] != 0)) {
                    continue;
                }
                q.push({dx, dy});
                visited_s[dx][dy] = visited_s[x][y] + 1;
            } else { // 불의 경우
                // 방문한 적 있으면 제외
                if (visited_f[dx][dy]) {
                    continue;
                }
                q.push({dx, dy});
                visited_f[dx][dy] = visited_f[x][y] + 1;
            }
        }
    }
    return 0;
}
int main() {
    cin >> t;

    while (t--) {
        cin >> w >> h;
        string line;

        // 배열, 큐 초기화
        memset(visited_f, 0, sizeof(visited_f));
        memset(visited_s, 0, sizeof(visited_s));

        while (!q.empty()) {
            q.pop();
        }

        for (int i = 0; i < h; i++) {
            cin >> line;
            for (int j = 0; j < w; j++) {
                board[i][j] = line[j];
                // 상근 시작 위치 저장
                if (board[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
                // 불 위치 큐에 저장
                if (board[i][j] == '*') {
                    q.push({i, j});
                    visited_f[i][j] = 1;
                }
            }
        }

        // 불 이동
        bfs(0);
        // 큐 초기화
        while (!q.empty()) {
            q.pop();
        }

        // 상근 이동
        int ans = bfs(1);

        // 탈출 성공시 시간 출력
        if (ans) {
            cout << ans << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}