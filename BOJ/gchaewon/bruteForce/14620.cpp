#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int v[104][104];
int visited[104][104];
int ans = INT_MAX;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int check(vector<pair<int, int>> location) {
    int temp = 0;
    for (auto l : location) {
        int x = l.first;
        int y = l.second;
        if (visited[x][y]) {
            return INT_MAX;
        }
        visited[x][y] = 1;
        temp += v[x][y];
        for (auto d : dir) {
            int dx = x + d.X;
            int dy = y + d.Y;

            if (dx < 0 || dx >= n || dy < 0 || dy >= n || visited[dx][dy]) {
                return INT_MAX;
            }

            visited[dx][dy] = 1;
            temp += v[dx][dy];
        }
    }
    return temp;
}
int main() {
    cin >> n;
    vector<pair<int, int>> location;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
                location.push_back({i, j});
            }
        }
    }
    vector<int> sub_arr(location.size(), 1);
    for (int i = 0; i < 3; i++) {
        sub_arr[i] = 0;
    }

    // 위치 뽑기
    do {
        vector<pair<int, int>> temp;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < location.size(); i++) {
            if (sub_arr[i] == 0) {
                temp.push_back(location[i]);
            }
        }
        ans = min(ans, check(temp));
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans;
    return 0;
}