#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define X first
#define Y second
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int sx = 104, sy = 104, ex = 0, ey = 0;
int map[104][104];
int visited[104][104];

void makeOutline(vector<int> r) {
    for (int i = r[1] * 2 + 1; i < r[3] * 2; i++) {
        for (int j = r[0] * 2 + 1; j < r[2] * 2; j++) {
            map[i][j] = 0;
        }
    }
}

int bfs(int cx, int cy, int ix, int iy) {
    queue<pair<int, int>> q;
    q.push({cx, cy});
    visited[cx][cy] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        // 아이템 위치 도달 시 종료
        if (x == ix && y == iy) {
            return visited[x][y];
        }

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            // 범위 벗어나거나, 방문한적 있거나, 테두리가 아닌 경우 제외

            if (dx < 0 || dy < 0 || dx > ex || dy > ey || visited[dx][dy] ||
                map[dx][dy] != 1) {
                continue;
            }

            visited[dx][dy] = visited[x][y] + 1;
            q.push({dx, dy});
        }
    }
    return -1;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY,
             int itemX, int itemY) {
    int answer = 0;

    // 1. 직사각형인 부분 1로 채우기, 2배 맵
    for (auto r : rectangle) {
        sx = min(sx, r[1] * 2);
        sy = min(sy, r[0] * 2);
        ex = max(ex, r[3] * 2);
        ey = max(ey, r[2] * 2);

        // 1로 채우기
        for (int i = r[1] * 2; i <= r[3] * 2; i++) {
            for (int j = r[0] * 2; j <= r[2] * 2; j++) {
                map[i][j] = 1;
            }
        }
    }

    // 2. 사각형 주변 테두리 따기 (0으로 빼기)
    for (auto r : rectangle) {
        makeOutline(r);
    }

    // 3. 시작 -> 아이템 위치까지 경로 찾기
    answer = bfs(characterY * 2, characterX * 2, itemY * 2, itemX * 2) - 1;
    answer /= 2;

    return answer;
}