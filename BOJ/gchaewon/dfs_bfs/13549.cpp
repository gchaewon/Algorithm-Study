#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_DIST = 100001;
int n, k;
vector<int> times(MAX_DIST, -1);

void bfs() {
    queue<pair<int, int>> q;
    q.push({n, 0});
    times[n] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int sec = q.front().second;
        q.pop();

        if (x == k) {
            return;
        }

        // 순간이동 하는 경우, 범위 내이고 방문한 적 없으면
        if (x * 2 < MAX_DIST && times[x * 2] == -1) {
            times[x * 2] = sec;
            q.push({x * 2, sec});
        }
        // 걷는 경우, 범위 내이고 방문한 적 없으면
        if (x - 1 >= 0 && times[x - 1] == -1) {
            times[x - 1] = sec + 1;
            q.push({x - 1, sec + 1});
        }
        if (x + 1 < MAX_DIST && times[x + 1] == -1) {
            times[x + 1] = sec + 1;
            q.push({x + 1, sec + 1});
        }
    }
}
int main() {
    cin >> n >> k;

    times[n] = 0;

    bfs();

    cout << times[k];

    return 0;
}