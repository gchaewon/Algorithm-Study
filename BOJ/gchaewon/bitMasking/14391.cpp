#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[5][5];

int main() {
    int n, m;
    int ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            a[i][j] = line[j] - '0';
        }
    }

    // N * M 모든 좌표 경우의 수 (가로 블럭->0, 세로 블럭->1)
    for (int s = 0; s < (1 << (n * m)); s++) {
        int sum = 0;

        // 가로 블럭 더하기
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                // k = 왼쪽 상단부터 칸 번호
                // 1 2 3
                // 4 5 6
                int k = i * m + j;

                // 해당 위치가 0이면 (가로 블럭) 누적해서 더하기 4 8 = 40 + 8
                if ((s & (1 << k)) == 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    // 해당 위치가 1이면 (세로 블럭) 더하기 중단
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        // 세로 블럭 더하기
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int k = i * m + j;
                // 해당 위치가 1이면 (세로 블럭) 누적해서 더하기 4 8 = 40 + 8
                if ((s & (1 << k)) != 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    // 해당 위치가 0이면 (가로 블럭) 더하기 중단
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}