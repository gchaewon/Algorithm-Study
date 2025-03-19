// 9935 문자열 폭발 스택 풀이
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str, bomb;
    string ans = "", temp = "";
    stack<char> s;

    cin >> str >> bomb;

    for (auto c : str) {
        s.push(c);
        // 폭발 문자열보다 크면 검사
        if (s.size() >= bomb.size()) {
            temp = "";
            for (int i = 0; i < bomb.size(); i++) {
                temp += s.top();
                s.pop();
            }
            reverse(temp.begin(), temp.end());

            // 폭발 문자열이 아니면 다시 스택에 넣기
            if (temp != bomb) {
                for (int i = 0; i < bomb.size(); i++) {
                    s.push(temp[i]);
                }
            }
        }
    }

    if (!s.size()) {
        cout << "FRULA";
    } else {
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        cout << ans;
    }

    return 0;
}