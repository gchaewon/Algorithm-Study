#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
const int MAX_SIZE = 104;

using namespace std;

int a[MAX_SIZE][MAX_SIZE];
int r, c, k;
int row = 3, col = 3;

void calcR() {
    int temp_col = 0;
    map<int, int> m;          // 갯수 저장 {숫자, 갯수}
    vector<pair<int, int>> v; // {갯수, 숫자}

    for (int i = 0; i < row; i++) {
        m.clear();
        v.clear();

        // 갯수 저장
        for (int j = 0; j < col; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            m[a[i][j]]++;
        }
        for (auto j : m) {
            v.push_back({j.second, j.first});
        }

        // 갯수 기준 오름차순 정렬
        sort(v.begin(), v.end());

        // 반영 전 0으로 초기화
        memset(a[i], 0, sizeof(a[i]));

        for (int idx = 0, j = 0; j < v.size(); j++) {
            a[i][idx++] = v[j].second;
            a[i][idx++] = v[j].first;
        }
        int size = v.size() * 2;
        temp_col = max(temp_col, size);
    }
    col = temp_col;
}

void calcC() {
    int temp_row = 0;
    map<int, int> m;          // 갯수 저장 {숫자, 갯수}
    vector<pair<int, int>> v; // {갯수, 숫자}

    for (int j = 0; j < col; j++) {
        m.clear();
        v.clear();

        // 갯수 저장
        for (int i = 0; i < row; i++) {
            if (a[i][j] == 0) {
                continue;
            }
            m[a[i][j]]++;
        }

        for (auto i : m) {
            v.push_back({i.second, i.first});
        }

        // 갯수 기준 오름차순 정렬
        sort(v.begin(), v.end());

        // 반영 전 0으로 초기화
        for (int i = 0; i < MAX_SIZE; i++) {
            a[i][j] = 0;
        }

        for (int idx = 0, i = 0; i < v.size(); i++) {
            a[idx++][j] = v[i].second;
            a[idx++][j] = v[i].first;
        }
        int size = v.size() * 2;
        temp_row = max(temp_row, size);
    }
    row = temp_row;
}

int main() {
    int cnt = 0;
    bool flag = false;
    cin >> r >> c >> k;
    r -= 1, c -= 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    while (cnt <= 100) {
        if (a[r][c] == k) {
            flag = true;
            cout << cnt;
            break;
        }
        if (row >= col) {
            calcR();
        } else {
            calcC();
        }
        cnt++;
    }

    if (!flag) {
        cout << -1;
    }

    return 0;
}