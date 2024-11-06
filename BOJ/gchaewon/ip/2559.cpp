#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    vector<int> sum;
    int pre = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i < k) {
            pre += v[i];
        }
    }
    sum.push_back(pre);

    for (int i = k; i < n; i++) {
        pre = pre - v[i - k] + v[i];
        sum.push_back(pre);
    }

    sort(sum.rbegin(), sum.rend());
    sum.push_back(0);
    cout << sum[0];

    return 0;
}