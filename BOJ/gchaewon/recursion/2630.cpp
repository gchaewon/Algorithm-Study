#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(128, vector<int>(128, 0));
int white = 0;
int blue = 0;

void recur(int x, int y, int n) {
    if (n == 1) {
        if (v[x][y]) {
            blue++;
        } else {
            white++;
        }
        return;
    }
    bool flag = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (v[x][y] != v[i][j]) { // 다른색이 있는 경우
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        if (v[x][y]) {
            blue++;
        } else {
            white++;
        }
    }

    else {
        recur(x, y, n / 2);
        recur(x, y + n / 2, n / 2);
        recur(x + n / 2, y, n / 2);
        recur(x + n / 2, y + n / 2, n / 2);
    }
}
int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    recur(0, 0, N);

    cout << white << "\n" << blue;
    return 0;
}