#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<char> vowel = {'A', 'E', 'I', 'O', 'U'};
set<string> dictionary;
char result[5];

void dfs(int cnt, int n) {
    if (cnt == n) {
        string temp = "";
        for (int i = 0; i < n; i++) {
            temp += result[i];
        }
        dictionary.insert(temp);
        return;
    }
    for (int i = 0; i < 5; i++) {
        result[cnt] = vowel[i];
        dfs(cnt + 1, n);
    }
}
int solution(string word) {
    long long answer = 0;

    for (int i = 1; i <= 5; i++) {
        dfs(0, i);
    }

    for (auto d : dictionary) {
        answer++;
        if (d == word) {
            return answer;
            break;
        }
    }
}