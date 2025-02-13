#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int r, c, k;
int ans = 0;
char m[6][6];
int visited[6][6];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pair<int, int>> temp;

void go(int x, int y) {
    if (x == 0 && y == c - 1) {
        if (temp.size() == k) {
            ans++;
        }
        return;
    }
    for (auto d : dir) {
        int dx = x + d.X;
        int dy = y + d.Y;

        if (dx < 0 || dx >= r || dy < 0 || dy >= c || visited[dx][dy] == 1 ||
            m[dx][dy] == 'T') {
            continue;
        }
        visited[dx][dy] = 1;
        temp.push_back({dx, dy});
        go(dx, dy);
        visited[dx][dy] = 0;
        temp.pop_back();
    }
}
int main() {
    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) {
            m[i][j] = line[j];
        }
    }

    visited[r - 1][0] = 1;
    temp.push_back({r - 1, 0});
    go(r - 1, 0);

    cout << ans;
    return 0;
}