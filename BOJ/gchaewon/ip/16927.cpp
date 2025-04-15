// 반시계 방향 회전, 회전 횟수가 커서 개별 사각형으로 나눠 회전하는 유형

#include <iostream>
#define X first
#define Y second
using namespace std;

int n, m, r;
int a[304][304], temp[304][304];

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }
}
void rotateRect() {
    pair<int, int> start = {0, 0};
    pair<int, int> end = {n - 1, m - 1};

    // 외부 -> 내부 사각형으로 들어감
    while (start.X < end.X && start.Y < end.Y) {
        int h = end.X - start.X + 1;
        int w = end.Y - start.Y + 1;

        int inner_r = 0;
        int mod = 2 * (h + w - 2); // 사각형의 원점으로 돌아오는 크기

        if (mod != 0) { // 0으로 나누는 경우 방지
            inner_r = r % mod;
        }

        // 필요한 회전 횟수만큼 돌기
        while (inner_r--) {
            copy();
            // <-
            for (int y = end.Y - 1; y >= start.Y; y--) {
                a[start.X][y] = temp[start.X][y + 1];
            }
            // v
            for (int x = start.X + 1; x <= end.X; x++) {
                a[x][start.Y] = temp[x - 1][start.Y];
            }
            // >
            for (int y = start.Y + 1; y <= end.Y; y++) {
                a[end.X][y] = temp[end.X][y - 1];
            }
            // ^
            for (int x = end.X - 1; x >= start.X; x--) {
                a[x][end.Y] = temp[x + 1][end.Y];
            }
        }

        // 꼭짓점 업데이트
        start = {start.X + 1, start.Y + 1};
        end = {end.X - 1, end.Y - 1};
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    // 회전 횟수 r이 크므로 매회차 돌리는 것이 아니라,
    // 내부 사각형 테두리를 개별적으로 (r % 원점으로 돌아오는 크기) 만큼 회전

    rotateRect();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}