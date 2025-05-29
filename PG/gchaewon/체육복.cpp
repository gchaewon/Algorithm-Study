#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> remain(n + 1, 0);
    int cnt_lost = 0;

    // 여분 체육복 여부 저장
    for (int i = 0; i < reserve.size(); i++) {
        remain[reserve[i]] += 1;
    }

    for (int i = 0; i < lost.size(); i++) {
        // 여분 가져온 학생 중에 도난 당한 경우, 여분 체육복 삭제, 도난 해결
        // 처리
        if (remain[lost[i]]) {
            remain[lost[i]] -= 1;
            lost[i] = 0;
            continue;
        }
        cnt_lost++; // 도난 해결 안된 학생수 카운팅
    }

    answer = n - cnt_lost;

    // 순서대로 빌리기 위해서 정렬
    sort(lost.begin(), lost.end());

    for (auto l : lost) {
        // 해결된 학생 건너뛰기
        if (l == 0) {
            continue;
        }
        int left = l - 1;
        int right = l + 1;

        // 왼쪽 학생에 여분이 있는 경우 (왼쪽부터 빌림)
        if (left >= 1 && remain[left]) {
            remain[left] -= 1;
            answer += 1;
            continue;
        }

        // 오른쪽 학생에 여분이 있는 경우
        if (right <= n && remain[right]) {
            remain[right] -= 1;
            answer += 1;
            continue;
        }
    }

    return answer;
}