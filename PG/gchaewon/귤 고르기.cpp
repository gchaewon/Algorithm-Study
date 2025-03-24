#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int remain = k;
    map<int, int> m;
    vector<pair<int, int>> v;

    for (auto t : tangerine) {
        m[t]++;
    }
    for (auto i : m) {
        v.push_back({i.second, i.first});
    }
    sort(v.rbegin(), v.rend());

    for (auto i : v) {
        int cur = i.first;
        if (remain - cur >= 0) {
            remain -= cur;
            answer++;
        } else if (remain > 0) {
            remain = 0;
            answer++;
        }
    }

    return answer;
}