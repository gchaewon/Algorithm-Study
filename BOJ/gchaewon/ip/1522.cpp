#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<int> index;
    cin >> s;
    int cnt = 0, ans = 1000;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
            cnt++;
            index.push_back(i);
        }
    }

    if (index.size() == 0) {
        cout << 0;
        return 0;
    }

    for (auto idx : index) {
        int temp = 0;
        for (int j = idx; j < idx + cnt; j++) {
            if (s[j % s.size()] != 'b') {
                temp++;
            }
        }
        ans = min(ans, temp);
    }
    cout << ans;
    return 0;
}