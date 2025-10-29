#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define X first
#define Y second

using namespace std;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int visited[104][104];
int n = 0, m = 0;

// 최단거리이므로 bfs 사용
int bfs(pair<int, int> start, vector<string> board) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.X][start.Y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        // 목적지 도착한 경우 종료
        if (board[x][y] == 'G') {
            return visited[x][y] - 1;
        }

        for (auto d : dir) {
            int dx = x;
            int dy = y;

            // 벽이나, 장애물 만나기 전까지 한 방향으로 계속 이동
            while (true) {
                dx += d.X;
                dy += d.Y;

                if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                    break;
                }
                if (board[dx][dy] == 'D') {
                    break;
                }
            }
            // 내부 범위로 조정
            dx -= d.X;
            dy -= d.Y;

            // 방문한적 있으면 제외
            if (visited[dx][dy]) {
                continue;
            }
            // 방문처리 후 bfs 탐색
            visited[dx][dy] = visited[x][y] + 1;
            q.push({dx, dy});
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 시작 지점 찾아서 bfs 시작
            if (board[i][j] == 'R') {
                answer = bfs({i, j}, board);
                break;
            }
        }
    }

    return answer;
}