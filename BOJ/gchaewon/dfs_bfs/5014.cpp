#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d, ans = INT_MAX;

void bfs() {
    queue<int> q;
    int visited[f + 4];

    memset(visited, 0, sizeof(visited));
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == g) {
            ans = min(ans, visited[cur]);
            continue;
        }

        if (cur + u <= f && !visited[cur + u]) {
            visited[cur + u] = visited[cur] + 1;
            q.push(cur + u);
        }
        if (cur - d >= 1 && !visited[cur - d]) {
            visited[cur - d] = visited[cur] + 1;
            q.push(cur - d);
        }
    }
}

int main() {
    cin >> f >> s >> g >> u >> d;

    bfs();

    if (ans != INT_MAX) {
        cout << ans - 1;
    } else {
        cout << "use the stairs";
    }
    return 0;
}