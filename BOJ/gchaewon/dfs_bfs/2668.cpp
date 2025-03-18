#include <bits/stdc++.h>
using namespace std;

int a[104], visited[104];
set<int> ans, cycle;

void dfs(int cur, int start) {
    if (visited[cur]) {     // 사이클
        if (cur == start) { // 처음 값으로 돌아온 경우
            for (auto c : cycle) {
                ans.insert(c);
            }
        }
        return;
    }
    visited[cur] = 1;
    cycle.insert(cur);
    dfs(a[cur], start);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        cycle.clear();
        dfs(i, i);
    }

    cout << ans.size() << " ";

    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}