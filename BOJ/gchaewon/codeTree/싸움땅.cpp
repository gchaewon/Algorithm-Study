#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

struct Player {
    int x, y;
    int d, s;
    int num; // 플레이어 번호 (1~M) 저장
    int gun; // 플레이어가 가진 총의 공격력 (없으면 0)
    int point;
};

int n, m, k;
int pa[24][24]; // 플레이어 번호 (1~M) 저장 (없으면 0)

// n*n 격자, 각 칸에 여러 개의 총 (공격력 높은 순) 우선순위큐에 저장
vector<vector<priority_queue<int>>> a(24, vector<priority_queue<int>>(24));

vector<Player> players;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 북동남서

// 싸우는 플레이어 정렬 (이긴사람 선)
bool cmp(Player &A, Player &B) {
    int a_score = A.gun + A.s;
    int b_score = B.gun + B.s;

    // 수치가 같은 경우, 초기 능력치 높은 순
    if (a_score == b_score) {
        return A.s > B.s;
    }
    // 수치 높은 순으로 정렬
    return A.gun + A.s > B.gun + B.s;
}

// 방향대로 한 칸 이동
void move(Player &player) {
    int x = player.x;
    int y = player.y;

    // 이동한 플레이어 지우기
    pa[x][y] = 0;

    int dx = x + dir[player.d].X;
    int dy = y + dir[player.d].Y;

    // 격자를 벗어나는 경우 정반대 방향으로 이동
    if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
        // 방향 변경
        player.d = (player.d + 2) % 4; // 북(0)->남(2), 동(1)->서(3)
        // 이동
        dx = x + dir[player.d].X;
        dy = y + dir[player.d].Y;
    }
    // player 위치 값 업데이트
    player.x = dx;
    player.y = dy;
}

void loserMove(Player &player) {
    int x = player.x;
    int y = player.y;
    int dx = -1, dy = -1;
    bool flag = false;

    // 가능한 칸 도달까지 시계방향 회전
    for (int i = 0; i < 4; i++) {
        dx = x + dir[(player.d + i) % 4].X;
        dy = y + dir[(player.d + i) % 4].Y;

        // 범위를 벗어나지 않고, 다른 플레이어가 없는 경우 이동 가능
        if (0 <= dx && dx < n && 0 <= dy && dy < n && pa[dx][dy] == 0) {
            player.d = (player.d + i) % 4; // 방향 업데이트
            player.x = dx;                 // 위치 업데이트
            player.y = dy;
            flag = true;
            break;
        }
    }

    // 이동 가능한 칸이 있는 경우
    if (flag) {
        pa[dx][dy] = player.num; // 새 위치 확정

        // 이동한 칸에 총이 있다면, 가장 공격력 높은 총 획득
        if (a[dx][dy].size() != 0) {
            player.gun = a[dx][dy].top();
            a[dx][dy].pop();
        }
    }
}

void goRound() {
    for (auto &player : players) {
        // 1-1. 이동
        move(player);
        int x = player.x;
        int y = player.y;

        // 2-1. 이동한 위치에 다른 플레이어 없는 경우
        if (pa[x][y] == 0) {
            // 이동 확정
            pa[x][y] = player.num;

            // 총 있는 경우
            if (a[x][y].size() != 0) {
                int cur_gun = player.gun;

                // 가지고 있는 총보다 큰 경우 (없는 경우 포함), 업데이트
                if (cur_gun < a[x][y].top()) {
                    player.gun = a[x][y].top();
                    a[x][y].pop();

                    // 가지고 있는 총이 있다면, 내려놓기
                    if (cur_gun != 0) {
                        a[x][y].push(cur_gun);
                    }
                }
            }
            continue;
        }

        // 2-2-1. 이동한 위치에 다른 플레이어 있는 경우
        if (pa[x][y] != 0) {
            vector<Player> fight = {player, players[pa[x][y] - 1]};
            sort(fight.begin(), fight.end(), cmp);

            int winner = fight[0].num - 1;
            int loser = fight[1].num - 1;

            // 이긴 플레이어 포인트 획득
            players[winner].point += (players[winner].s + players[winner].gun) -
                                     (players[loser].s + players[loser].gun);

            // 2-2-2. 진 플레이어 이동
            if (players[loser].gun) {
                // 가진 총 내려놓음
                a[x][y].push(players[loser].gun);
                players[loser].gun = 0;
            }
            loserMove(players[loser]); // 원래 방향대로 한 칸 이동

            // 2-2-3. 이긴 플레이어
            pa[x][y] = winner + 1; // 위치 확정

            // 이긴 칸에 총이 있고, 더 공격력이 높은 총이 있다면
            if (a[x][y].size() != 0 && players[winner].gun < a[x][y].top()) {
                int temp = players[winner].gun;
                players[winner].gun = a[x][y].top(); // 총 업데이트
                a[x][y].pop();                       // 격자에서 삭제
                a[x][y].push(temp); // 플레이어 총을 격자에 추가
            }
        }
    }
}
int main() {
    cin >> n >> m >> k;

    // 총 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int power;
            cin >> power;
            if (power == 0) {
                continue;
            }
            a[i][j].push(power);
        }
    }

    // 플레이어 입력
    for (int i = 0; i < m; i++) {
        int x, y, d, s;
        cin >> x >> y >> d >> s;
        players.push_back(
            {x - 1, y - 1, d, s, i + 1, 0, 0}); // 위치 0번부터 시작
        // 맵에 플레이어 번호 저장 (1~m-1)
        pa[x - 1][y - 1] = i + 1;
    }

    // 라운드 수행
    while (k--) {
        goRound();
    }

    // 플레이어가 얻은 점수 출력
    for (auto player : players) {
        cout << player.point << " ";
    }

    return 0;
}