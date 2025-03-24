#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

int dijkstra(vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
        pq; // {비용, 이전 위치}
    int cost[n + 4];
    fill(cost, cost + n + 4, INT_MAX);
    pq.push({0, 1}); // 시작

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (cur_cost > cost[cur]) {
            continue;
        }

        for (auto node : adj[cur]) {
            int next = node.second;
            int next_cost = node.first;

            if (cur_cost + next_cost < cost[next]) {
                cost[next] = cur_cost + next_cost;
                pq.push({cost[next], next});
            }
        }
    }
    return cost[n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> adj[n + 4];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b}); // {비용, 도착지}
        adj[b].push_back({c, a});
    }

    cout << dijkstra(adj);

    return 0;
}