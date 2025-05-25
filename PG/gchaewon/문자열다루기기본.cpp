#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    // 길이 조건 만족하지 않은 경우 제외
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }

    for (auto c : s) {
        int n = c - '0';
        // 숫자값이 아닌 경우 제외
        if (n < 0 || n > 9) {
            return false;
        }
    }
    return answer;
}