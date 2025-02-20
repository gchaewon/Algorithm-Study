#include <bits/stdc++.h>

using namespace std;
int k;
string ans_max = "0";
string ans_min = "9999999999";
vector<char> v(10, 0);
vector<int> is_used(10, 0);
vector<int> picked;

void update() {
    string temp;
    for (auto n : picked) {
        temp += to_string(n);
    }
    ans_max = max(ans_max, temp);
    ans_min = min(ans_min, temp);
}
void backTracking(int idx) {
    if (idx > k) {
        update();
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (is_used[i]) {
            continue;
        }
        if (v[idx - 1] == '<' && picked[idx - 1] > i) {
            continue;
        } else if (v[idx - 1] == '>' && picked[idx - 1] < i) {
            continue;
        }

        is_used[i] = 1;
        picked.push_back(i);
        backTracking(idx + 1);
        is_used[i] = 0;
        picked.pop_back();
    }
}

int main() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    backTracking(0);

    cout << ans_max << "\n" << ans_min;
    return 0;
}