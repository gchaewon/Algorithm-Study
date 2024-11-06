#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    int count = 0;
    cin >> n >> m;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        s.insert(input);
    }

    for (auto i : s) {
        if (s.find(m - i) != s.end()) {
            count++;
        }
    }
    cout << count / 2;

    return 0;
}