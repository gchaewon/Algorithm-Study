#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬

    for (int s : scoville) {
        pq.push(s);
    }

    // 남은 음식이 있고, 스코빌 지수 조건을 만족하는 동안만 반복
    while (pq.size() && pq.top() < K) {
        answer++;
        int a, b;

        a = pq.top();
        pq.pop();

        // 남은 음식이 하나인 경우 종료
        if (pq.size()) {
            b = pq.top();
            pq.pop();
        } else {
            answer = -1;
            break;
        }

        int mixed = a + (b * 2);
        pq.push(mixed);
    }
    return answer;
}