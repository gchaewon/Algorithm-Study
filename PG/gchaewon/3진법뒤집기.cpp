#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    int r = n;

    // 10진 -> 3진
    while (r > 0) {
        v.push_back(r % 3);
        r /= 3;
    }

    // 3진 -> 10진
    int a = 1;
    for (int i = v.size() - 1; i >= 0; i--) {
        answer += a * v[i];
        a *= 3;
    }
    return answer;
}