#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long MAX_P = 1000000000;
const long long MAX_T = 100000;

bool checkValid(long long t, int n, vector<int> times) {
    long long cnt = 0;

    // 각 심사대에서 심사할 수 있는 사람 수 cnt 에 저장
    for (auto time : times) {
        cnt += t / time;
    }

    // 심사해야하는 수만큼 못하는 경우 false
    if (cnt < n) {
        return false;
    }

    return true;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = times.front(); // 가장 처음 사람 심사받는데 걸리는 시간
    long long right = MAX_P * MAX_T; // 최대 범위에서 걸리는 시간

    int cnt = 0;

    // 총 심사하는데 걸리는 시간 기준
    while (left <= right) {
        long long mid = (left + right) / 2LL;

        // mid 시간에 n명을 모두 심사 할 수 있는 경우
        if (checkValid(mid, n, times)) {
            // 시간 줄임
            right = mid - 1;
            answer = mid;
        } else {
            // 심사할 수 없는 경우, 시간 늘림
            left = mid + 1;
        }
    }

    return answer;
}