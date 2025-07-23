#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n, ans = INT_MAX;
string light, target;
string temp_light;

void turnLight(int idx) {
    for (int i = max(0, idx - 1); i <= min(idx + 1, n - 1); i++) {
        if (temp_light[i] == '0') {
            temp_light[i] = '1';
        } else {
            temp_light[i] = '0';
        }
    }
}

void simulator(int idx, int cnt) {
    // 마지막 인덱스까지 탐색한 경우 종료
    if (idx == n - 1) {
        // 같다면 횟수 반영
        if (temp_light == target) {
            ans = min(ans, cnt);

            // 다르다면 마지막 스위치 꺼보고 같은지 확인
        } else {
            turnLight(idx);
            if (temp_light == target) {
                ans = min(ans, cnt + 1);
            }
        }
        return;
    }

    // 이미 타겟과 같다면 전구 누르지 않음, 왼쪽 자리 검사만 진행
    // (뒤에서 누르면 바뀌기 때문에)
    if (temp_light[idx - 1] == target[idx - 1]) {
        simulator(idx + 1, cnt);
    } else { // 같지 않다면 전구 누르기
        turnLight(idx);
        simulator(idx + 1, cnt + 1);
    }
}
int main() {
    cin >> n >> light >> target;

    // case1. 0번 켜지 않고 진행
    temp_light = light;
    simulator(1, 0); // 0번 켜지 않고, 1번 인덱스부터 시작

    // case2. 0번 켜고 진행
    temp_light = light;
    turnLight(0);    // 0번 전구 켜기
    simulator(0, 1); // 0번 인덱스부터 시작

    if (ans != INT_MAX) {
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}