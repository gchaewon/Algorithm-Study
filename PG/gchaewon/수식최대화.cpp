#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

long long calc(char op, long long a, long long b) {
    if (op == '+') {
        return a + b;
    }
    if (op == '-') {
        return a - b;
    }
    return a * b;
}
// op 연산자가 있는지 확인하는 함수
bool check(vector<char> tops, char op) {
    for (int i = 0; i < tops.size(); i++) {
        if (tops[i] == op) {
            return true;
        }
    }
    return false;
}

long long getPrice(vector<char> priority, vector<long long> nums,
                   vector<char> ops) {
    long long price = 0, inner = 0;
    vector<long long> tnums = nums;
    vector<char> tops = ops;

    cout << ": ";
    for (auto p : priority) {
        while (check(tops, p)) {
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] == p) {
                    // 괄호 내부 계산
                    inner = calc(tops[i], tnums[i], tnums[i + 1]);
                    // 계산 결과로 업데이트
                    tnums[i] = inner;
                    // 계산한 피연산자, 연산자 제거
                    tnums.erase(tnums.begin() + i + 1);
                    tops.erase(tops.begin() + i);
                    break;
                }
            }
        }
    }
    price = inner;
    return abs(price);
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> ops, comb;
    set<char> s; // 중복 제거용

    string temp = "";
    // 식에서 숫자, 연산자 분리
    for (auto c : expression) {
        if (c == '+' || c == '-' || c == '*') {
            if (temp.size()) {
                nums.push_back(stoll(temp));
                temp.clear();
            }
            ops.push_back(c);
            s.insert(c);
        } else {
            temp += c;
        }
    }
    if (temp.size()) {
        nums.push_back(stoll(temp));
    }
    // 연산자 우선순위 경우의 수 구하기
    for (auto i : s) {
        comb.push_back(i);
    }
    do {
        vector<char> temp;
        for (int i = 0; i < comb.size(); i++) {
            temp.push_back(comb[i]);
        }
        answer = max(answer, getPrice(temp, nums, ops));
    } while (next_permutation(comb.begin(), comb.end()));

    return answer;
}