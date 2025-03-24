#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, n, d, c;

void dijkstra(int start, vector<pair<int, int>> adj[]) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // {dist, 번호} dist 오름차순

    int cnt = 0, max_time = 0;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (dist[cur] < cur_cost) {
            continue;
        }
        cnt++;
        max_time = max(max_time, dist[cur]);

        for (auto a : adj[cur]) {
            int next = a.first;
            int next_cost = a.second;

            if (dist[cur] + next_cost < dist[next]) {
                dist[next] = dist[cur] + next_cost;
                pq.push({dist[next], next});
            }
        }
    }
    cout << cnt << " " << max_time << "\n";
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        vector<pair<int, int>> adj[n + 1]; //{감염 시간, 다음 정점}
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }
        dijkstra(c, adj);
    }

    return 0;
}