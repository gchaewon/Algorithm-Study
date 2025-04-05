#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m, ans = INT_MAX;
int a[12][12], temp[12][12];
vector<pair<int, int>> dir = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 북, 서, 남, 동 90도씩 이동

// 각 cctv 번호에서 나가는 방향의 인덱스
vector<vector<int>> cdir = {{3}, {1, 3}, {0, 3}, {0, 1, 3}, {0, 1, 2, 3}};
vector<pair<int, int>> cctv; // cctv 위치 저장
vector<vector<int>> dirs; // cctv가 회전했을 때 나아가는 방향 인덱스

void extend(int x, int y, int d) {
    int nx = x, ny = y;
    while (true) {
        nx += dir[d].X;
        ny += dir[d].Y;

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            break;
        }
        // 벽 만난 경우 중단
        if (temp[nx][ny] == 6) {
            break;
        }
        // 볼 수 있는 경우 -1 처리
        if (temp[nx][ny] == 0) {
            temp[nx][ny] = -1;
        }
    }
}

int getArea() {
    int area = 0;
    memset(temp, 0, sizeof(temp));

    // 기존 값 복사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }
    // cctv마다 저장한 방향대로 뻗어나감
    for (int i = 0; i < cctv.size(); i++) {
        int x = cctv[i].X, y = cctv[i].Y;
        for (int d : dirs[i]) { // 각 cctv 보는 방향대로 전파
            extend(x, y, d);
        }
    }
    // 영역 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                area++;
            }
        }
    }
    return area;
}

void backTracking(int idx) {
    if (idx == cctv.size()) { // 끝까지 검사한 경우
        int temp_area = getArea();
        ans = min(ans, temp_area);
        return;
    }

    int x = cctv[idx].X, y = cctv[idx].Y;
    int type = a[x][y] - 1;

    // ccctv 90*4 4번 회전
    for (int i = 0; i < 4; i++) {
        vector<int> temp_cdir = cdir[type]; // cctv 나아가는 방향 인덱스
        for (int j = 0; j < temp_cdir.size(); j++) {
            temp_cdir[j] = (temp_cdir[j] + i) % 4; // 회전하면서 방향 업데이트
        }

        dirs.push_back(temp_cdir);
        backTracking(idx + 1);
        dirs.pop_back();

        if (type == 4 ||
            (type == 1 && i == 1)) { // cctv 5, 2번은 여러번 회전 안해도됨
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0 && a[i][j] != 6) {
                cctv.push_back({i, j});
            }
        }
    }

    backTracking(0);

    cout << ans;

    return 0;
}

// 핵심 로직
// 1. 백트래킹으로 각 cctv마다 4방향 회전, dirs에 회전한 상태 cdir 저장
// 2. 끝 번호 cctv까지 백트래킹으로 닿음 idx == cctv.size()
// 3. extend로 dirs에 저장한 cdir값 기반 전파, 영역 구하기