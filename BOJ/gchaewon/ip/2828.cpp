#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, j;
    int ans = 0;
    vector<int> v(20, 0);
    vector<int> path(10, 0);

    cin >> n >> m >> j;

    for (int i = 0; i < j; i++) {
        cin >> v[i];
        v[i] -= 1;
    }

    int start = 0;
    int end = m - 1;

    for (int i = 0; i < j; i++) {
        int target = v[i];
        int move = 0;

        // 바구니 구간 안인 경우 이동 X
        if (target <= end && target >= start) {
            continue;
        }
        // 오른쪽으로 이동
        if (target > end) {
            move = target - end;
            start += move;
            end = target;
        }
        // 왼쪽으로 이동
        if (target < end) {
            move = start - target;
            start = target;
            end = start + m - 1;
        }
        ans += move;
    }

    cout << ans;
    return 0;
}