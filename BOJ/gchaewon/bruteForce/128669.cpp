#include <bits/stdc++.h>

using namespace std;
const int MAX = 180;
vector<vector<int>> attack_case = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1},
                                   {3, 1, 9}, {1, 3, 9}, {1, 9, 3}};
vector<int> scv(3, 0);
int visited[61][61][61];

void bfs(vector<int> start) {
    queue<vector<int>> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int z = q.front()[2];
        q.pop();

        // 모든 좌표가 0이 되면 리턴
        if (x == 0 && y == 0 && z == 0) {
            cout << visited[x][y][z];
            break;
        }

        for (auto attack : attack_case) {
            int dx = max(0, x - attack[0]); // 음수가 되는 경우 0으로 맞추기
            int dy = max(0, y - attack[1]);
            int dz = max(0, z - attack[2]);

            if (visited[dx][dy][dz]) {
                continue;
            }

            visited[dx][dy][dz] = visited[x][y][z] + 1;
            q.push({dx, dy, dz});
        }
    }
}
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }
    bfs(scv);
    return 0;
}