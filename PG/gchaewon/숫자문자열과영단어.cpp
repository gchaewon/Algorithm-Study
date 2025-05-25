#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    map<string, string> m = {{"zero", "0"},  {"one", "1"},   {"two", "2"},
                             {"three", "3"}, {"four", "4"},  {"five", "5"},
                             {"six", "6"},   {"seven", "7"}, {"eight", "8"},
                             {"nine", "9"}};

    string ans = "", temp = "";

    for (auto c : s) {
        int num = c - '0';
        // 원래 숫자인 경우 더하기
        if (num >= 0 && num <= 9) {
            ans += c;
        }

        else {
            temp += c;
            // 숫자 문자열이 완성된 경우 더하기
            if (m.find(temp) != m.end()) {
                ans += m[temp];
                temp.clear();
            }
        }
    }

    return stoi(ans);
}