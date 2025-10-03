#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m;
int board[54][54], dist[54][54];
int ans = INT_MAX;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pair<int, int>> starts;

int checkDone() {
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 1 && dist[i][j] == 0) {
                return -1;
            }
            t = max(t, dist[i][j] - 1);
        }
    }
    return t;
}
void bfs(vector<pair<int, int>> virus) {
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;

    // 초기 바이러스 위치 저장
    for (auto v : virus) {
        q.push(v);
        dist[v.X][v.Y] = 1;
    }

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n || board[dx][dy] == 1 ||
                dist[dx][dy]) {
                continue;
            }
            dist[dx][dy] = dist[x][y] + 1;
            q.push({dx, dy});
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                starts.push_back({i, j});
            }
        }
    }

    // 1. 2의 개수 중에서 m개를 뽑음,
    vector<int> sub_arr(starts.size(), 1);
    for (int i = 0; i < m; i++) {
        sub_arr[i] = 0;
    }

    do {
        vector<pair<int, int>> virus;
        for (int i = 0; i < sub_arr.size(); i++) {
            if (sub_arr[i] == 0) {
                virus.push_back(starts[i]);
            }
        }
        // 2. m개 위치에서 시작하는 bfs를 돌리고
        // 빈 칸에 바이러스 다 차는 시간 최솟값 구하기
        bfs(virus);
        int t = checkDone();
        if (t != -1) {
            ans = min(ans, t);
        }
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    if (ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}