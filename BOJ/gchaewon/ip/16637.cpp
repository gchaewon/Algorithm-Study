#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

int n;
int ans = INT_MIN;
string s;
vector<int> nums;
vector<char> opers;

int calc(char op, int a, int b) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
    return a * b;
}

void go(int idx, int result) {
    if (idx == nums.size() - 1) {
        ans = max(ans, result);
        return;
    }

    // 괄호 추가하지 않은 경우
    // 누적 값에 계속 더하기
    go(idx + 1, calc(opers[idx], result, nums[idx + 1]));

    // 괄호를 추가하는 경우 인덱스 두개 건너뜀
    // a+b -> (a+b)
    if (idx + 2 <= nums.size() - 1) {
        // 괄호 내부 계산
        int inner = calc(opers[idx + 1], nums[idx + 1], nums[idx + 2]);
        // 기존 계산값 + 괄호 내부 계산 더하기
        go(idx + 2, calc(opers[idx], result, inner));
    }
    return;
}
int main() {
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        // 숫자인 경우
        if (0 <= num && num <= 9) {
            nums.push_back(num);
        }
        // 연산자인 경우
        else {
            opers.push_back(s[i]);
        }
    }

    // 시작 인덱스, 첫 값
    go(0, nums[0]);

    cout << ans;

    return 0;
}