#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(string &a, string &b) {
    if (a.size() == b.size()) {
        return a <= b;
    }
    return a.size() <= b.size();
}

int main() {
    int n;
    vector<string> nums;
    cin >> n;

    while (n--) {
        string str;
        string temp = "";
        cin >> str;

        for (auto c : str) {
            // 숫자인 경우
            if (c >= '0' && c <= '9') {
                // 앞에 0이 여러 개 나온 경우 -> 0 으로 바꾸기
                if (temp.size() == 1 && temp[0] == '0') {
                    temp = c;
                } else { // 일반 숫자인 경우 숫자붙이기
                    temp += c;
                }
                // 숫자가 아니고, 만든 숫자가 있는 경우 추가 후 초기화
            } else if (temp.size() != 0) {
                nums.push_back(temp);
                temp = "";
            }
        }
        // 끝까지 돌았을 때 숫자가 있는 경우 추가
        if (temp.size() != 0) {
            nums.push_back(temp);
        }
    }

    sort(nums.begin(), nums.end(), cmp);

    for (auto num : nums) {
        cout << num << "\n";
    }
    return 0;
}