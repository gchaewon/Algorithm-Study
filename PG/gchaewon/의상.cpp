#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> cnt;

    for (auto cloth : clothes) {
        if (cnt.find(cloth[1]) != cnt.end()) {
            cnt[cloth[1]]++;
        } else {
            cnt.insert({cloth[1], 1});
        }
    }

    for (auto i : cnt) {
        answer *= (i.second + 1);
    }

    answer -= 1;

    return answer;
}