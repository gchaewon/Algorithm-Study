#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    int ans = 0, temp = 0;
    stack<int> st;
    map<char, int> m = {{'H', 1}, {'C', 12}, {'O', 16}};
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        // 여는 괄호만나면 -1 넣기 (표시용)
        if (str[i] == '(') {
            st.push(-1);
            // 원자 만나면 값 push
        } else if (str[i] == 'H' || str[i] == 'C' || str[i] == 'O') {
            st.push(m[str[i]]);
            // 숫자 만나면 이전 계산값 * 숫자 해주기
        } else if (str[i] >= '2' && str[i] <= '9') {
            temp = st.top() * (str[i] - '0');
            st.pop();
            st.push(temp);
            // 괄호 닫는거 만나면, 괄호 내부 계산하고, 다시 push
        } else if (str[i] == ')') {
            int num = 0;
            while (st.top() != -1) {
                num += st.top();
                st.pop();
            }
            st.pop();
            st.push(num);
        }
    }
    // 총 계산한 값 다 더하기
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans << "\n";
    return 0;
}