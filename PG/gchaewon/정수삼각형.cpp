#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    vector<vector<int>> dp(n); // dp[i][j] = i행 j열의 누적 최댓값

    int root = triangle[0][0];
    dp[0] = {root};

    // 삼각형 높이가 1인 경우
    if (n == 1) {
        return root;
    }

    dp[1] = {root + triangle[1][0], root + triangle[1][1]};

    for (int i = 2; i < n; i++) {
        // 왼쪽 가장자리
        dp[i].push_back(dp[i - 1][0] + triangle[i][0]);

        // 중간자리
        for (int j = 1; j <= i; j++) {
            int left = dp[i - 1][j - 1];
            int right = dp[i - 1][j];
            // 왼쪽, 오른쪽 부모 중 큰 값을 더함
            dp[i].push_back(max(left, right) + triangle[i][j]);
        }

        // 오른쪽 가장자리
        dp[i].push_back(dp[i - 1][i] + triangle[i][i]);
    }

    sort(dp[n - 1].rbegin(), dp[n - 1].rend());

    answer = dp[n - 1][0];

    return answer;
}
