#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int calcDiff(string cur, string next) {
    if (cur > next) {
        return -1;
    }
    int diff = 0;
    int h1 = stoi(cur.substr(0, 2));
    int m1 = stoi(cur.substr(3));
    int h2 = stoi(next.substr(0, 2));
    int m2 = stoi(next.substr(3));

    diff = (h2 - h1) * 60 + (m2 - m1);

    return diff;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end());
    priority_queue<string, vector<string>, greater<>>
        pq; // 종료 시간 기준 오름차순 정렬 (빨리 끝나는 방 배정)

    for (auto book : book_time) {
        string start = book[0];
        string end = book[1];

        // 손님이 있는 객실이 없으면 추가
        if (pq.empty()) {
            pq.push(end);
            answer++;
            continue;
        }
        // 가장 빨리 끝나는 예약 - 현재 예약 차이가 10분 이상 나는 경우 같은
        // 객실 사용
        if (calcDiff(pq.top(), start) >= 10) {
            pq.pop();
            pq.push(end);
        }
        // 아닌 경우 추가 객실 사용
        else {
            pq.push(end);
            answer++;
        }
    }

    return answer;
}