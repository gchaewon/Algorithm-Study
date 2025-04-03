#include <iostream>

using namespace std;

int main() {
    int n, b, c;
    long long ans = 0LL;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> b >> c;

    for (int i = 0; i < n; i++) {
        ans += 1;
        a[i] -= b; // 정감독 커버 인원 제외

        if (a[i] <= 0) { // 정감독만 있어도 되는 경우
            continue;
        }
        int s = a[i] / c;
        int r = a[i] % c;
        ans += s;

        if (r) { // 남은 학생이 있다면 부감독 추가
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}