#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    stack<int> s;
    vector<int> answer;

    s.push(arr.front());

    for (int i = 1; i < arr.size(); i++) {
        // 중복인 경우 추가하지 않음
        if (s.top() == arr[i]) {
            continue;
        }
        s.push(arr[i]);
    }

    // 원래 순서대로 출력하기 위해 뒤집기
    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}