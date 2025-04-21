#include <iostream>
#include <vector>

const int MOD = 1000000000;

using namespace std;
int main() {
    int n;
    cin >> n;
    int m = abs(n);
    vector<int> f(m + 4, 0);  // 양수 값
    vector<int> mf(m + 4, 0); // 음수 값

    // 양수 식 f(n) = f(n-1)+f(n-2)
    // 음수 식 mf(n+2) = mf(n)-mf(n+1)

    f[0] = 0;
    f[1] = 1;
    mf[0] = 0;
    mf[1] = 1;

    if (n > 0) {
        for (int i = 2; i <= m; i++) {
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }
        if (f[m] > 0) {
            cout << 1;
        } else if (f[m] == 0) {
            cout << 0;
        } else {
            cout << -1;
        }
        cout << "\n" << abs(f[m]);
    } else {
        for (int i = 0; i <= m - 2; i++) {
            mf[i + 2] = (mf[i] - mf[i + 1]) % MOD;
        }
        if (mf[m] > 0) {
            cout << 1;
        } else if (mf[m] == 0) {
            cout << 0;
        } else {
            cout << -1;
        }
        cout << "\n" << abs(mf[m]);
    }

    return 0;
}