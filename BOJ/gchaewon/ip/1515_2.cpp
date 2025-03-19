#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1;
    int idx = 0, n = 1;

    while (idx < s1.size()) {
        s2 = to_string(n);
        // 1부터 자리 수 비교하면서 idx 더하기
        for (int i = 0; i < s2.size(); i++) {
            if (s1[idx] == s2[i]) {
                idx++;
                // 자리수가 수 길이 넘으면 종료
                if (idx >= s1.size()) {
                    cout << n;
                    return 0;
                }
            }
        }
        n++;
    }
    return 0;
}