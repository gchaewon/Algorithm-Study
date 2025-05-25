#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<char> s = {'-', '_', '.'};

string toLower(string id) {
    string temp = "";
    for (auto c : id) {
        if (isupper(c)) {
            temp += tolower(c);
        } else {
            temp += c;
        }
    }
    return temp;
}

string removeInvalid(string id) {
    string temp = "";

    for (auto c : id) {
        if (s.find(c) != s.end() || isdigit(c) || isalpha(c)) {
            temp += c;
        }
    }
    return temp;
}
string compressDots(string id) {
    string temp = "";
    int mark = 0;

    for (auto c : id) {
        if (c == '.') {
            mark++;
        } else {
            if (mark >= 1) {
                temp += '.';
                mark = 0;
            }
            temp += c;
        }
    }
    return temp;
}

string removeDots(string id) {
    string temp = id;

    if (id.front() == '.') {
        temp = id.substr(1, temp.size());
    }
    if (id.back() == '.') {
        temp.pop_back();
    }
    return temp;
}
string shortenId(string id) {
    string temp = id.substr(0, 15);

    temp = removeDots(temp);
    return temp;
}

string extendId(string id) {
    string temp = id;

    while (temp.size() < 3) {
        temp += id.back();
    }
    return temp;
}

string solution(string new_id) {
    string answer = "";

    // 1단계 대문자 -> 소문자
    answer = toLower(new_id);

    // 2단계 특수 문자 제거
    answer = removeInvalid(answer);

    // 3단계 .. 연속 .로 치환
    answer = compressDots(answer);

    // 4단계 처음, 끝 . 제거
    answer = removeDots(answer);

    // 5단계 빈 문자열이라면 a 대입
    if (answer.size() == 0) {
        answer = "a";
    }

    // 6단계 16자 이상이면 길이 조정
    if (answer.size() >= 16) {
        answer = shortenId(answer);
    }

    // 7단계 2자 이하이면 3될때까지 붙이기
    if (answer.size() <= 2) {
        answer = extendId(answer);
    }

    return answer;
}