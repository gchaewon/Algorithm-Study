#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define X first;
#define Y second;
using namespace std;

int ans = 0;
int n, m;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(vector<vector<int>> &map, pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
                continue;
            }
            if (map[dx][dy] == 0) {
                map[dx][dy] = 2;
                q.push({dx, dy});
            }
        }
    }
}

void makeWall(vector<int> &wall, vector<vector<int>> v) {
    vector<vector<int>> map = v;
    int count = 0;
    // 벽 세우기
    for (int i = 0; i < 3; i++) {
        int temp = wall[i] - 1;
        int y = temp % m;
        int x = temp / m;
        map[x][y] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                bfs(map, {i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                count++;
            }
        }
    }
    ans = max(count, ans);
}

int main() {
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<int> arr;

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 0) {
                arr.push_back(i * m + j + 1);
            }
        }
    }

    // 벽 세울 위치 뽑기
    vector<int> sub_arr(arr.size(), 1);
    for (int i = 0; i < 3; i++) {
        sub_arr[i] = 0;
    }

    do {
        vector<int> temp;
        for (int i = 0; i < arr.size(); i++) {
            if (!sub_arr[i]) {
                temp.push_back(arr[i]);
            }
        }
        makeWall(temp, v);
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans;
    return 0;
}