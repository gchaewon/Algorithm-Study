#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> heights(n, 0LL);
    stack<int> st; // {탑 번호} 0부터 시작

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // 첫 번째 탑 넣기
    cout << 0;
    st.push(0);

    for (int i = 1; i < n; i++) {
        cout << " ";
        long long cur = heights[i];

        // 왼쪽에 큰 탑이 있다면, 바로 출력
        if (cur < heights[st.top()]) {
            cout << st.top() + 1;
        } else { // 없다면 있을 때까지 스택 삭제
            while (!st.empty()) {
                // 큰 탑을 찾으면 번호 출력 후 종료
                if (cur < heights[st.top()]) {
                    cout << st.top() + 1;
                    break;
                }
                st.pop();
            }
            // 큰 탑이 없다면 0 출력
            if (st.size() == 0) {
                cout << 0;
            }
        }
        // 현재 위치 탑 추가
        st.push(i);
    }

    return 0;
}