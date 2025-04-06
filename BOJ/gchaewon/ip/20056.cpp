#include <cmath>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, p, k;

struct Ball {
    int r, c, m, s, d;
};

vector<pair<int, int>> dir = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                              {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

vector<Ball> balls;

void combine(int r, int c, vector<Ball> temp, vector<Ball> &newBalls) {
    int sum_m = 0, sum_s = 0; // 합친 질량, 속력
    int even = 0, odd = 0;    // 방향 짝수 개수, 홀수 개수
    int d = 0; // 나눌 공의 방향 시작 (짝수는 0, 홀수는 1)

    for (auto b : temp) {
        sum_m += b.m;
        sum_s += b.s;

        if (b.d % 2 == 0) {
            even += 1;
        } else {
            odd += 1;
        }
    }
    // 모두 짝수이거나, 홀수이지 않는 경우
    if (even != 0 && odd != 0) {
        d = 1;
    }

    int new_m = floor(sum_m / 5);
    int new_s = floor(sum_s / temp.size());

    if (new_m == 0) {
        return;
    }

    for (int i = 0; i < 4; i++, d += 2) {
        newBalls.push_back({r, c, new_m, new_s, d});
    }
}
void move() {
    // a[i][j] = (i,j)에 있는 공
    vector<vector<vector<Ball>>> a(n, vector<vector<Ball>>(n));
    vector<Ball> newBalls;

    // 공 이동
    for (auto &b : balls) {
        b.r += dir[b.d].X * (b.s % n);
        b.c += dir[b.d].Y * (b.s % n);

        if (b.r < 0) {
            b.r += n;
        }
        if (b.r >= n) {
            b.r -= n;
        }
        if (b.c < 0) {
            b.c += n;
        }
        if (b.c >= n) {
            b.c -= n;
        }
        a[b.r][b.c].push_back(b);
    }

    // 공 2개 이상 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = a[i][j].size();
            // 공이 없는 위치 넘어김
            if (cnt == 0) {
                continue;
            }
            // 공이 1개인 경우 병합 X
            if (cnt == 1) {
                newBalls.push_back(a[i][j][0]);
                continue;
            }
            // 공 2개 이상이면 병합
            combine(i, j, a[i][j], newBalls);
        }
    }
    balls = newBalls;
}

int main() {
    int ans = 0;
    cin >> n >> p >> k;

    for (int i = 0; i < p; i++) {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        balls.push_back({x - 1, y - 1, m, s, d});
    }

    while (k--) {
        move();
    }

    for (auto ball : balls) {
        ans += ball.m;
    }

    cout << ans;

    return 0;
}
