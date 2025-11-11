#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    int t = 0;

    while (getline(cin, str)) {
        stack<char> st;
        int cnt1 = 0;
        int cnt2 = 0;
        if (str[0] == '-') {
            break;
        }

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '{') {
                st.push('{');
                continue;
            }
            if (str[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    cnt1++;
                }
            }
        }

        cnt1 = (cnt1 + 1) / 2;
        cnt2 = (st.size() + 1) / 2;

        cout << ++t << ". " << cnt1 + cnt2 << "\n";
    }
    return 0;
}