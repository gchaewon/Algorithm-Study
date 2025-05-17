#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ' ') {
            answer += c;
            continue;
        }
        int alpha = c + n;

        if ((c - 'a' >= 0 && alpha > 'z') || (c - 'a' < 0 && alpha > 'Z')) {
            alpha -= 26;
        }

        answer += (char)alpha;
    }
    return answer;
}