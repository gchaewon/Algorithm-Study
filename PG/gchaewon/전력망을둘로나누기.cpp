#include <bits/stdc++.h>
using namespace std;

vector<int> adj[104];
int visited[104];

int dfs(int from) {
    visited[from] = true;
    int cnt = 1;
    for (int to : adj[from]) {
        if (!visited[to]) {
            cnt += dfs(to);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = INT_MAX;

    // 모든 전선에 대한 경우 구하기
    for (auto wire : wires) {
        // 그래프 초기화
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (auto w : wires) {
            if (w == wire) { // 자를 전선 제외
                continue;
            }
            // 정점 추가
            adj[w[0]].push_back(w[1]);
            adj[w[1]].push_back(w[0]);
        }

        // 방문처리 배열 초기화
        memset(visited, 0, sizeof(visited));

        int s1 = n - dfs(wire[0]); // 서브그래프 사이즈1
        int s2 = n - s1;           // 서브 그래프 사이즈2
        int diff = abs(s1 - s2);

        ans = min(ans, diff); // 개수 차이 갱신
    }

    return ans;
}
