#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> count;
    vector<vector<int>> v = {{1, 2, 3, 4, 5},
                             {2, 1, 2, 3, 2, 4, 2, 5},
                             {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

    for (int i = 0; i < 3; i++) {
        count.push_back({0, i});
    }
    for (int i = 0; i < answers.size(); i++) {
        if (v[0][i % 5] == answers[i]) {
            count[0].first++;
        }
        if (v[1][i % 8] == answers[i]) {
            count[1].first++;
        }
        if (v[2][i % 10] == answers[i]) {
            count[2].first++;
        }
    }

    sort(count.rbegin(), count.rend());

    answer.push_back(count[0].second + 1);

    for (int i = 1; i < 3; i++) {
        if (count[i - 1].first > count[i].first) {
            break;
        }
        answer.push_back(count[i].second + 1);
    }

    sort(answer.begin(), answer.end());

    return answer;
}