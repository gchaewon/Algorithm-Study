#include <bits/stdc++.h>

using namespace std;

string ans = "";
bool cmp(string a, string b) { return a + b > b + a; }
string solution(vector<int> numbers) {
    vector<string> v;

    for (auto n : numbers) {
        v.push_back(to_string(n));
    }
    sort(v.begin(), v.end(), cmp);

    for (auto n : v) {
        ans += n;
    }
    if (ans[0] == '0') {
        return "0";
    }

    return ans;
}