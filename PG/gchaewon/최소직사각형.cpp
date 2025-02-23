#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 1;

    int w = 0, h = 0;

    // w-작은거, h-큰거
    // 최대값으로 갱신 (명함 최대길이 만큼 커야함)
    for (auto s : sizes) {
        w = max(w, max(s[0], s[1]));
        h = max(h, min(s[0], s[1]));
    }

    answer = w * h;
    return answer;
}