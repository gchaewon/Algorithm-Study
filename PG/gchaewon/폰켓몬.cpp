#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    set<int> s;
    int ans = 0;
    int n = nums.size() / 2;
    for (auto num : nums) {
        s.insert(num);
    }

    if (s.size() <= n) {
        ans = s.size();
    } else {
        ans = n;
    }
    return ans;
}