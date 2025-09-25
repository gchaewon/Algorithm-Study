#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int m;
string str;
stack<char> s1, s2; // 커서 기준 왼쪽, 오른쪽 문자열

// 커서 왼쪽으로 옮기기
void moveLeft() {
    if (s1.empty()) {
        return;
    }
    s2.push(s1.top());
    s1.pop();
}
// 커서 오른쪽으로 옮기기
void moveRight() {
    if (s2.empty()) {
        return;
    }
    s1.push(s2.top());
    s2.pop();
}
// 커서 왼쪽에 있는거 하나 삭제하기
void deleteLeft() {
    if (s1.empty()) {
        return;
    }
    s1.pop();
}
// 커서 왼쪽에 하나 추가하기
void addLeft(char add) { s1.push(add); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;

    for (auto c : str) {
        s1.push(c);
    }
    cin >> m;

    while (m--) {
        char op;
        cin >> op;
        switch (op) {
        case 'L':
            moveLeft();
            break;
        case 'D':
            moveRight();
            break;
        case 'B':
            deleteLeft();
            break;
        case 'P':
            char add;
            cin >> add;
            addLeft(add);
        }
    }

    string ans;
    // 커서 왼쪽 문자열 더하기
    while (!s1.empty()) {
        ans += s1.top();
        s1.pop();
    }
    reverse(ans.begin(), ans.end());

    // 커서 오른쪽 문자열 더하기
    while (!s2.empty()) {
        ans += s2.top();
        s2.pop();
    }

    cout << ans;

    return 0;
}