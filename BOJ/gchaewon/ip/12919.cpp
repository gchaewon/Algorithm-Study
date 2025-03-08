#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    set<string> comb;
    int flag = 0;
    cin >> s >> t;

    comb.insert(t);

    while (comb.size()) {
        if (comb.find(s) != comb.end()) {
            flag = 1;
            break;
        }
        set<string> temp_comb;
        for (auto str : comb) {
            if (str[0] == 'B') {
                string temp1 = str.substr(1, str.size() - 1);
                string temp2;
                for (int i = temp1.size() - 1; i >= 0; i--) {
                    temp2 += temp1[i];
                }
                temp_comb.insert(temp2);
            }

            if (str[str.size() - 1] == 'A') {
                temp_comb.insert(str.substr(0, str.size() - 1));
            }
        }
        comb = temp_comb;
    }

    cout << flag;
    return 0;
}