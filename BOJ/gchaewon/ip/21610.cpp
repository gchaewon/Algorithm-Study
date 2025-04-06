#include <iostream>
#include <set>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m;
int a[54][54];
vector<pair<int, int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                              {0, 1},  {1, 1},   {1, 0},  {1, -1}};
vector<pair<int, int>> cdir = {
    {-1, -1}, {-1, 1}, {1, 1}, {1, -1}}; // 대각선 방향

vector<pair<int, int>> cloud; // 현재 구름이 있는 위치
set<pair<int, int>> pre;      // 이전에 구름이 있던 위치

void move(int d, int s) {
    pre.clear();
    // 1. 구름 이동
    for (auto &c : cloud) {
        c.X += ((dir[d].X) * (s % n));
        c.Y += ((dir[d].Y) * (s % n));

        if (c.X < 1) {
            c.X += n;
        }
        if (c.X > n) {
            c.X %= n;
        }
        if (c.Y < 1) {
            c.Y += n;
        }
        if (c.Y > n) {
            c.Y %= n;
        }
        // 2. 물 업데이트
        a[c.X][c.Y] += 1;
        pre.insert({c.X, c.Y});
    }
    // 3. 구름 삭제
    cloud.clear();
}

void magic() {
    // 인근 대각선 물있는 바구니 수만큼 물 양 증가
    for (auto c : pre) {
        int x = c.X;
        int y = c.Y;
        int cnt = 0;

        // 대각선에 물 있는 바구니 개수 구하기
        for (auto cd : cdir) {
            int dx = x + cd.X;
            int dy = y + cd.Y;

            if (dx < 1 || dx > n || dy < 1 || dy > n || a[dx][dy] <= 0) {
                continue;
            }
            cnt++;
        }
        // 물 양 증가
        a[x][y] += cnt;
    }
}

void makeCloud() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 물 양이 2 이상, 이전에 구름이 사라진 칸 아님 (이 조건 아직 없음 )
            if (a[i][j] >= 2 && !(pre.find({i, j}) != pre.end())) {
                cloud.push_back({i, j});
                a[i][j] -= 2;
            }
        }
    }
}

int main() {
    int ans = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // 구름 초기 저장
    cloud.push_back({n, 1});
    cloud.push_back({n, 2});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 1, 2});

    while (m--) {
        int d, s;
        cin >> d >> s;

        move(d - 1, s); // 1, 2, 3 과정
        magic();        // 4 과정
        makeCloud();    // 5 과정
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += a[i][j];
        }
    }
    cout << ans;
    return 0;
}