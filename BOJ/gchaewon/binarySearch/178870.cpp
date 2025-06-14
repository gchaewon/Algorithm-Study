#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    // 구간이 짧은 순으로 정렬
    if (a[1] - a[0] != b[1] - b[0]) {
        return a[1] - a[0] < b[1] - b[0];
    }
    // 시작 인덱스가 작은 순으로 정렬
    return a[0] < b[0];
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<vector<int>> idxs;
    int n = sequence.size();
    vector<int> dp(n, 0); // 누적합 저장

    dp[0] = sequence[0];

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + sequence[i];
    }

    int left = 0;
    int right = 0;

    // 투포인터
    while (left < n && right < n) {
        // sequence[left, right] 구간의 합
        int sum = dp[right] - dp[left] + sequence[left];

        // k 값보다 크거나 같은 경우, 범위 좁히기
        if (sum >= k) {
            if (sum == k) {
                idxs.push_back({left, right});
            }
            left += 1;
        }
        // 작은 경우 범위 늘리기
        else {
            right += 1;
        }
    }

    // 가능한 인덱스 조합 정렬
    sort(idxs.begin(), idxs.end(), cmp);

    answer = idxs[0];

    return answer;
}