#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> m = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};
vector<vector<int>> e = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int answer = INT_MAX;

int calcResult(vector<int> v, vector<string> minerals) {
    int result = 0;
    int idx = 0;
    for (auto from : v) {
        for (int i = 0; i < 5; i++) {
            if (idx >= minerals.size()) {
                break;
            }
            if (result > answer) {
                return INT_MAX;
            }
            string cur = minerals[idx];
            int to = m[cur];
            result += e[from][to];
            idx++;
        }
    }
    return result;
}
int solution(vector<int> picks, vector<string> minerals) {
    vector<int> arr;
    for (int i = 0; i < picks.size(); i++) {
        for (int j = 0; j < picks[i]; j++) {
            arr.push_back(i);
        }
    }

    do {
        vector<int> temp;
        for (int i = 0; i < arr.size(); i++) {
            temp.push_back(arr[i]);
        }
        int result = calcResult(temp, minerals);
        answer = min(answer, result);
    } while (next_permutation(arr.begin(), arr.end()));

    return answer;
}