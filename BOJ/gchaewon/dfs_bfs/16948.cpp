#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int n;
pair<int, int> start, target;
int dist[204][204];
vector<pair<int, int>> dir = {{-1, -2}, {1, -2}, {-2, 0},
                              {2, 0},   {-1, 2}, {1, 2}};
int bfs() {
    queue<pair<int, int>> q;
    dist[start.X][start.Y] = 1;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        if (x == target.X && y == target.Y) {
            return dist[x][y] - 1;
            break;
        }

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx > n || dy < 0 || dy > n || dist[dx][dy]) {
                continue;
            }

            dist[dx][dy] = dist[x][y] + 1;
            q.push({dx, dy});
        }
    }
    return -1;
}
int main() {
    cin >> n;

    // x, y 반대로 저장
    cin >> start.Y >> start.X >> target.Y >> target.X;

    cout << bfs();
    return 0;
}