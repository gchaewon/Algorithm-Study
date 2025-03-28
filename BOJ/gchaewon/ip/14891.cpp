#include <iostream>
#include <vector>
using namespace std;

int x = 4, y = 8;
int w[4][8];
vector<vector<int>> score = {{0, 1}, {0, 2}, {0, 4}, {0, 8}};

// 회전
void rotator(int num, int opt) {
    // 복사
    int temp[8] = {0};

    for (int i = 0; i < y; i++) {
        temp[i] = w[num][i];
    }
    // 회전한 후 값 반영
    for (int i = 0; i < y; i++) {
        // 1이면 시계 방향, -1이면  반시계 방향
        int next = i + (-1 * opt);
        if (next < 0) {
            next += y;
        }
        w[num][i] = temp[next % y];
    }
}

int main() {
    int k, ans = 0;

    for (int i = 0; i < x; i++) {
        string wheel;
        cin >> wheel;
        for (int j = 0; j < y; j++) {
            w[i][j] = wheel[j] - '0';
        }
    }

    cin >> k;

    while (k--) {
        int num, opt;
        cin >> num >> opt;
        num -= 1;

        int dir[4] = {0}; // 회전 방향 저장, 1 = 시계 방향, -1 = 반시계 방향
        dir[num] = opt;

        // 왼쪽 전파
        for (int i = num - 1; i >= 0; i--) {
            if (w[i][2] != w[i + 1][6]) { // 다른 극이면
                dir[i] = -dir[i + 1];     // 반대 방향으로 설정
            } else {
                break;
            }
        }

        // 오른쪽 전파
        for (int i = num + 1; i < 4; i++) {
            if (w[i - 1][2] != w[i][6]) { // 다른 극이면
                dir[i] = -dir[i - 1];     // 반대 방향으로 설정
            } else {
                break;
            }
        }

        // 회전 실행
        for (int i = 0; i < 4; i++) {
            if (dir[i] != 0) {
                rotator(i, dir[i]);
            }
        }
    }

    for (int i = 0; i < x; i++) {
        int p = w[i][0];
        ans += score[i][p];
    }
    cout << ans;

    return 0;
}