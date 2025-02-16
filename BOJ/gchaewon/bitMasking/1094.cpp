#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    int n = 64;
    int ans = 0;
    cin >> x;

    while (x > 0) {
        while (x < n) {
            n = n >> 1;
        }
        x -= n;
        ans++;
    }
    cout << ans;
    return 0;
}