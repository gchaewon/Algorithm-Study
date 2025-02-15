#include <bits/stdc++.h>

using namespace std;

string add(string a, string b) {
    string ans = "";
    int sum = 0;

    // a 자리수 이상으로 carry 발생시 더하기
    while (a.size() || b.size() || sum) {
        // 뒤에서 부터 더하기
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ans += to_string((sum % 10));
        sum /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    string a, b, t;
    vector<int> ans;
    cin >> a >> b;

    cout << add(a, b);
    return 0;
}