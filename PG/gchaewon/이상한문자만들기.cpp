#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string word = "";

    for (int i = 0; i < s.size(); i++) {
        word += s[i];
        // 단어 구분, 공백 위치이거나 마지막일 때
        if (s[i] == ' ' || i == s.size() - 1) {
            // 단어 순회하면서 대소문자 변경
            for (int j = 0; j < word.size(); j++) {
                if (j % 2 == 0) {
                    answer += toupper(word[j]);
                } else {
                    answer += tolower(word[j]);
                }
            }
            word.clear();
        }
    }
    return answer;
}