#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> s;
int visited[104];

void bfs(int start, int count) {
    queue<pair<int, int>> q;
    q.push({start, count});
    visited[1] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int dx = x + i;
            if (dx == 100) {
                cout << cnt + 1;
                return;
            }
            // 사다리가 있다면 사다리로 이동
            while (s[dx] != 0) {
                dx = s[dx];
            }
            // 없다면 주사위로 이동
            if (!visited[dx]) {
                visited[dx] = true;
                q.push({dx, cnt + 1});
            }
        }
    }
}
int main() {
    int x, y;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        s.insert({x, y});
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        s.insert({x, y});
    }

    bfs(1, 0);

    return 0;
}