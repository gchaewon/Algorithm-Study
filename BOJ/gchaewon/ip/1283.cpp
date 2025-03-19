#include <bits/stdc++.h>
using namespace std;

int n;
int alpha[26];

void print(vector<string> &words, string str) {
    bool flag = false;
    string s1, s2;
    string ans = "";

    // 단어 첫 글자 우선 조회
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (!alpha[toupper(word[0]) - 'A'] && !flag) {
            ans +=
                "[" + word.substr(0, 0) + word[0] + "]" + word.substr(1) + " ";
            alpha[toupper(word[0]) - 'A'] = 1;
            flag = true;
            continue;
        }
        ans += word;
        if (i != words.size() - 1) {
            ans += " ";
        }
    }
    // 문장 전체에서 조회
    if (!flag) {
        ans = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ' && !alpha[toupper(str[i]) - 'A']) {
                ans +=
                    str.substr(0, i) + "[" + str[i] + "]" + str.substr(i + 1);
                flag = true;
                alpha[toupper(str[i]) - 'A'] = 1;
                break;
            }
        }
    }

    if (flag) {
        cout << ans << "\n";
        return;
    } else {
        cout << str << "\n";
    }
}

int main() {
    string str;
    getline(cin, str);
    n = stoi(str);

    for (int i = 0; i < n; i++) {
        getline(cin, str);
        vector<string> words;

        string temp = "";
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == ' ') {
                words.push_back(temp);
                temp = "";
                continue;
            }
            temp += str[j];
        }
        words.push_back(temp);

        print(words, str);
    }

    return 0;
}