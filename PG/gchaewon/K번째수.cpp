#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto c : commands) {
        vector<int> temp;
        int i = c[0] - 1;
        int j = c[1];
        int k = c[2] - 1;
        for (int idx = i; idx < j; idx++) {
            temp.push_back(array[idx]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }
    return answer;
}