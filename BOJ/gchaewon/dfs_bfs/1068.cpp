#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
int n, p, target;
int ans = 0, root = 0;

int dfs(int cur) {
    // 타겟 노드까지 간 경우 재귀 중단
    if (cur == target) {
        return -1;
    }

    // 리프 노드인지 확인
    bool isLeaf = true;

    // 타겟 노드가 아닌 자식 노드만 탐색, 자식이 있다면 리프가 아님
    for (auto next : adj[cur]) {
        if (dfs(next) != -1) {
            isLeaf = false;
        }
    }

    if (isLeaf) {
        ans++;
    }

    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;

        if (p == -1) {
            root = i;
        } else {
            adj[p].push_back(i);
        }
    }

    cin >> target;

    // 루트를 삭제하는 경우 0 리턴
    if (target == root) {
        cout << 0;
        return 0;
    }

    dfs(root);
    cout << ans;

    return 0;
}