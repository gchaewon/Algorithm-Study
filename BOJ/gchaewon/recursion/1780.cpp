#include <iostream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

int N;
int MAX = pow(3, 7);
map<int, int> m = {{-1, 0}, {0, 0}, {1, 0}}; // 종이별 개수 저장
vector<vector<int>> v(MAX, vector<int>(MAX, 0));

void recur(int x, int y, int n) {
    if (n == 1) {
        m[v[x][y]]++;
        return;
    }
    bool flag = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (v[i][j] != v[x][y]) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        m[v[x][y]]++;
        return;
    }

    recur(x, y, n / 3);
    recur(x, y + (n / 3), n / 3);
    recur(x, y + (n / 3) * 2, n / 3);

    recur(x + (n / 3), y, n / 3);
    recur(x + (n / 3), y + (n / 3), n / 3);
    recur(x + (n / 3), y + (n / 3) * 2, n / 3);

    recur(x + (n / 3) * 2, y, n / 3);
    recur(x + (n / 3) * 2, y + (n / 3), n / 3);
    recur(x + (n / 3) * 2, y + (n / 3) * 2, n / 3);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    recur(0, 0, N);

    cout << m[-1] << "\n" << m[0] << "\n" << m[1];
    return 0;
}