#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main() {
    int n, x, y;
    int ans = 0;
    stack<int> st;
    cin >> n;

    while (n--) {
        cin >> x >> y;

        // 높이가 0이 될 때 스택에 쌓인 블럭 전체 카운팅, 스택 초기화
        if (y == 0) {
            while (!st.empty()) {
                st.pop();
                ans += 1;
            }
            continue;
        }

        // 높이가 작아졌을 때, 기존 블록 개수 카운팅
        while (!st.empty()) {
            if (st.top() <= y) {
                break;
            }
            st.pop();
            ans += 1;
        }
        // 비어있거나, 제일 위 블럭이 같은 높이가 아니라면 추가
        if (st.empty() || st.top() != y) {
            st.push(y);
        }
    }

    // 남은 블럭 반영
    ans += st.size();

    cout << ans;
    return 0;
}