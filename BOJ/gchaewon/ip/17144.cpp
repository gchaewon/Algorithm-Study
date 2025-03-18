#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
int x1 = -1, x2 = -1;
int a[54][54], temp[54][54];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void copy() {
    memset(temp, 0, sizeof(temp));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            temp[i][j] = a[i][j];
        }
    }
}

void move() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] > 0) {
                int cnt = 0;
                for (auto d : dir) {
                    int dx = i + d.first;
                    int dy = j + d.second;

                    if (dx <= 0 || dx > r || dy <= 0 || dy > c ||
                        a[dx][dy] == -1) {
                        continue;
                    }
                    cnt++;
                    temp[dx][dy] += floor(a[i][j] / 5);
                }
                temp[i][j] -= floor(a[i][j] / 5) * cnt;
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            a[i][j] = temp[i][j];
        }
    }
}

void cleaner1() {
    // 우
    a[x1][2] = 0;
    for (int y = 3; y <= c; y++) {
        a[x1][y] = temp[x1][y - 1];
    }
    // 상
    for (int x = 1; x < x1; x++) {
        a[x][c] = temp[x + 1][c];
    }

    // 좌
    for (int y = 1; y < c; y++) {
        a[1][y] = temp[1][y + 1];
    }
    // 하
    for (int x = 2; x < x1; x++) {
        a[x][1] = temp[x - 1][1];
    }
}
void cleaner2() {
    // 우
    a[x2][2] = 0;
    for (int y = 3; y <= c; y++) {
        a[x2][y] = temp[x2][y - 1];
    }
    // 상
    for (int x = x2 + 1; x < r; x++) {
        a[x][1] = temp[x + 1][1];
    }

    // 좌
    for (int y = 1; y < c; y++) {
        a[r][y] = temp[r][y + 1];
    }
    // 하
    for (int x = x2 + 1; x <= r; x++) {
        a[x][c] = temp[x - 1][c];
    }
}

int main() {
    int ans = 0;
    cin >> r >> c >> t;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1 && x1 == -1) {
                x1 = i;
                x2 = i + 1;
            }
        }
    }

    while (t--) {
        copy();
        move();

        copy();
        cleaner1();
        cleaner2();
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] > 0) {
                ans += a[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}