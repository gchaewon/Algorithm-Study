#include <algorithm>
#include <iostream>
using namespace std;

int n, m, sum = 0, ans = 0;

void findAns(int start, int end, vector<int> v) {
    for (int pivot = start; pivot <= end; pivot++) {
        int temp_sum = 0;
        bool flag = true;

        for (auto cur : v) {
            if (temp_sum > m) {
                flag = false;
                break;
            }
            if (cur < pivot) {
                temp_sum += cur;
            } else {
                temp_sum += pivot;
            }
        }
        if (flag && sum < temp_sum && temp_sum <= m) {
            ans = pivot;
            sum = temp_sum;
        }
    }
}
int main() {
    int max_num = 0, min_num = 0;

    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        min_num = min(v[i], min_num);
        max_num = max(v[i], max_num);
    }

    sort(v.begin(), v.end());
    cin >> m;

    if (sum <= m) {
        cout << max_num;
        return 0;
    }

    sum = 0;
    findAns(min_num, m / n - 1, v);
    findAns(m / n, max_num, v);

    cout << ans;

    return 0;
}