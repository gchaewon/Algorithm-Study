#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n;
int a[104], visited[104];
set<int> ans;

void bfs(int start) {
    queue<int> q;
    set<int> temp;

    q.push(start);
    temp.insert(start);

    while (!q.empty()) {
        int cur = q.front();
        int next = a[cur];
        q.pop();

        // 사이틀 생성시
        if (visited[next]) {
            // 출발지로 돌아오면 추가
            if (next == start) {
                for (auto t : temp) {
                    ans.insert(t);
                }
            }
            return;
        }

        visited[next] = 1;
        q.push(next);
    }
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        bfs(i);
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
    }

    return 0;
}