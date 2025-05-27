#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int solution(string before, string after) {
    int answer = 1;
    map<char, int> m; // {문자, 갯수}

    // 구성 문자 갯수 저장
    for (char b : before) {
        m[b]++;
    }

    // 문자 갯수가 일치하는지 확인
    for (char a : after) {
        // 구성 문자가 없거나, 모자란 경우 제외
        if (m.find(a) == m.end() || m[a] == 0) {
            answer = 0;
            break;
        }
        m[a]--;
    }
    return answer;
}