#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();

    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i + 1; j < n; j++) {
            // 가격이 떨어지는 시점도 1초+1, 더하기 중단
            if (prices[i] > prices[j]) {
                s++;
                break;
            }
            s++;
        }
        answer.push_back(s);
    }
    return answer;
}