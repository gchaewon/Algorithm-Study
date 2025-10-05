#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<long long> len(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> len[i];
    }
    // 입력 값 정렬
    sort(len.begin(), len.end());

    long long l = 1, r = len[n - 1];
    long long max_len = 0;

    while (l <= r) {
        long long mid = (l + r) / 2; // 나눠주는 길이

        // mid 길이보다 큰 길이값 시작 인덱스 구하기
        int idx = int(lower_bound(len.begin(), len.end(), mid) - len.begin());
        int cnt = 0;
        bool flag = false;

        // 해당 인덱스부터 끝까지 나눠줄 수 있는 명수 구하기
        for (int i = idx; i < n; i++) {
            cnt += len[i] / mid;
            // m명 보다 많은 경우 종료
            if (cnt >= m) {
                flag = true;
                break;
            }
        }

        // 조카 m명에게 나눠줄 수 있으면, 최대 길이 갱신, 탐색 길이 범위 올림
        if (flag) {
            l = mid + 1;
            max_len = mid;
        } else { // 아니면 탐색 길이 범위 낮춤
            r = mid - 1;
        }
    }
    cout << max_len;
    return 0;
}