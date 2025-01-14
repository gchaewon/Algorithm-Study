#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    string str;
    cin >> t;

    while (t--) {
        stack<char> s;
        cin >> str;

        s.push(str[0]);

        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '(') {
                s.push(str[i]);
                continue;
            }
            if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    s.push(str[i]);
                }
            }
        }
        if (s.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}