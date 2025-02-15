#include <bits/stdc++.h>

using namespace std;

int n;
int p[11];       // 인구수 저장
int adj[11][11]; // 연결 저장
int visited[11];
int sum = 0;

int go(int from, set<int> g) {
    visited[from] = 1;
    sum += p[from];

    // 그룹의 인근 선거구 중 방문하지 않고, i->i가 아닐 때만 탐색
    for (auto to : g) {
        if (visited[to] || from == to || !adj[from][to]) {
            continue;
        }
        // 방문처리 후, dfs
        visited[to] = 1;
        go(to, g);
    }
    return sum;
}

int main() {
    int ans = INT_MAX;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        int t, e;
        cin >> t;
        while (t--) {
            cin >> e;
            adj[i][e - 1] = 1;
        }
        adj[i][i] = 1;
    }

    // n/2까지 nCk해서 구역 뽑아 선거구 나누기
    for (int i = 0; i < n / 2; i++) {
        vector<int> sub_arr(n, 1);
        for (int j = 0; j <= i; j++) {
            sub_arr[j] = 0;
        }

        do {
            set<int> g1;
            set<int> g2;
            int sum1 = 0, sum2 = 0;
            int temp1 = 0, temp2 = 0;

            for (int i = 0; i < n; i++) {
                if (sub_arr[i] == 0) {
                    g1.insert(i);
                    sum1 += p[i];
                }
            }
            for (int i = 0; i < n; i++) {
                if (g1.find(i) == g1.end()) {
                    g2.insert(i);
                    sum2 += p[i];
                }
            }

            // 그룹 1, 인구 합 구하기
            sum = 0;
            memset(visited, 0, sizeof(visited));
            temp1 = go(*g1.begin(), g1);
            if (temp1 != sum1) { // 선거구끼리 이어져있지 않으면 제외
                continue;
            }

            // 그룹 2, 인구 합 구하기
            sum = 0;
            memset(visited, 0, sizeof(visited));
            temp2 = go(*g2.begin(), g2);
            if (temp2 != sum2) { // 선거구끼리 이어져있지 않으면 제외
                continue;
            }

            // 인구 차이 최솟값 갱신
            ans = min(ans, abs(sum1 - sum2));
        } while (next_permutation(sub_arr.begin(), sub_arr.end()));
    }

    // 값 갱신이 없는 경우 (선거구 나눌 수 없는 경우)
    if (ans == INT_MAX) {
        ans = -1;
    }

    cout << ans;
    return 0;
}