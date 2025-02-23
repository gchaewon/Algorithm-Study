#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int r, c;

char m[21][21];
int visited[21][21];
int alpha[26];
int ans = 0;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void go(int x, int y) {
    ans = max(ans, visited[x][y]);

    for (auto d : dir) {
        int dx = x + d.X;
        int dy = y + d.Y;

        if (dx < 0 || dx >= r || dy < 0 || dy >= c || alpha[m[dx][dy] - 'A']) {
            continue;
        }
        visited[dx][dy] = visited[x][y] + 1;
        alpha[m[dx][dy] - 'A'] = 1;
        go(dx, dy);
        alpha[m[dx][dy] - 'A'] = 0;
        visited[dx][dy] -= 1;
    }
}
int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) {
            m[i][j] = line[j];
        }
    }
    visited[0][0] = 1;
    alpha[m[0][0] - 'A'] = 1;
    go(0, 0);

    cout << ans;
    return 0;
}