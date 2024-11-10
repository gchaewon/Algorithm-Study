#include <iostream>

using namespace std;
int main() {
    int n, temp, ans;
    while (cin >> n) {
        temp = ans = 1;
        while (true) {
            if (temp % n == 0) {
                cout << ans << "\n";
                break;
            }
            temp = temp * 10 + 1;
            temp %= n;
            ans++;
        }
    }

    return 0;
}