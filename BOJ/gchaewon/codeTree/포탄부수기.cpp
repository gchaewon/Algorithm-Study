#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m, k, remain = 0, t = 0;
int a[14][14], visited[14][14], active[14][14];

struct Bomb {
    int X, Y;
    int power;       // 공격력
    int last_attack; // 최근 공격한 시점
    int id;          // 포탑 고유 번호 (0부터 시작)
};

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 우 하 좌 상

vector<Bomb> bombs;

// 약한 포탑 찾기용 정렬
bool cmp(Bomb &A, Bomb &B) {
    // 1. 공격력 오름차순
    if (A.power != B.power) {
        return A.power < B.power;
    }
    // 2. 최근 공격 포탑 (최근 공격시점 내림차순)
    if (A.last_attack != B.last_attack) {
        return A.last_attack > B.last_attack;
    }
    // 3. 행, 열 합 내림차순
    if ((A.X + A.Y) != (B.X + B.Y)) {
        return (A.X + A.Y) > (B.X + B.Y);
    }
    // 4. 열 내림차순
    return A.Y > B.Y;
}

int getAttacker() {
    int attacker = -1;
    vector<Bomb> sorted = bombs;

    sort(sorted.begin(), sorted.end(), cmp); // 공격자 선정 4가지로 정렬

    // 0은 제외
    for (int i = 0; i < sorted.size(); i++) {
        if (sorted[i].power > 0) {
            attacker = sorted[i].id;
            break;
        }
    }

    // 공격자 포탑 공격 시점 업데이트
    bombs[attacker].last_attack = t;
    active[bombs[attacker].X][bombs[attacker].Y] = 1;
    return attacker;
}

int getDepenser() {
    int depenser = -1;
    vector<Bomb> sorted = bombs;

    sort(sorted.begin(), sorted.end(), cmp); // 약한 포탑 구하기로 정렬

    depenser = sorted.back().id;
    active[bombs[depenser].X][bombs[depenser].Y] = 1;
    return depenser;
}

bool raiserAttack(int attacker, int depenser) {
    bool is_successed = false;

    int sx = bombs[attacker].X;
    int sy = bombs[attacker].Y;
    int ex = bombs[depenser].X;
    int ey = bombs[depenser].Y;

    vector<vector<pair<int, int>>> path(
        n, vector<pair<int, int>>(m)); // {이전 이동 경로 저장}

    queue<pair<int, int>> q;
    q.push({sx, sy});

    memset(visited, 0, sizeof(visited));
    visited[sx][sy] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        // 공격 대상까지 최단거리를 찾은 경우 종료
        if (x == ex && y == ey) {
            is_successed = true;
            break;
        }

        for (auto d : dir) {
            int dx = (x + d.X + n) % n;
            int dy = (y + d.Y + m) % m;

            // 방문한 적 있음 or 부서진 포탑 위치
            if (visited[dx][dy] != 0 || a[dx][dy] == 0) {
                continue;
            }
            visited[dx][dy] = visited[x][y] + 1;
            path[dx][dy] = {x, y}; // 경로 업데이트
            q.push({dx, dy});
        }
    }
    // 최단 경로 못찾은 경우 조기 리턴
    if (!is_successed) {
        return is_successed;
    }

    // 공격 시작
    // 1) 공격 대상
    a[ex][ey] = max(a[ex][ey] - bombs[attacker].power, 0); // 공격력 업데이트

    // 2) 경로에 있는 포탑 (공격받은 탑 -> 공격한 탑까지 경로 탐색)
    int dx = path[ex][ey].X;
    int dy = path[ex][ey].Y;
    while (true) {
        if (dx == sx && dy == sy) {
            break;
        }

        a[dx][dy] = max(a[dx][dy] - bombs[attacker].power / 2, 0);

        // 공격 관여여부 업데이트
        active[dx][dy] = 1;

        int temp_x = path[dx][dy].X;
        int temp_y = path[dx][dy].Y;
        dx = temp_x;
        dy = temp_y;
    }
    return is_successed;
}

void bombAttack(int attacker, int depenser) {
    int x = bombs[depenser].X;
    int y = bombs[depenser].Y;

    // 공격 대상
    a[x][y] = max(a[x][y] - bombs[attacker].power, 0);

    // 주변 8칸
    vector<pair<int, int>> dirs = {{1, 0},   {0, 1}, {-1, 0}, {0, -1},
                                   {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    for (auto d : dirs) {
        int dx = (x + d.X + n) % n;
        int dy = (y + d.Y + m) % m;

        // 공격자라면 건너뜀
        if (dx == bombs[attacker].X && dy == bombs[attacker].Y) {
            continue;
        }
        // 부서진 포탄이면 제외
        if (a[dx][dy] == 0) {
            continue;
        }
        a[dx][dy] = max(a[dx][dy] - bombs[attacker].power / 2, 0);
        active[dx][dy] = 1; // 공격 관여 여부 업데이트
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                int id = bombs.size();
                bombs.push_back({i, j, a[i][j], 0, id});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        t++;
        memset(active, 0, sizeof(active));
        // 1. 공격자 선정
        int attacker = getAttacker();

        // 2. 공격자의 공격
        // 2-0 공격 대상 선정
        int depenser = getDepenser();

        // 공격자 power 업데이트
        a[bombs[attacker].X][bombs[attacker].Y] += (n + m);
        bombs[attacker].power += (n + m);

        // 2-1. 레이저 공격 시도
        bool is_successed = raiserAttack(attacker, depenser);
        if (!is_successed) {
            // 2-2. 실패 시 포탄 공격
            bombAttack(attacker, depenser);
        }

        // 3. 포탑 부서짐
        remain = 0;

        // 공격력 변화, 폭탄에 반영하기
        for (auto &bomb : bombs) {
            bomb.power = a[bomb.X][bomb.Y];
            if (bomb.power > 0) {
                remain += 1;
            }
        }

        // 3-1. 부서지지 않은 포탑 수가 1개라면 종료
        if (remain <= 1) {
            break;
        }

        // 4. 포탑 정비
        for (auto &bomb : bombs) {
            if (bomb.power == 0) {
                continue;
            }
            // 공격에 관여 X
            if (!active[bomb.X][bomb.Y]) {
                bomb.power += 1;
                a[bomb.X][bomb.Y] = bomb.power;
            }
        }
    }

    // 공격 끝나고 제일 공격력 높은 포탄 출력
    sort(bombs.begin(), bombs.end(), cmp);

    cout << bombs.back().power;

    return 0;
}
