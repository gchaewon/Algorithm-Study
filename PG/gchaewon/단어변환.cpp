#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
int answer = 54;
int visited[54];

bool checkValid(string cur, string next) {
    int cnt = 0;
    // 현재 단어에서 1개 알파벳보다 많이 차이나는지 확인
    for (int i = 0; i < cur.size(); i++) {
        if (cur[i] != next[i]) {
            cnt++;
            // 1개 이상 차이나면 변환 불가
            if (cnt > 1) {
                return false;
            }
        }
    }
    return true;
}

void backTracking(string cur, string target, vector<string> words, int depth) {
    // 최단이 아닌 경우 제외
    if (depth > answer) {
        return;
    }
    // 타겟 단어와 같으면 종료
    if (cur == target) {
        answer = depth;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        // 이미 탐색한 단어면 제외
        if (visited[i]) {
            continue;
        }
        // 알파벳 1개 이상 차이나는 경우 제외
        if (!checkValid(cur, words[i])) {
            continue;
        }
        // 방문처리
        visited[i] = 1;
        // 탐색
        backTracking(words[i], target, words, depth + 1);
        // 원복
        visited[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {

    set<string> s;

    for (auto word : words) {
        s.insert(word);
    }

    // 단어 집합에 타겟 단어가 없는 경우 종료
    if (s.find(target) == s.end()) {
        return 0;
    }

    backTracking(begin, target, words, 0);

    return answer;
}