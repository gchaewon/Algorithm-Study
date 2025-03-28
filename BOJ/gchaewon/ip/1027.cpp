#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n], ans[n];
    memset(h, 0, sizeof(h));
    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        double max_g = INT_MAX * -1.0;

        for (int j = i + 1; j < n; j++) {
            double g = double(h[j] - h[i]) / (j - i);

            if (g <= max_g) {
                continue;
            }

            // 기울기가 최댓값보다 크면 보이는 건물
            max_g = g;
            // 서로 보이는 건물이므로 개수 +1
            ans[i]++;
            ans[j]++;
        }
    }

    sort(ans, ans + n);
    cout << ans[n - 1];

    return 0;
}
