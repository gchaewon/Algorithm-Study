#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int remain = n;
    priority_queue<int> pq;

    for (auto work : works) {
        pq.push(work);
    }

    int cnt = 0;
    while (remain-- && !pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if (cur - 1 > 0) {
            pq.push(cur - 1);
        }
    }

    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}