#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, ans = 0;
    string s;
    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] != 'P') {
            continue;
        }

        for (int j = i - k; j <= i + k; j++) {
            if (j >= 0 && j < n && s[j] == 'H') {
                ans++;
                s[j] = 'C';
                break;
            }
        }
    }

    cout << ans;

    return 0;
}