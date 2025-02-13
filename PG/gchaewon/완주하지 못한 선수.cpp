#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = " ";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int n = completion.size();
    for (int i = 0; i < n; i++) {
        // 인덱스가 다른 경우 (완주를 하지 못한 참가자)
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }
    // 완주를 하지 못한 참가자가 가장 마지막 위치인 경우
    answer = participant[n];

    return answer;
}