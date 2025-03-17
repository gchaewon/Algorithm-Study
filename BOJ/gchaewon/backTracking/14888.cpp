#include <bits/stdc++.h>

using namespace std;

int n, min_ans = INT_MAX, max_ans = -INT_MAX + 1;
int a[15], opr[4];

void backTracking(int result, int cnt) {
    if (cnt == n) {
        min_ans = min(result, min_ans);
        max_ans = max(result, max_ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!opr[i]) {
            continue;
        }
        opr[i] -= 1;
        switch (i) {
        case 0:
            backTracking(result + a[cnt], cnt + 1);
            break;
        case 1:
            backTracking(result - a[cnt], cnt + 1);
            break;
        case 2:
            backTracking(result * a[cnt], cnt + 1);
            break;
        case 3:
            backTracking(result / a[cnt], cnt + 1);
            break;
        }

        opr[i] += 1;
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> opr[i];
    }

    backTracking(a[0], 1);

    cout << max_ans << "\n" << min_ans;
}