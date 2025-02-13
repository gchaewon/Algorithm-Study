#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    int count = 0;

    cin >> n;
    while (n--) {
        stack<char> s;
        string word;
        cin >> word;
        for (auto i : word) {
            if (!s.empty()) {
                if (s.top() == i) {
                    s.pop();
                    continue;
                }
            }
            s.push(i);
        }
        if (s.empty()) {
            count++;
        }
    }
    cout << count;
    return 0;
}