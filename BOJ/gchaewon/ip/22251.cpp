#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

//  -- a --
// |       |
// f       b
// |       |
// -- g --
// |       |
// e       c
// |       |
//  -- d --
// abcdefg (순으로 켜져있으면 1, 꺼져있으면 0)

map<char, string> nums = {{'0', "1111110"}, {'1', "0110000"}, {'2', "1101101"},
                          {'3', "1111001"}, {'4', "0110011"}, {'5', "1011011"},
                          {'6', "1011111"}, {'7', "1110000"}, {'8', "1111111"},
                          {'9', "1111011"}};

int n, k, p, ans = 0;
string x;

string transformFloor(string f) {
    string transformed_f = "";
    // 자릿수 k보다 짧은 경우 0 앞에 추가하기
    for (int i = 0; i < k - f.size(); i++) {
        transformed_f += nums['0'];
    }

    for (int i = 0; i < f.size(); i++) {
        transformed_f += nums[f[i]];
    }

    return transformed_f;
}

int main() {
    cin >> n >> k >> p >> x;

    x = transformFloor(x);
    // 1층부터 N층까지 탐색
    for (int f = 1; f <= n; f++) {
        // 7자리 비트로 변경
        string floor_str = transformFloor(to_string(f));

        if (floor_str == x) {
            continue;
        }
        // 다른 개수 구하기
        int diff = 0;
        for (int i = 0; i < x.size(); i++) {
            if (floor_str[i] != x[i]) {
                diff++;
            }
        }
        // 다른 개수가 1이상 p 이하일때만 가능
        if (diff >= 1 && diff <= p) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}