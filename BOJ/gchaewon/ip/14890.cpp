#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int n, l;
int m[104][104];
int ans = 0;

bool findLoad(int temp[]) {
    int h = -1;
    int is_used[104] = {0};

    for (int i = 0; i < n; i++) {
        if (h == -1) {
            h = temp[i];
        }

        int cur = temp[i];
        int diff = abs(cur - h);

        // 높이차가 1이상일 때
        if (diff > 1) {
            return false;
        }
        // 경사로를 놓아야할 때
        if (diff == 1) {
            // 낮 -> 높(현) 경우
            if (cur > h) {
                int cnt = 0;
                // 경사로 길이가 모자라는 경우
                if (i - l < 0) {
                    return false;
                }
                // i-l부터 i-1까지 같은 높이인지 확인
                // 높이가 다르거나 경사로 설치된 곳이면 제외
                for (int j = i - l; j < i; j++) {
                    if (temp[j] != h || is_used[j]) {
                        return false;
                    }
                }
                for (int j = i - l; j < i; j++) {
                    is_used[j] = 1;
                }
            }
            // 높 -> 낮(현) 경우
            else {
                // 경사로 길이가 모자라는 경우
                if (i + l > n) {
                    return false;
                }
                // i부터 i+l-1까지 같은 높이인지 확인
                // 높이가 다르거나 경사로 설치된 곳이면 제외
                for (int j = i; j < i + l; j++) {
                    if (temp[j] != cur || is_used[j]) {
                        return false;
                    }
                }
                for (int j = i; j < i + l; j++) {
                    is_used[j] = 1;
                }
                // 건너뛰기
                i += l - 1;
            }
        }
        h = cur;
    }
    return true;
}

int main() {
    cin >> n >> l;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        // 행 기준 길찾기
        if (findLoad(m[i])) {
            ans++;
        }

        // 열 복사하기
        int temp[n];
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < n; j++) {
            temp[j] = m[j][i];
        }
        // 열 기준 길찾기
        if (findLoad(temp)) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}