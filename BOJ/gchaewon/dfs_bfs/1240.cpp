#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 0;
vector<int> adj[1004];
int visited[1004];
int dist[1004][1004];

bool dfs(int d, int cur, int to) {
    // 거리 찾은 경우 true 리턴
    if (cur == to) {
        ans = d;
        return true;
    }

    // 인근 노드 탐색
    for (auto next : adj[cur]) {
        // 방문한 적 있는 경우 제외
        if (visited[next]) {
            continue;
        }
        visited[next] = 1;

        // 찾은 경우 종료
        if (dfs(d + dist[cur][next], next, to)) {
            return true;
        }
        visited[next] = 0;
    }
    return false;
}

int main() {
    cin >> n >> m;
    int from, to, d;

    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> d;
        // 인근 노드 정보 저장
        adj[from].push_back(to);
        adj[to].push_back(from);

        // 노드간 거리 저장
        dist[from][to] = dist[to][from] = d;
    }

    while (m--) {
        cin >> from >> to;
        memset(visited, 0, sizeof(visited));
        ans = 0;
        visited[from] = 1;

        dfs(0, from, to);
        cout << ans << "\n";

        visited[to] = 0;
    }

    return 0;
}