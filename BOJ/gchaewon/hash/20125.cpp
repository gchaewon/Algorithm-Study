#include <bits/stdc++.h>

using namespace std;

int n, hx, hy;
char a[1004][1004];
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            a[i][j + 1] = line[j];
            if (a[i][j + 1] == '*' && hx == 0 && hy == 0) {
                hx = i + 1, hy = j + 1;
            }
        }
    }
    // 심장 구하기
    cout << hx << " " << hy << "\n";

    // 팔 구하기
    int ly = 0, ry = 0;
    for (int y = 1; y <= n; y++) {
        if (a[hx][y] == '*' && ly == 0) {
            ly = y;
        }
        if (a[hx][y] != '*' && ly != 0 && ry == 0) {
            ry = y - 1;
        }
    }
    if (!ry) {
        ry = n;
    }
    cout << hy - ly << " " << ry - hy << " ";

    // 몸통 구하기
    int bx = 0;

    for (int x = hx + 1; x <= n; x++) {
        if (a[x][hy] != '*' && bx == 0) {
            bx = x - 1;
            break;
        }
    }
    cout << bx - hx << " ";

    // 다리 구하기
    int lx = 0, rx = 0;
    for (int x = bx + 1; x <= n; x++) {
        if (a[x][hy - 1] != '*' && lx == 0) {
            lx = x - 1;
        }
    }
    if (!lx) {
        lx = n;
    }
    for (int x = bx + 1; x <= n; x++) {
        if (a[x][hy + 1] != '*' && rx == 0) {
            rx = x - 1;
        }
    }
    if (!rx) {
        rx = n;
    }
    cout << lx - bx << " " << rx - bx;

    return 0;
}