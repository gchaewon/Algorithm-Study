#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
    stack<char> st;
    bool answer = true;

    for (auto c : s) {
        // 비어있다면 추가
        if (st.empty()) {
            st.push(c);
            continue;
        }
        // 왼쪽 괄호면 추가
        if (c == '(') {
            st.push(c);
            continue;
        }
        // 오른쪽 괄호고 짝이 맞는게 있으면 스택에서 제거
        if (c == ')' && st.top() == '(') {
            st.pop();
        }
    }
    if (!st.empty()) {
        answer = false;
    }

    return answer;
}