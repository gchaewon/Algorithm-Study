#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;
int n, m;
int a[304][304], visited[304][304], temp[304][304];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 동서남북

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }
}
void melt() {
    copy();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                continue;
            }
            // 빙산이면 주변 0 개수만큼 차감
            int cnt = 0;
            for (auto d : dir) {
                if (temp[i + d.X][j + d.Y] == 0) {
                    cnt++;
                }
            }
            a[i][j] = max(temp[i][j] - cnt, 0);
        }
    }
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.X][start.Y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy] ||
                a[dx][dy] == 0) {
                continue;
            }

            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }
}

int getArea() {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && !visited[i][j]) {
                bfs({i, j});
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int t = 1, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        melt();
        cnt = getArea();
        if (cnt >= 2 || cnt == 0) { // 나뉘어지거나, 다 녹았다면 중지
            break;
        }
        t++;
    }

    // 다 녹을 때까지 덩이 개수가 2 이상이면 시간 출력
    if (cnt) {
        cout << t;
    } else {
        cout << 0;
    }

    return 0;
}