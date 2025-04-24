#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

string min_arr = "null";
string arr;
string nums = "123";

int n;

bool checkValid() {
    int len = arr.size();

    // 검사할 겹치는 수열의 길이
    for (int i = 1; i <= len / 2; i++) {
        bool is_valid = false;
        // 뒤에서부터 i길이만큼 같은게 있는지 확인
        for (int j = 0; j < i; j++) {
            if (arr[len - j - 1] != arr[len - j - 1 - i]) {
                is_valid = true;
                break;
            }
        }
        // i  길이만큼 검사했을 때, 겹친다면 바로 리턴
        if (!is_valid) {
            return false;
        }
    }

    // 검사 통과
    return true;
}

void backTracking(int idx) {
    // 최소 수열 찾았다면 중단
    if (min_arr != "null") {
        return;
    }
    // 길이가 n일 때 중단
    if (idx == n) {
        min_arr = arr;
        return;
    }
    for (auto num : nums) {
        // 바로 옆 수와 같은 경우 제외
        if (!arr.empty() && arr.back() == num) {
            continue;
        }

        // 추가
        arr.push_back(num);

        // 가능한 경우만 탐색
        if (checkValid()) {
            backTracking(idx + 1);
        }

        // 원복
        arr.pop_back();
    }
    return;
}
int main() {
    cin >> n;

    backTracking(0);

    cout << min_arr;

    return 0;
}