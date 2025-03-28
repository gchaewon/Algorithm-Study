#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> is_valid(n + 2, 1);
    vector<int> ans(n, 0);
    vector<pair<int, int>> v; // {키, 앞에있는 사람 수}

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        v.push_back({i, num});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur_cnt = v[j].second;
            int cur_h = v[j].first;

            if (!is_valid[cur_h]) {
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < i; k++) {
                if (ans[k] > cur_h) {
                    cnt++;
                }
            }
            if (cnt == cur_cnt) {
                ans[i] = cur_h;
                is_valid[cur_h] = 0;
                break;
            }
        }
    }

    for (auto a : ans) {
        cout << a << " ";
    }

    return 0;
}