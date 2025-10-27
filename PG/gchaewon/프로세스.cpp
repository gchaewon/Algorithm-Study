#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first != b.first) {
            return a.first < b.first; // 내림차순
        }
        return a.second > b.second; // 오름차순
    }
};
int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    // {우선 순위, 들어온 순서}
    deque<pair<int, int>> dq;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push({priorities[i], i});
        dq.push_back({priorities[i], i});
    }

    while (!dq.empty() && !pq.empty()) {
        // 우선 순위가 가장 높은 프로세스의 값과 같은 프로세스가 나올 때까지
        // 뒤로 보내기
        while (dq.front().first != pq.top().first) {
            pair<int, int> temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        // 찾은 후에 덱, 우선 순위 큐에서 값 제거
        int idx = dq.front().second;
        dq.pop_front();
        pq.pop();

        answer++;
        // 찾고자 하는 인덱스와 일치하는 경우 종료
        if (idx == location) {
            break;
        }
    }

    return answer;
}