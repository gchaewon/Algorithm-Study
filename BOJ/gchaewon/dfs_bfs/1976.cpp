#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, num, is_connect;
vector<int> adj[201];
set<int> cycle;
set<int> city;

void dfs(int cur) {
    cycle.insert(cur);

    for (auto next : adj[cur]) {
        if (cycle.find(next) != cycle.end()) {
            continue;
        }
        dfs(next);
    }
}
int main() {
    cin >> n >> m;

    // 노드 연결
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> is_connect;

            if (is_connect) {
                adj[i].push_back(j);
            }
        }
    }
    // 도시 정보 저장
    for (int i = 0; i < m; i++) {
        cin >> num;
        num -= 1;
        city.insert(num);
    }

    dfs(num);

    set<int> visit;

    // 서로 연결된 사이클 중, 여행 도시만 뽑아서 visit에 저장
    for (auto c : cycle) {
        if (city.find(c) != city.end()) {
            visit.insert(c);
        }
    }

    // 계획한 도시와 방문한 도시가 같으면 yes
    if (city == visit) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

// 5
// 5
// 0 1 0 1 1
// 1 0 1 1 0
// 0 1 0 0 0
// 1 1 0 0 0
// 1 0 0 0 0
// 4 2 1 2 3