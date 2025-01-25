#include <iostream>
#include <vector>

using namespace std;

int bfs(vector<int> &v, int n) {
    int cnt = 0;
    vector<bool> is_team(n + 1, false);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        // 방문한 적 있는 경우 건너뛰기
        if (visited[i]) {
            continue;
        }

        vector<int> path;
        int current = i;

        // 다음 경로가 방문한 적이 있으면 종료
        while (!visited[current]) {
            // 방문 처리, 경로에 넣기
            visited[current] = true;
            path.push_back(current);
            current = v[current];
        }

        // 방문한 적 있지만, 팀이 아닌 경우 사이클 발생
        if (!is_team[current]) {
            int idx = 0;
            // 사이클 시작 위치 찾기
            while (idx < path.size() && path[idx] != current) {
                idx++;
            }
            // 사이클에 속한 학생 팀으로 처리
            if (idx < path.size()) {
                for (int j = idx; j < path.size(); j++) {
                    is_team[path[j]] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!is_team[i])
            cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }

        cout << bfs(v, n) << "\n";
    }

    return 0;
}
