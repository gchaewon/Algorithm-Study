#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;
using namespace std;

int n, m;
vector<vector<int>> v(500, vector<int>(500, 0));
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(pair<int, int> start) {
    int count = 0;
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        v[x][y] = 2;
        q.pop();
        count++;

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (v[nx][ny] != 1) {
                continue;
            }
            v[nx][ny] = 2; // 방문 표시
            q.push({nx, ny});
        }
    }
    return count;
}

int main() {
    cin >> n >> m;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                answer.push_back(bfs({i, j}));
            }
        }
    }

    sort(answer.rbegin(), answer.rend());
    cout << answer.size() << "\n";
    cout << (answer.size() == 0 ? 0 : answer[0]);

    return 0;
}