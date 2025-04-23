#include <cmath>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = pow(10, 12);

long long n, p, q;
map<long long, long long> a; // {n, an}

long long recursion(long long idx) {
    // 0일 때 중단
    if (idx == 0) {
        return 1;
    }
    // 이미 계산한 것이라면
    if (a.find(idx) != a.end()) {
        return a[idx];
    }
    long long idx1 = floor(idx / p);
    long long idx2 = floor(idx / q);

    // 값 저장하기
    a[idx] = recursion(idx1) + recursion(idx2);

    return a[idx];
}
int main() {

    cin >> n >> p >> q;

    a[0] = 1LL;

    cout << recursion(n);

    return 0;
}