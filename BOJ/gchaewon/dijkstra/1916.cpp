#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, start, target;
vector<int> dist(1004, INT_MAX);

vector<pair<int, int>> bus[1004];

void dijkstra() {
    priority_queue<pair<int, int>>
        pq; // {누적 비용, 도시 번호}, 비용 순 오름차순

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        // 기존 경로값보다 큰 값이면 패스
        if (dist[cur] < cur_cost) {
            continue;
        }

        for (auto b : bus[cur]) {
            int next = b.first;
            int cost = b.second;

            if (dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int cur, next, cost;
        cin >> cur >> next >> cost;
        bus[cur].push_back({next, cost});
    }
    cin >> start >> target;
    dijkstra();
    cout << dist[target];

    return 0;
}