#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1234567;
const int MAX_N = 100004;

int solution(int n) {
    vector<int> f(MAX_N, 0);

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    return f[n];
}