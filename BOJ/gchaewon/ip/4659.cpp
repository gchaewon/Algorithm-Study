#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char temp) {
    if (vowel.find(temp) != vowel.end()) {
        return true;
    }
    return false;
}

int main() {
    string input;

    while (cin >> input) {
        bool is_valid = true;
        int v_count = 0;
        int c_count = 0;
        int v_total = 0;

        if (input == "end") {
            break;
        }

        if (isVowel(input[0])) {
            v_count++;
            v_total++;
        } else {
            c_count++;
        }

        for (int i = 1; i < input.size(); i++) {
            bool pre = isVowel(input[i - 1]);
            bool cur = isVowel(input[i]);

            // 같은 글자 연속 제외
            if (input[i] == input[i - 1] && input[i - 1] != 'e' &&
                input[i - 1] != 'o') {
                is_valid = false;
                break;
            }

            // 자/모음 연속 갯수 카운트
            if (cur) {
                v_count++;
                v_total++;
            } else {
                c_count++;
            }

            // 연속하지 않을 때 집계 초기화
            if (pre != cur || i == input.size() - 1) {
                if (v_count >= 3 || c_count >= 3) {
                    is_valid = false;
                    break;
                }
                if (cur) {
                    c_count = 0;
                } else {
                    v_count = 0;
                }
            }
        }

        if (is_valid && v_total != 0) {
            cout << "<" << input << ">" << " is acceptable.\n";
        } else {
            cout << "<" << input << ">" << " is not acceptable.\n";
        }
    }
    return 0;
}