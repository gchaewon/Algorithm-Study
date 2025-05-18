#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string ns = s;

    int cnt = 0, zero = 0;

    while (ns != "1") {
        string temp = "";
        // 0 제거하기
        for (int i = 0; i < ns.size(); i++) {
            if (ns[i] == '0') {
                zero++;
                continue;
            }
            temp += ns[i];
        }

        int c = temp.size();

        // 이진 변환하기
        string binary = "";
        while (c > 0) {
            // 뒤에서부터 (LSB) 구하기 때문에 앞으로 더하기
            binary = to_string(c % 2) + binary;
            c >>= 1; // c/2
        }

        ns = binary;
        cnt++;
    }
    answer = {cnt, zero};

    return answer;
}