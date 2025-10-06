#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n;
    long long ans = 0;
    cin >> k >> n;
    vector<long long> len(k, 0);

    for (int i = 0; i < k; i++) {
        cin >> len[i];
    }
    sort(len.begin(), len.end());

    // 자를 랜선 길이 기준 이분 탐색
    long long l = 1, r = len[k - 1];

    while (l <= r) {
        long long mid = (l + r) / 2;

        int idx = lower_bound(len.begin(), len.end(), mid) - len.begin();
        int cnt = 0;
        bool flag = false;

        // mid보다 긴 랜선 순회하면서 만들 수 있는 개수 구하기
        for (int i = idx; i < k; i++) {
            cnt += len[i] / mid;
            if (cnt >= n) {
                flag = true;
                break;
            }
        }
        // n개 이상 만들 수 있으면 갱신, 자를 랜선 길이 늘림
        if (flag) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            // 만들 수 없으면, 자를 길이 줄임
            r = mid - 1;
        }
    }
    cout << ans;

    return 0;
}