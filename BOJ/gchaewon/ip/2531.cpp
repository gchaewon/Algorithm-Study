#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, d, k, c;
    int ans = 0;
    cin >> n >> d >> k >> c;

    int sushi[n + 1];
    int eat[d + 1];

    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    for (int i = 0; i < n; i++) {
        int coupon = 1, cnt = 0;
        memset(eat, 0, sizeof(eat));
        for (int j = i; j < i + k; j++) {
            if (eat[sushi[j % n]] == 0) {
                eat[sushi[j % n]]++;
            } else {
                cnt++;
            }

            if (sushi[j % n] == c) {
                coupon = 0;
            }
        }
        int cur = k - cnt + coupon;
        ans = max(cur, ans);
    }
    cout << ans;

    return 0;
}