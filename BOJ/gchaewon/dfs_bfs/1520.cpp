#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int m, n, ans = 0;
int dp[504][504]; // dp[x][y] = {x, y}에서 시작해서 {n-1, m-1}에 가는 경우의 수
long long board[504][504];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int h, int x, int y) {
    // 도착지 -> 도착지 가는 경우의 수 1개
    if (x == n - 1 && y == m - 1) {
        return 1;
    }
    // 이미 계산된 곳이면 제외
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    // 초기 값 0으로 설정
    dp[x][y] = 0;

    for (auto d : dir) {
        int dx = x + d.X;
        int dy = y + d.Y;
        long long dh = board[dx][dy];

        if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
            continue;
        }
        // 내리막이 아닌 경우 제외
        if (dh >= h) {
            continue;
        }
        // 재귀 호출해서 경우의 수 더하기
        dp[x][y] += dfs(dh, dx, dy);
    }
    // {0, 0}에서 도착지 {n-1, m-1}에 도달하는 경우의 수 리턴
    return dp[x][y];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(board[0][0], 0, 0);

    return 0;
}