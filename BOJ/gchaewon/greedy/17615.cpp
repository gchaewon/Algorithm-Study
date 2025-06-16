#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int ans = 0;
    string balls;

    cin >> n;
    cin >> balls;

    int b_cnt = 0, r_cnt = 0;

    // 공에서 빨간 공, 파란 공 개수 구하기
    for (auto ball : balls) {
        if (ball == 'B') {
            b_cnt++;
        } else {
            r_cnt++;
        }
    }

    vector<int> cases(4, 0);
    bool r_flag = false, b_flag = false;

    // 공 왼쪽으로 옮기기
    for (int i = 0; i < n; i++) {
        // case0 : 빨간색 공 왼쪽으로 옮기기
        if (!r_flag && balls[i] != 'R') {
            // 전체 빨간 공 - 왼쪽에 연속된 빨간 공
            cases[0] = r_cnt - i;
            r_flag = true;
        }

        // case1 : 파란색 공 왼쪽으로 옮기기
        if (!b_flag && balls[i] != 'B') {
            // 전체 파란 공 - 왼쪽에 연속된 파란 공
            cases[1] = b_cnt - i;
            b_flag = true;
        }
    }

    r_flag = false;
    b_flag = false;

    // 공 오른쪽으로 옮기기
    for (int i = n - 1; i >= 0; i--) {
        // case2 : 빨간색 공 오른쪽으로 옮기기
        if (!r_flag && balls[i] != 'R') {
            // 전체 빨간 공 - 오른쪽에 연속된 빨간 공
            cases[2] = r_cnt - (n - i) + 1;
            r_flag = true;
        }

        // case3 : 파란색 공 오른쪽으로 옮기기
        if (!b_flag && balls[i] != 'B') {
            // 전체 파란 공 - 오른쪽에 연속된 파란 공
            cases[3] = b_cnt - (n - i) + 1;
            b_flag = true;
        }
    }

    sort(cases.begin(), cases.end());
    cout << cases[0];
    return 0;
}