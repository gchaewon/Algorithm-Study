#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10002];
int visited[10002];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}
int dfs(int from) {
    visited[from] = 1;
    int cnt = 1;
    for (int to : adj[from]) {
        if (visited[to]) {
            continue;
        }
        cnt += dfs(to);
    }
    return cnt;
}

int main() {
    int n, m;
    vector<pair<int, int>> ans;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int temp = dfs(i);
        ans.push_back({i, temp});
    }

    sort(ans.rbegin(), ans.rend(), cmp);

    for (int i = 0; i < n; i++) {
        if (ans[i].second < ans[0].second) {
            break;
        }
        cout << ans[i].first << " ";
    }
    return 0;
}
