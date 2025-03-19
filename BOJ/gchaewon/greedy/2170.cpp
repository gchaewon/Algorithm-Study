#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
    int n;
    long long x, y, l, r;
    long long ans = 0LL;
    vector<pair<long, long>> v;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    l = v[0].X;
    r = v[0].Y;

    for (int i = 1; i < n; i++) {
        if (v[i].X > r) {
            ans += (r - l);
            l = v[i].X;
        }
        if (v[i].Y > r) {
            r = v[i].Y;
        }
    }
    ans += (r - l);

    cout << ans;
}