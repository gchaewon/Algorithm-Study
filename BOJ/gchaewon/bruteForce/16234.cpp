#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, l, r;
int a[51][51];
int visited[51][51];
int ans = 0;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<pair<int, int>>> uni;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    visited[x][y] = 1;
    v.push_back({x, y});
    q.push({x, y});

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
                continue;
            }
            if (visited[dx][dy] == 1) {
                continue;
            }
            int diff = abs(a[x][y] - a[dx][dy]);
            if (diff >= l && diff <= r) {
                visited[dx][dy] = 1;
                v.push_back({dx, dy});
                q.push({dx, dy});
            }
        }
    }
    uni.push_back(v);
}

void move(vector<vector<pair<int, int>>> uni) {
    for (auto u : uni) {
        int avg = 0;
        for (auto i : u) {
            avg += a[i.X][i.Y];
        }
        avg /= u.size();

        for (auto i : u) {
            a[i.X][i.Y] = avg;
        }
    }
}
bool isValid(int x, int y) {
    for (auto d : dir) {
        int dx = x + d.X;
        int dy = y + d.Y;

        if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
            continue;
        }
        int diff = abs(a[x][y] - a[dx][dy]);
        if (diff >= l && diff <= r) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (ans <= 2000) {
        int temp = 0;
        uni.clear();
        memset(visited, 0, sizeof(visited));

        // 연합 생성 (여러개 가능)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isValid(i, j) && visited[i][j] == 0) {
                    temp++;
                    bfs(i, j);
                }
            }
        }
        // 연합이 없으면 중지
        if (temp == 0) {
            break;
        }

        // 인구 이동 반영
        move(uni);
        ans++;
    }

    cout << ans;

    return 0;
}