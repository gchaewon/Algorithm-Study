#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int a[129][129], dist[129][129];

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<>>
        pq;
    // {비용,{x, y}} 비용 오름차순

    dist[0][0] = a[0][0];
    pq.push({a[0][0], {0, 0}});

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cur_cost = pq.top().first;
        pq.pop();

        // 기존 경로값보다 큰 값이면 패스
        if (dist[x][y] < cur_cost) {
            continue;
        }

        for (auto d : dir) {
            int dx = x + d.first;
            int dy = y + d.second;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
                continue;
            }

            if (dist[x][y] + a[dx][dy] < dist[dx][dy]) {
                dist[dx][dy] = dist[x][y] + a[dx][dy];
                pq.push({dist[dx][dy], {dx, dy}});
            }
        }
    }
}
int main() {
    int cnt = 0;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        memset(a, 0, sizeof(a));
        fill(&dist[0][0], &dist[0][0] + 129 * 129, INT_MAX);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        dijkstra();

        cout << "Problem " << ++cnt << ": " << dist[n - 1][n - 1] << "\n";
    }

    return 0;
}