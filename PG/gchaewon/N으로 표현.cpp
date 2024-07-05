#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    
    vector<set<int>> dp(9);
    
    // dp[i]는 i개의 N을 사용하여 만들 수 있는 수들의 집합
    dp[1].insert(N);
    
    for (int i = 2; i <= 8; i++) {
        // i개의 N을 사용하여 만들 수 있는 수들의 집합
        for (int j = 1; j < i; j++) {
            for (auto a : dp[j]) {
                // 이전 집합에서 사칙 연산한 값 추가
                for (auto b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) { // 0으로 나누기 예외처리
                        dp[i].insert(a / b);
                    }
                }
            }
        }
        
        // NN과 같이 N을 여러번 써서 수를 만드는 경우 추가
        int num = 0;
        for (int k = 0; k < i; k++) {
            num = num * 10 + N;
        }
        dp[i].insert(num);
        
        // number를 찾으면 N 사용 횟수 i 반환
        if (dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }
    
    return -1;
}