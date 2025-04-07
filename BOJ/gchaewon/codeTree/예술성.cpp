#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, t = 3, total_score = 0;
int a[33][33], ga[33][33], visited[33][33], temp[33][33];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = a[i][j];
        }
    }
}
// 그룹 구하기 위한 bfs
int bfs(pair<int, int> start, int num, int idx) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.X][start.Y] = 1;
    int area = 0;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        ga[x][y] = idx;

        area++;
        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            // 범위 벗어남 or 방문한 곳 or 해당 그룹이 아닌 곳
            if (dx < 0 || dx == n || dy < 0 || dy == n || visited[dx][dy] ||
                a[dx][dy] != num) {
                continue;
            }

            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }
    return area;
}

// 그룹 지도를 기반으로 맞닿은 다른 그룹 값 계산하는 함수
void bfs2(pair<int, int> start, vector<pair<int, int>> groups) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.X][start.Y] = 1;

    int cur_idx = ga[start.X][start.Y];
    int g_size = groups.size();
    map<int, int>
        near_cnt; // near_cnt[group_idx] = group_idx와 현재 그룹 맞닿은 변

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            // 범위 벗어남 or 방문한 곳
            if (dx < 0 || dx == n || dy < 0 || dy == n || visited[dx][dy]) {
                continue;
            }
            // 해당 그룹이 아닌 곳
            int group_idx = ga[dx][dy];
            if (group_idx != cur_idx) {
                near_cnt[group_idx]++; // 맞닿은 변 개수 업데이트
                continue;
            }
            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }

    // 저장한 인근 그룹 값 계산
    for (auto near : near_cnt) {
        int group_idx = near.first;

        int temp_score = (groups[cur_idx].second +
                          groups[group_idx].second) // a 칸수 + b칸수
                         * groups[cur_idx].first    // a를 이루는 숫자값
                         * groups[group_idx].first  // b를 이루는 숫자값
                         * near.second;             // 맞닿은 개수
        total_score += temp_score;                  // 점수 업데이트
    }
}

void getScore() {
    // 그룹 구하기
    vector<pair<int, int>> groups; // {그룹 숫자 값, 그룹의 칸 수}
    memset(visited, 0, sizeof(visited));
    memset(ga, 0, sizeof(ga));
    int score = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }
            int cnt = bfs({i, j}, a[i][j],
                          groups.size()); // 인접한 같은 숫자 칸 수 구하기
            groups.push_back({a[i][j], cnt});
        }
    }

    // bfs로 ga 돌면서 점수 업데이트
    memset(visited, 0, sizeof(visited));
    int is_used[groups.size()]; // 점수 업데이트 여부 저장

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] && is_used[ga[i][j]]) {
                continue;
            }
            is_used[ga[i][j]] = 1;
            bfs2({i, j}, groups);
        }
    }
}

// 작은 사각형 90도 회전 함수
void turnRect(int sx, int sy, int ex, int ey) {
    int len = ex - sx + 1; // 사각형 한 변 길이

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            a[sx + j][sy + len - 1 - i] = temp[sx + i][sy + j];
        }
    }
}

void turnSimulator() {
    copy();
    // 십자 모양 회전
    // 세로 기둥
    int h = n / 2;
    for (int i = 0; i < h; i++) {
        a[i][h] = temp[h][n - i - 1];
        a[n - i - 1][h] = temp[h][i];
    }
    // 가로 기둥
    for (int i = 0; i < n; i++) {
        if (i == h) {
            continue;
        }
        a[h][i] = temp[i][h];
    }

    // 4개 네모 회전
    // 1 2
    // 3 4
    turnRect(0, 0, h - 1, h - 1);
    turnRect(0, h + 1, h - 1, n - 1);
    turnRect(h + 1, 0, n - 1, h - 1);
    turnRect(h + 1, h + 1, n - 1, n - 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    getScore();

    while (t--) { // 3회
        turnSimulator();
        getScore();
    }

    cout << total_score;

    return 0;
}
