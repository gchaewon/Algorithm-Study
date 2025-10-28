#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool cmp(vector<string> &a, vector<string> &b) { return a[1] < b[1]; }
// hh:mm 형태 시간, 분으로 구분하고 정수형으로 리턴하는 함수
vector<int> tokenizer(string s) {
    vector<int> tokens;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, ':')) {
        tokens.push_back(stoi(temp));
    }
    return tokens;
}
// hh-mm 시간에 분 더하고 hh-mm으로 변환하는 함수
string calcTime(string t1, int min) {
    vector<int> tokens = tokenizer(t1);

    int h1 = tokens[0];
    int m1 = tokens[1];

    string h = to_string(h1 + (m1 + min) / 60);
    string m = to_string((m1 + min) % 60);

    return h + ":" + m;
}
// hh-mm 형식 string으로, 분 차이 구하는 함수
int calcDiff(string t1, string t2) {
    vector<int> t1_tokens = tokenizer(t1);
    vector<int> t2_tokens = tokenizer(t2);

    int h1 = t1_tokens[0];
    int m1 = t1_tokens[1];
    int h2 = t2_tokens[0];
    int m2 = t2_tokens[1];

    int diff = (h2 - h1) * 60 + (m2 - m1);

    return diff;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> stopped; // {과제명, 남은 시간}
    sort(plans.begin(), plans.end(), cmp); // {과제명, 시작 시간, 수행 시간}

    for (int i = 0; i < plans.size() - 1; i++) {
        vector<string> cur = plans[i];
        vector<string> next = plans[i + 1];

        int diff = calcDiff(cur[1], next[1]);

        // 현재 과제가 다음 과제보다 먼저 끝나는 경우
        if (stoi(cur[2]) <= diff) {
            answer.push_back(cur[0]);
            int remain = diff - stoi(cur[2]);
            string time = calcTime(cur[1], stoi(cur[2]));

            // 남은 시간만큼 중단된 과제 재개
            while (stoi(cur[2]) != diff && !stopped.empty()) {
                pair<string, int> stop = stopped.top();
                stopped.pop();
                diff = calcDiff(time, next[1]);
                // 중단된 과제가 다음 과제보다 일찍 끝나는 경우 종료 처리
                if (stop.second <= diff) {
                    answer.push_back(stop.first);
                    time = calcTime(time, stop.second);
                }
                // 아니면 중단하고, 한 시간 업데이트
                else {
                    stopped.push({stop.first, stop.second - diff});
                    break;
                }
            }
        } else { // 현재 과제가 다음 과제보다 늦게 끝나는 경우
            // 남은 시간 저장 후 중단
            stopped.push({cur[0], stoi(cur[2]) - diff});
        }
    }
    // 마지막 과제, 중단된 과제처리
    vector<string> last = plans.back();
    answer.push_back(last[0]);

    while (!stopped.empty()) {
        answer.push_back(stopped.top().first);
        stopped.pop();
    }

    return answer;
}