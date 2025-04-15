#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m;
vector<pair<int, int>> dir = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}}; // 상 좌 우 하 순서
int a[19][19]; // n * n 격자, 0 빈공간, 1 베이스캠프, 2 편의점, -1 방문할 수
               // 없는 경우
int visited[19][19];

vector<pair<int, int>> players; // 플레이어 위치, {x, y} 0부터 시작
vector<pair<int, int>> conbs;   // 편의점 위치
vector<pair<int, int>> camps;   // 베이스 캠프 위치
set<pair<int, int>> cantgos;    // 지나갈 수 없는 위치 임시 저장
int is_finished[34]; // is_finished[플레이어번호] = 플레이어가 끝났는지 여부
                     // 저장

bool check() {
    bool is_valid = true;
    // 플레이어 중 한 명이라도 도착 못한게 있다면 검사 종료
    for (int i = 0; i < m; i++) {
        if (!is_finished[i]) {
            is_valid = false;
            return is_valid;
        }
    }
    return is_valid;
}

void move(int idx) { // 플레이어 번호
    // idx 플레이어 현재 위치 -> 타겟 편의점까지 상 좌 우 하 방향으로 bfs해서
    // 거리 구하기 이후 최단 거리 방향 구하기 (같다면, 방향 오름차순)
    vector<pair<int, int>> dist; // {거리, 이동방향}

    for (int i = 0; i < 4; i++) {
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        pair<int, int> start = {players[idx].X + dir[i].X,
                                players[idx].Y + dir[i].Y};

        // 한 칸 이동했을 때 가능 범위 벗어난다면 INT_MAX 처리
        if (start.X < 0 || start.Y >= n || start.Y < 0 || start.Y >= n ||
            a[start.X][start.Y] == -1) {
            dist.push_back({INT_MAX, i});
            continue;
        }

        // 한 칸 이동했을 때 바로 편의점이라면 바로 추가
        if (start.X == conbs[idx].X && start.Y == conbs[idx].Y) {
            dist.push_back({1, i});
            continue;
        }

        q.push(start);
        visited[start.X][start.Y] = 1;

        while (!q.empty()) {
            int x = q.front().X;
            int y = q.front().Y;
            q.pop();

            if (x == conbs[idx].X && y == conbs[idx].Y) {
                dist.push_back({visited[x][y], i});
                break;
            }

            for (auto d : dir) {
                int dx = x + d.X;
                int dy = y + d.Y;

                if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy] ||
                    a[dx][dy] == -1) {
                    continue;
                }
                visited[dx][dy] = visited[x][y] + 1;
                q.push({dx, dy});
            }
        }
    }

    sort(dist.begin(), dist.end()); // 이동거리 - 방향 번호 오름차순 정렬,
    int newd =
        dist[0].second; // 가장 이동거리가 작고, 우선순위가 높은 방향 선택

    // 1. 한 칸 이동
    int dx = players[idx].X + dir[newd].X;
    int dy = players[idx].Y + dir[newd].Y;
    players[idx] = {dx, dy}; // 위치 갱신

    // 2. 만약 편의점에 도착한다면
    if (dx == conbs[idx].X && dy == conbs[idx].Y) {
        is_finished[idx] = 1;     // 완료 처리
        cantgos.insert({dx, dy}); // 이동 불가 임시 저장
    }
}

void findCamp(int idx) { // 플레이어 번호
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    vector<pair<int, int>> tempCamps;
    int min_dist = INT_MAX;

    // idx번 플레이어의 타겟 편의점 -> 근처 베이스 캠프까지 bfs해서 최단거리
    // 찾기
    q.push(conbs[idx]);
    visited[conbs[idx].X][conbs[idx].Y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        // 베이스 캠프를 찾았다면
        if (a[x][y] == 1) {
            // 거리가 최단이라면 갱신
            if (visited[x][y] < min_dist) {
                if (tempCamps.size()) {
                    tempCamps.pop_back();
                }
                tempCamps.push_back({x, y});
                min_dist = visited[x][y];
            }
            // 최단거리와 같다면 추가
            else if (visited[x][y] == min_dist) {
                tempCamps.push_back({x, y});
            } else {
                break;
            }
        }
        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy] ||
                a[dx][dy] == -1 ||
                cantgos.find({dx, dy}) !=
                    cantgos.end()) { // 갈 수 없는 임시 위치에 저장된 곳도 제외
                                     // (다음 턴에 이동 불가 -> 최단 거리 안 됨)
                continue;
            }
            visited[dx][dy] = visited[x][y] + 1;
            q.push({dx, dy});
        }
    }

    sort(tempCamps.begin(), tempCamps.end()); // 행, 열 기준 오름차순 정렬
    int dx = tempCamps[0].X;
    int dy = tempCamps[0].Y;

    players[idx] = {dx, dy};  // 플레이어 위치 갱신
    cantgos.insert({dx, dy}); // 이동 불가 위치 임시 저장
}

void update() {
    for (auto c : cantgos) {
        a[c.X][c.Y] = -1;
    }
}

int main() {
    int t = 0;
    cin >> n >> m;

    // 베이스 캠프 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                camps.push_back({i, j});
            }
        }
    }
    // 편의점 입력
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        conbs.push_back({x, y});
        a[x][y] = 2; // 지도에 표시

        // 사람 초기화
        players.push_back({-1, -1});
    }

    bool flag = false;

    // while(t<7){
    while (true) {
        // m분 초과면 종료 조건 만족하는지 확인
        cantgos.clear();
        if (t > m) {
            flag = check();
        }
        if (flag) {
            break;
        }
        // 각 플레이어 이동
        for (int i = 0; i < m; i++) {
            // 이미 편의점 도달한 플레이어 제외
            if (is_finished[i]) {
                continue;
            }
            // 베이스 캠프 이미 찾은 경우
            if (t > i) {
                move(i);
            }
            // 베이스 캠프 찾기
            else if (t == i) {
                findCamp(i);
            }
            // 아직 시간이 안된 플레이어 만날 시 종료
            else {
                break;
            }
        }
        // 임시 저장한 이동 불가 칸 업데이트
        update();
        t++;
    }

    cout << t;
    return 0;
}