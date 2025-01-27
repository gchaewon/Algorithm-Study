#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> nge(n, 0);
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s.push({0, a[0]});

    for (int i = 1; i < n; i++) {
        // 왼쪽 < 오른쪽일 때, 스택에서 오른쪽 수보다 큰 수 발견할 때까지 pop
        while (!s.empty() && s.top().second < a[i]) {
            if (s.top().second < a[i]) {
                nge[s.top().first] = a[i];
                s.pop();
            }
        }
        // 왼쪽 > 오른쪽 일 때, 오른쪽 값 push
        s.push({i, a[i]});
    }

    while (!s.empty()) {
        int idx = s.top().first;
        s.pop();
        nge[idx] = -1;
    }

    for (auto n : nge) {
        cout << n << " ";
    }

    return 0;
}