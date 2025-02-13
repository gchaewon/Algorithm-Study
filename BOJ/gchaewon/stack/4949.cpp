#include <iostream>
#include <stack>
using namespace std;

int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == ".") {
            break;
        }
        stack<char> s;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(' || line[i] == '[') {
                s.push(line[i]);
            } else if (line[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    s.push(line[i]);
                    break;
                }
                s.pop();
            } else if (line[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    s.push(line[i]);
                    break;
                }
                s.pop();
            }
        }

        if (s.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}