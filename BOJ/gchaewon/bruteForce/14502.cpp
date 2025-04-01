#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int n, m;
int map[12][12], temp[12][12];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void updateMap(vector<pair<int, int>> picked) {
    // 초기화, 복사
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = map[i][j];
        }
    }
    // 뽑은 위치 벽 세우기
    for (auto p : picked) {
        temp[p.X][p.Y] = 1;
    }
}
void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= m || temp[dx][dy] != 0) {
                continue;
            }
            temp[dx][dy] = 2;
            q.push({dx, dy});
        }
    }
}
int countArea() {
    int cnt = 0;
    // 바이러스 시작점으로 bfs 영역 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                bfs({i, j});
            }
        }
    }

    // 바이러스가 안퍼진 곳 개수 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int ans = 0;
    cin >> n >> m;
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                arr.push_back({i, j});
            }
        }
    }

    vector<int> sub_arr(arr.size(), 1);
    for (int i = 0; i < 3; i++) {
        sub_arr[i] = 0;
    }

    // 벽 뽑기
    do {
        vector<pair<int, int>> picked;
        for (int i = 0; i < arr.size(); i++) {
            if (!sub_arr[i]) {
                picked.push_back(arr[i]);
            }
        }
        // 벽 업데이트 후 영역 최댓값 업데이트
        updateMap(picked);
        ans = max(ans, countArea());
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans;
    return 0;
}