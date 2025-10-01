#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    // 백트래킹으로도 풀어볼 것
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> arr(n, 0);
    set<set<int>> ans;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    // 뽑기 개수(cnt)에 따라서 반복
    for (int cnt = 2; cnt <= n; cnt++) {
        vector<int> sub_arr(n, 1);
        for (int i = 0; i < cnt; i++) {
            sub_arr[i] = 0;
        }
        // n개 중에 cnt개수 뽑는 조합
        do {
            set<int> idx;
            int min_num = INT_MAX, max_num = 0, sum = 0;
            bool flag = false;

            // cnt개수 만큼 수 뽑기
            for (int i = 0; i < sub_arr.size(); i++) {
                if (sub_arr[i] == 0) {
                    idx.insert(i);
                    min_num = min(min_num, arr[i]);
                    max_num = max(max_num, arr[i]);
                    sum += arr[i];
                    // 뽑는 중에 합이 조건 범위 벗어나면 중단
                    if (sum > r) {
                        flag = true;
                        break;
                    }
                }
            }
            // 조건이 맞지 않는 경우 제외
            if (flag || sum < l || (max_num - min_num) < x ||
                ans.find(idx) != ans.end()) {
                continue;
            }
            // 아닌 경우 뽑은 수의 인덱스 번호 set을 저장
            // (중복 수가 있기 때문에 idx로 관리)
            ans.insert(idx);

        } while (next_permutation(sub_arr.begin(), sub_arr.end()));
    }

    // 뽑을 수 있는 모든 경우의 수 출력
    cout << ans.size();

    return 0;
}