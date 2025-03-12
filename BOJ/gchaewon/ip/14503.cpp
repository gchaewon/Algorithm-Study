#include <bits/stdc++.h>

using namespace std;

int a[54][54];
int n, m, r, c, d;
int cnt = 0;

vector<pair<int, int>> back = {
    {1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 북 동 남 서 후진

vector<pair<int, int>> fward = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 북 동 남 서 전진

vector<int> dir = {3, 0, 1, 2}; // 회전 시 바라보는 방향

bool check(int dr, int dc) {
    if (dr < 0 || dr >= n || dc < 0 || dc >= m || a[dr][dc] != 0) {
        return false;
    }
    return true;
}

bool turn() {
    int temp = 0;
    int next = dir[d];

    while (++temp <= 4) {
        int dr = r + fward[next].first;
        int dc = c + fward[next].second;

        if (check(dr, dc)) {
            r = dr;
            c = dc;
            d = next;
            return true;
        }
        next = dir[next];
    }
    return false;
}
bool move() {
    int dr = r + back[d].first;
    int dc = c + back[d].second;

    if (dr < 0 || dr >= n || dc < 0 || dc >= m || a[dr][dc] == 1) {
        return false;
    }

    r = dr;
    c = dc;
    return true;
}

bool go() {
    bool flag = false;
    if (a[r][c] == 0) {
        a[r][c] = 2;
        cnt++;
        return true;
    }

    // 주변 네칸에서 찾기
    else {
        for (auto i : back) {
            int dr = r + i.first;
            int dc = c + i.second;

            if (!check(dr, dc)) {
                continue;
            }
            // 청소되지 않은 빈칸이 있는 경우
            if (a[dr][dc] == 0) {
                flag = true;
                break;
            }
        }
    }
    if (flag) {
        return turn();
        // 주변에서 없는 경우 이동
    } else {
        return move();
    }
}

int main() {
    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int i = 0;
    bool flag = true;

    while (flag) {
        flag = go();
    }

    cout << cnt;

    return 0;
}