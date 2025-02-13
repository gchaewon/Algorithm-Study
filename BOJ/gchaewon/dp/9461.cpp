#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dp(int max_n, vector<int> &n) {
    vector<long long> arr(max_n, 0LL);

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i < max_n; i++) {
        arr[i] = arr[i - 3] + arr[i - 2];
    }
    for (auto i : n) {
        cout << arr[i - 1] << "\n";
    }
}
int main() {
    int t;
    int max_n = 0;
    cin >> t;
    vector<int> n(t, 0);

    for (int i = 0; i < t; i++) {
        cin >> n[i];
        max_n = max(max_n, n[i]);
    }

    dp(max_n, n);

    return 0;
}