#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    long long a, b, c;
    unordered_set<long long> s;
    vector<long long> v;

    cin >> a >> b >> c;
    long long temp = 1LL;

    a %= c;

    while (b > 0) {
        if (b % 2 == 1) {
            temp = (temp * a) % c;
        }
        b = b / 2;
        a = (a * a) % c;
    }
    cout << temp;

    return 0;
}