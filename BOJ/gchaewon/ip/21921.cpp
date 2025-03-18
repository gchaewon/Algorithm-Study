#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[250004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    long long sum = 0LL;
    vector<long long> v;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < x; i++) {
        sum += a[i];
    }
    v.push_back(sum);

    for (int i = x; i < n; i++) {
        sum = sum - a[i - x] + a[i];
        if (sum > v[0]) {
            v.clear();
            v.push_back(sum);
        } else if (sum == v[0]) {
            v.push_back(sum);
        }
    }

    sort(v.rbegin(), v.rend());

    if (v[0] == 0) {
        cout << "SAD";
    } else {
        cout << v[0] << "\n" << v.size() << "\n";
    }
    return 0;
}