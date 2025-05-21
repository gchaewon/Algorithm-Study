#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> s;

    // 스킬 set에 저장
    for (int i = 0; i < skill.size(); i++) {
        s.insert(skill[i]);
    }

    for (auto tree : skill_trees) {
        int cur = 0; // skill 인덱스
        bool is_valid = true;

        // 첫 스킬이 배워야하는 순서에 포함되어있지만, 처음으로 배워야하는
        // 스킬이 아닌 경우 제외
        if (s.find(tree[0]) != s.end() && tree[0] != skill[0]) {
            continue;
        }

        for (auto t : tree) {
            // 배워야하는 스킬이 아닌 경우 검사 X
            if (s.find(t) == s.end()) {
                continue;
            }
            // 순서에 맞는 스킬이 아닌 경우 불가능한 스킬트리
            if (skill[cur] != t) {
                is_valid = false;
                break;
            }
            cur += 1;
        }

        if (is_valid) {
            answer++;
        }
    }
    return answer;
}