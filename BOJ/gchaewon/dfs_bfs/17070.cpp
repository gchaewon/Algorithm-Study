#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int n, ans = 0;
int board[20][20], visited[20][20];

struct Pipe {
    int x1, y1;
    int x2, y2;
    int status; // 0 가로, 1 세로, 2 대각선
};
Pipe pipe = {0, 0, 0, 1, 0};

// dir[0] = {{가로 파이프가 이동할 위치값 x1 y1 x2 y2, 이동 후 상태값 status}}
map<int, vector<Pipe>> dir = {
    {0, {{0, 1, 0, 1, 0}, {0, 1, 1, 1, 2}}},
    {1, {{1, 0, 1, 0, 1}, {1, 0, 1, 1, 2}}},
    {2, {{1, 1, 0, 1, 0}, {1, 1, 1, 0, 1}, {1, 1, 1, 1, 2}}}};

void dfs(Pipe cur) {
    if (cur.x2 == n - 1 && cur.y2 == n - 1) {
        ans++;
        return;
    }

    int status = cur.status;
    for (auto d : dir[status]) {
        int dx1 = cur.x1 + d.x1;
        int dy1 = cur.y1 + d.y1;
        int dx2 = cur.x2 + d.x2;
        int dy2 = cur.y2 + d.y2;

        if (dx1 < 0 || dx2 < 0 || dx1 >= n || dx2 >= n || dy1 < 0 || dy2 < 0 ||
            dy1 >= n || dy2 >= n) {
            continue;
        }
        // 이동하려는 곳이 빈칸이 아니면 제외
        if (board[dx1][dy1] || board[dx2][dy2]) {
            continue;
        }

        // 대각선인 경우 주변 2칸 빈칸이 아니면 제외
        if (d.status == 2 && (board[dx2][dy1] || board[dx1][dy2])) {
            continue;
        }

        Pipe next = {dx1, dy1, dx2, dy2, d.status};

        dfs(next);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    Pipe pipe = {0, 0, 0, 1, 0};
    dfs(pipe);

    cout << ans;
    return 0;
}
