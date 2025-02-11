#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    map<string, int> m; // 카테고리별 옷 가지수 저장

    for (auto cloth : clothes) {
        if (m.find(cloth[1]) != m.end()) { // 등록되어 있는 경우, 숫자만 증가
            m[cloth[1]]++;
        } else {
            m.insert({cloth[1], 1}); // 없는 경우, 새로 넣기
        }
    }

    for (auto i : m) {
        ans *= (i.second + 1); // 옷 가지수 + 선택하지 않는 경우 1
    }
    ans -= 1; // 아무것도 입지 않는 경우 제외

    return ans;
}