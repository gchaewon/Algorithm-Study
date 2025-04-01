#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int n;                     // 공간 크기
int s = 2, t = 0, cnt = 0; // 상어 크기, 지난 시간, 잡아먹은 물고기수
int a[24][24], visited[24][24];
vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

struct fish {
    int x, y; // 위치
    int d;    // 거리
};

bool cmp(fish a, fish b) {
    // 1. 거리기준 오름차순 (가장 가까운)
    if (a.d == b.d) {
        // 2. x 좌표기준 오름차순 (가장 위)
        if (a.x == b.x) {
            // 3. y 좌표 기준 오름차순 (가장 왼쪽)
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    return a.d < b.d;
}

vector<fish> bfs(pair<int, int> start) {
    vector<fish> fishes;
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    q.push(start);
    visited[start.X][start.Y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n || a[dx][dy] > s ||
                visited[dx][dy]) {
                continue;
            }
            visited[dx][dy] = visited[x][y] + 1;
            q.push({dx, dy});

            if (a[dx][dy] != 0 && a[dx][dy] < s) {
                fishes.push_back({dx, dy, visited[dx][dy]});
            }
        }
    }
    return fishes;
}

int main() {
    cin >> n;
    int sx, sy; // 상어 위치

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                sx = i;
                sy = j;
                a[i][j] = 0;
            }
        }
    }

    while (true) {
        // 주변 물고기 찾기
        vector<fish> fishes = bfs({sx, sy});

        // 물고기 없으면 종료
        if (!fishes.size()) {
            break;
        } else {
            sort(fishes.begin(), fishes.end(), cmp);
            fish next = fishes[0];
            t += next.d - 1; // 시간 증가
            cnt++;           // 잡은 물고기 수 증가
            sx = next.x;     // 상어 위치 옮기기
            sy = next.y;
            a[sx][sy] = 0; // 잡아먹은 물고기 맵에서 지우기

            if (s == cnt) {
                s += 1;
                cnt = 0;
            }
        }
    }

    cout << t;

    return 0;
}