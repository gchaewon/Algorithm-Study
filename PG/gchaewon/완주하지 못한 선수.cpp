#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = " ";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    queue<string> q;
    for (auto p : participant) {
        q.push(p);
    }

    for (auto c : completion) {
        string temp = q.front();
        if (temp == c) {
            q.pop();
        }
    }

    answer = q.front();

    return answer;
}