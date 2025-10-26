#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Job {
    int idx, r_time, w_time;
};
struct cmp {
    bool operator()(const Job &a, const Job &b) {
        if (a.w_time != b.w_time) {
            return a.w_time > b.w_time;
        }
        if (a.r_time != b.r_time) {
            return a.r_time > b.r_time;
        }
        return a.idx > b.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<Job, vector<Job>, cmp> pq;

    // 작업 요청 시각 기준 정렬
    sort(jobs.begin(), jobs.end());
    int idx = 0, t = 0, n = jobs.size();

    while (true) {
        if (idx >= n && pq.empty()) {
            break;
        }
        // 대기열에 넣어도 되는 작업 넣기 (요청 시각 <= 현재시각)
        while (idx < n && jobs[idx][0] <= t) {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        // 대기열에 있는 것 중에 하나 빼기
        if (!pq.empty()) {
            Job job = pq.top();
            answer += (t - job.r_time + job.w_time);
            t += job.w_time;
            pq.pop();
        }
        // 대기열이 없는 경우, 바로 다음 요청 시각을 현재 시간으로 맞춤
        else {
            t = jobs[idx][0];
        }
    }

    answer /= n;

    return answer;
}