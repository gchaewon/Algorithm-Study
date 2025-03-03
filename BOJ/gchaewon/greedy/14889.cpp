#include <bits/stdc++.h>

using namespace std;

int n;
int ans = INT_MAX;
vector<vector<int>> v(21, vector<int>(21, 0));

int getDiff(vector<int> t1, vector<int> t2) {
    int sum1 = 0, sum2 = 0, diff = 0;

    // 교차점 구하기
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            sum1 += v[t1[i]][t1[j]];
            sum2 += v[t2[i]][t2[j]];
        }
    }
    return abs(sum1 - sum2);
}
int main() {
    cin >> n;
    vector<int> sub_arr(n, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        sub_arr[i] = 0;
    }

    do {
        vector<int> t1, t2;
        for (int i = 0; i < n; i++) {
            if (sub_arr[i] == 0) {
                t1.push_back(i + 1);
            } else {
                t2.push_back(i + 1);
            }
        }
        ans = min(ans, getDiff(t1, t2));
    } while (next_permutation(sub_arr.begin(), sub_arr.end()));

    cout << ans;
    return 0;
}