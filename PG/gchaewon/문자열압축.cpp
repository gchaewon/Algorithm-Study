#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pressor(string s, int cnt, int n) {
    string pre = s.substr(0, cnt);
    string ns = "", cur = "";
    int pos = 0;

    for (int i = cnt; i < n; i += cnt) {
        cur = s.substr(i, cnt);
        if (pre == cur) {
            pos++;
            continue;
        }
        if (pos > 0) {
            ns += to_string(pos + 1);
            pos = 0;
        }
        ns += pre;
        pre = cur;
    }

    // 남은 단위 더하기
    if (pos > 0) {
        ns += to_string(pos + 1);
    }
    ns += pre;

    return ns.size();
}
int solution(string s) {
    int answer = 1004;
    int n = s.size();

    // i개씩 자를 때 압축한 문자열 길이 최솟값 구하기
    for (int i = 1; i <= n; i++) {
        answer = min(answer, pressor(s, i, n));
    }
    return answer;
}