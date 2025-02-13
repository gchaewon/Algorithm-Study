#include <bits/stdc++.h>

using namespace std;

int n, mp, mf, ms, mv;
vector<vector<int>> foods(16, vector<int>(5, 0));

int check(vector<int> foods_num) {
    int sum_mp = 0, sum_mf = 0, sum_ms = 0, sum_mv = 0, cost = 0;
    for (auto idx : foods_num) {
        sum_mp += foods[idx][0];
        sum_mf += foods[idx][1];
        sum_ms += foods[idx][2];
        sum_mv += foods[idx][3];
        cost += foods[idx][4];
        if (sum_mp >= mp && sum_mf >= mf && sum_ms >= ms && sum_mv >= mv) {
            return cost;
        }
    }
    return -1;
}
int main() {
    cin >> n >> mp >> mf >> ms >> mv;
    vector<int> ans_num;
    int ans_cost = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> foods[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        vector<int> foods_num;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                foods_num.push_back(j);
                int temp_cost = check(foods_num);

                // 유효한 경우라면 (비용이 -1 아님)
                if (temp_cost >= 0) {
                    // 비용 비교하고 갱신
                    if (temp_cost < ans_cost) {
                        ans_cost = temp_cost;
                        ans_num = foods_num;
                        // 비용이 동일하다면, 경우의 수 번호를 비교 후 갱신
                    } else if (temp_cost == ans_cost) {
                        if (foods_num < ans_num) {
                            ans_num = foods_num;
                        }
                    }
                }
            }
        }
    }

    // 비용 갱신이 없는 경우는 -1 출력
    if (ans_cost == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << ans_cost << "\n";
        for (auto n : ans_num) {
            cout << n + 1 << " ";
        }
    }

    return 0;
}