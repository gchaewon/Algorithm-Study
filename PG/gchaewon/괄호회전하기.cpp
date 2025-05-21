#include <deque>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;
map<char, char> p = {{')', '('}, {']', '['}, {'}', '{'}};

bool checkValid(deque<char> dq) {
    stack<char> st;

    while (!dq.empty()) {
        char c = dq.front();
        dq.pop_front();

        // 왼쪽 괄호면 스택에 추가
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
            continue;
        }
        // 스택이 비어있다면 추가
        if (st.empty()) {
            st.push(c);
            continue;
        }

        // 스택 위의 값이 맞는 짝이라면 제거
        char left = p[c];
        if (st.top() == left) {
            st.pop();
        }
        // 짝이 맞지 않으면 추가
        else {
            st.push(c);
        }
    }

    // 짝을 못찾은게 있다면 올바르지 않음
    if (!st.empty()) {
        return false;
    }

    return true;
}

int solution(string s) {
    int answer = 0;
    deque<char> dq;

    if (s.size() == 1) {
        return 0;
    }

    // 문자열 회전을 위한 deque
    for (int i = 0; i < s.size(); i++) {
        dq.push_back(s[i]);
    }

    // 한 칸씩 회전하면서 확인
    for (int i = 0; i < s.size(); i++) {
        if (checkValid(dq)) {
            answer++;
        }
        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }

    return answer;
}