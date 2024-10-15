#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(string begin, string target, vector<string> v) {
    int answer = 0;
    string pre;
    int n = begin.length();
    vector<bool> is_finished(n, false); // n자리 알파벳이 타겟과 일치하는지 여부
    set<string> words;
    queue<string> q;

    // 단어 삭제를 편리하게 하기 위해, set 사용
    for (auto word : v) {
        words.insert(word);
    }

    q.push(begin);

    while (words.size() >= 0 && !q.empty()) {
        pre = q.front();
        q.pop();

        if (pre == target) {
            return answer;
        }

        for (auto word : words) {
            int diff = 0;
            int change = 0;
            for (int i = 0; i < n; i++) {
                // 알파벳 차이가 2개 이상이라면 (다음 단어로 변경 불가)
                if (diff >= 2) {
                    break;
                }
                if (word[i] != pre[i]) {
                    diff++;
                    change = i;
                }
            }
            // 알파벳 차이가 1개일 때
            if (diff == 1) {
                // 이미 완료한 자리는 바꾸지 않음
                if (is_finished[change]) {
                    break;
                }
                // 타겟 자리와 같은 자리라면 처리
                if (target[change] == word[change]) {
                    is_finished[change] = true;
                }
                q.push(word);
                words.erase(word);
                answer++;
                break;
            }
        }
    }

    return 0;
}