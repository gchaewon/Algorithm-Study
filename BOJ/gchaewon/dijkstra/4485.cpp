#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
using namespace std;

int n;
int a[129][129], dist[129][129];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dijkstra() {
    priority_queue<pair<int, int>> pq;

    dist[0][0] = a[0][0];
    pq.push({0, 0});

    while (!pq.empty()) {
        int x = pq.top().X;
        int y = pq.top().Y;
        pq.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n) {
                continue;
            }

            if (dist[x][y] + a[dx][dy] < dist[dx][dy]) {
                dist[dx][dy] = dist[x][y] + a[dx][dy];
                pq.push({dx, dy});
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
        memset(dist, 10, sizeof(dist)); // 최댓값으로 초기화
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