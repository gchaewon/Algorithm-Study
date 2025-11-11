#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> tokens;
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ' && str[i] != '<') {
            string temp = "";
            while (i < str.size() && str[i] != ' ' && str[i] != '<') {
                temp += str[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            tokens.push_back(temp);
        }

        if (str[i] == ' ') {
            tokens.push_back(" ");
            continue;
        }
        if (str[i] == '<') {
            string temp = "";
            while (str[i] != '>') {
                temp += str[i];
                i++;
            }
            temp += '>';
            tokens.push_back(temp);
        }
    }

    for (auto token : tokens) {
        cout << token;
    }

    return 0;
}