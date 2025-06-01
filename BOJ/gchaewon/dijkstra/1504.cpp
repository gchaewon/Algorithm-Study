#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[804]; // {거리, 연결된 정점}

int dijkstra(int start, int target) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // {누적 거리, 정점} 누적거리 기준 오름차순 정렬
    vector<int> dist(1004, INT_MAX);
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        // 도착시 리턴
        if (cur == target) {
            return dist[target];
        }
        // 기존 거리보다 짧은 방식이 아닌 경우 넘어감
        if (dist[cur] < cur_cost) {
            continue;
        }

        for (auto node : adj[cur]) {
            int next = node.second;
            int next_cost = node.first;

            // 누적값+ 다음 간선크기가 짧은 방식이 아닌 경우 제외
            if (cur_cost + next_cost < dist[next]) {
                dist[next] = cur_cost + next_cost;
                pq.push({dist[next], next});
            }
        }
    }
    return -1;
}
int main() {
    int n, e, v1, v2;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // 양방향 저장
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;

    // 1. 1->v1->v2->n까지 경로
    vector<int> path1, path2;
    int dist1 = 0, dist2 = 0;
    path1.push_back(dijkstra(1, v1));
    path1.push_back(dijkstra(v1, v2));
    path1.push_back(dijkstra(v2, n));

    // 2. 1->v2->v1->n까지 경로
    path2.push_back(dijkstra(1, v2));
    path2.push_back(dijkstra(v2, v1));
    path2.push_back(dijkstra(v1, n));

    // 경로별 값 더하기
    for (auto p : path1) {
        // -1이 있는 경우 (경로가 없음), 최대값으로 저장
        if (p == -1) {
            dist1 = INT_MAX;
            break;
        }
        dist1 += p;
    }

    for (auto p : path2) {
        if (p == -1) {
            dist2 = INT_MAX;
            break;
        }
        dist2 += p;
    }

    if (dist1 == INT_MAX && dist2 == INT_MAX) {
        cout << -1;
    } else {
        cout << min(dist1, dist2);
    }

    return 0;
}