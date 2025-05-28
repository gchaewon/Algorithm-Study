#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    // 1~9 더하기
    for (int i = 1; i <= 9; i++) {
        answer += i;
    }
    // 있는 숫자 빼기
    for (int num : numbers) {
        answer -= num;
    }

    return answer;
}