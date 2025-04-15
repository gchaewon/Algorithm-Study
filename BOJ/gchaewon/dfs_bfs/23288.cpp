#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second

int n, m, k, ans = 0;
int a[24][24], visited[24][24];

vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // 서북동남
vector<int> dice1 = {4, 1, 3, 6}; // 서,동 이동시 사용, dice1[3] = 바닥 값
vector<int> dice2 = {2, 1, 5, 6}; // 북,남 이동시 시용, dice2[3] = 바닥 값

struct Dice {
    int d; // 현재 주사위 이동 방향, 0=서, 1=북, 2=동, 3=남
    int x, y;
};
Dice dice = {2, 0, 0};

// bfs로 주변 연속 이동 가능한 칸 수
int getScore(pair<int, int> start) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    int b = 1;

    q.push(start);
    visited[start.X][start.Y] = 1;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy]) {
                continue;
            }
            if (a[dx][dy] != a[start.X][start.Y]) {
                continue;
            }

            b += 1;
            visited[dx][dy] = 1;
            q.push({dx, dy});
        }
    }

    return a[start.X][start.Y] * b;
}

void siimulator() {
    // 1. 한 칸 이동
    int dx = dice.x + dir[dice.d].X;
    int dy = dice.y + dir[dice.d].Y;

    // 이동 불가한 경우 방향 수정
    if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
        dice.d = (dice.d + 2) % 4; // 반대 방향으로 바꾸기
    }
    // 위치 업데이트
    dx = dice.x + dir[dice.d].X;
    dy = dice.y + dir[dice.d].Y;
    dice.x = dx;
    dice.y = dy;

    // 주사위 업데이트
    int d = dice.d;
    vector<int> temp;
    switch (d) {
    case 0: // 서
        temp = dice1;
        for (int i = 0; i < 3; i++) {
            dice1[i] = temp[i + 1];
        }
        dice1[3] = temp[0];
        // 세로 방향 업데이트
        dice2[1] = dice1[1];
        dice2[3] = dice1[3];
        break;
    case 1: // 북
        temp = dice2;
        for (int i = 0; i < 3; i++) {
            dice2[i] = temp[i + 1];
        }
        dice2[3] = temp[0];
        // 가로 방향 업데이트
        dice1[1] = dice2[1];
        dice1[3] = dice2[3];
        break;
    case 2: // 동
        temp = dice1;
        for (int i = 3; i > 0; i--) {
            dice1[i] = temp[i - 1];
        }
        dice1[0] = temp[3];
        // 세로 방향 업데이트
        dice2[1] = dice1[1];
        dice2[3] = dice1[3];
        break;
    case 3: // 남
        temp = dice2;
        for (int i = 3; i > 0; i--) {
            dice2[i] = temp[i - 1];
        }
        dice2[0] = temp[3];
        // 가로 방향 업데이트
        dice1[1] = dice2[1];
        dice1[3] = dice2[3];
        break;
    }

    // 2. 점수 획득
    ans += getScore({dx, dy});

    // 3. 다음 방향 결정
    int bottom = 0;
    if (d == 0 || d == 2) {
        bottom = dice1[3];
    } else {
        bottom = dice2[3];
    }

    if (bottom > a[dx][dy]) { // 시계
        dice.d += 1;
        if (dice.d >= 4) {
            dice.d = 0;
        }
    } else if (bottom < a[dx][dy]) { // 반시계
        dice.d -= 1;
        if (dice.d < 0) {
            dice.d = 3;
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        siimulator();
    }
    cout << ans;

    return 0;
}
