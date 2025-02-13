#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int ans = 0;
void recur(int x, int y, int n) {
    if (n == 1) {
        return;
    }
    int half = n / 2;
    int size = half * half;

    // 4개로 분할하여 탐색
    // 왼쪽 위 0<=r<half, 0<=c<half
    if (r < x + half && c < y + half) {
        recur(x, y, half);
    }
    // 오른쪽 위 0<=r<half, half<=c<n
    else if (r < x + half && c >= y + half) {
        ans += size;
        recur(x, y + half, half);
    }
    // 왼쪽 아래 half<=r<n, 0<=c<half
    else if (r >= x + half && c < y + half) {
        ans += 2 * size;
        recur(x + half, y, half);
    }
    // 오른쪽 아래 half<=r<n, half<=c<n
    else {
        ans += 3 * size;
        recur(x + half, y + half, half);
    }
}
int main() {
    cin >> N >> r >> c;

    N = pow(2, N);
    recur(0, 0, N);
    cout << ans;
    return 0;
}