#include <algorithm>
#include <iostream>
using namespace std;

int n, ans = 0;
// queen[x] = y 각 x행에 놓은 퀸 y열 저장
int queen[19] = {
    -1,
};

bool check(int dx, int dy) {
    for (int x = 0; x < dx; x++) {
        // 열이 같거나, 대각선이라면(각 x, y 위치차가 1으로 같음) 퀸 못 놓음
        if (queen[x] == dy || (abs(dx - x) == abs(dy - queen[x]))) {
            return false;
        }
    }
    return true;
}

void backTracking(int x) {
    // n-1행까지 반복
    if (x == n) {
        ans++;
        return;
    }

    // x행에서 가능한 y열 찾기
    for (int y = 0; y < n; y++) {
        if (check(x, y)) {
            // 값 저장
            queen[x] = y;
            // 탐색
            backTracking(x + 1);
            // 원복
            queen[x] = -1;
        }
    }
}

int main() {
    cin >> n;

    // 0번 행부터 시작
    backTracking(0);

    cout << ans;

    return 0;
}