#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int n = dungeons.size();
    sort(dungeons.begin(), dungeons.end()); // 순열 위한 정렬

    // 완전 탐색 모든 순열 고려
    do {
        int remain = k; // 남은 피로도
        int cnt = 0;    // 탐색한 던전 개수

        // 던전 순회하면서 개수 카운팅
        for (auto d : dungeons) {
            int min_h = d[0];
            int use_h = d[1];

            if (remain < min_h || remain - use_h < 0) {
                break;
            }
            remain -= use_h;
            cnt++;
        }
        // 최대 갯수 갱신
        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}