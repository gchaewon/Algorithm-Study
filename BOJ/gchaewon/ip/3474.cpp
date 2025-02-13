#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, cnt_2, cnt_5;
    int max_num = 0;

    cin >> t;

    while (t--) {
        cin >> n;
        cnt_2 = cnt_5 = 0;

        for (int i = 2; i <= n; i *= 2) {
            cnt_2 += n / i;
        }

        for (int i = 5; i <= n; i *= 5) {
            cnt_5 += n / i;
        }

        cout << min(cnt_2, cnt_5) << "\n";
    }
    return 0;
}