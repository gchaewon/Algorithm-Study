// 반시계 회전하기, 2774KB, 96ms
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
    // 1 2
    // 3 4
    pair<int, int> start = {0, 0};       // 1번 꼭짓점
    pair<int, int> end = {n - 1, m - 1}; // 4번 꼭짓점

    while (start.X < end.X && start.Y < end.Y) { // 직사각형 만족할 때까지 수행
        // <-
        for (int y = end.Y - 1; y >= start.Y; y--) {
            a[start.X][y] = temp[start.X][y + 1];
        }

        // V
        for (int x = start.X + 1; x <= end.X; x++) {
            a[x][start.Y] = temp[x - 1][start.Y];
        }

        // ->
        for (int y = start.Y + 1; y <= end.Y; y++) {
            a[end.X][y] = temp[end.X][y - 1];
        }

        // ^
        for (int x = end.X - 1; x >= start.X; x--) {
            a[x][end.Y] = temp[x + 1][end.Y];
        }

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

    while (r--) {
        copy();
        rotateRect();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}