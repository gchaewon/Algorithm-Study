#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;

    for (auto oper : operations) {
        char opt = oper[0];
        string temp = oper.substr(2);
        int num = stoi(temp);

        switch (opt) {
        case 'I':
            dq.push_back(num);
            break;
        case 'D':
            if (num == 1) {
                if (!dq.empty()) {
                    dq.pop_front();
                }
            } else {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
        }
        sort(dq.rbegin(), dq.rend());
    }

    if (dq.empty()) {
        answer = {0, 0};
    } else {
        answer = {dq.front(), dq.back()};
    }

    return answer;
}