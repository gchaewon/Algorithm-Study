#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, sum = 0, ans = 0;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    cin >> m;

    if (sum <= m) {
        cout << v[n - 1];
        return 0;
    }

    int left = 0, right = v[n - 1];

    while (left <= right) {
        sum = 0;
        int mid = (left + right) / 2;

        for (auto num : v) {
            sum += min(mid, num);
        }

        if (sum > m) {
            right = mid - 1;
        } else {
            left = mid + 1;
            ans = mid;
        }
    }

    cout << ans;

    return 0;
}