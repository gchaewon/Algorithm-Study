#include <algorithm>
#include <iostream>
#include <vector>

#define B first
#define A second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int answer = 1;
    int pre;
    vector<pair<int, int>> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> schedule =
            make_pair(b, a); // 끝나는 시간을 기준으로 정렬
        v.push_back(schedule);
    }

    sort(v.begin(), v.end());
    pre = v[0].B; // 제일 첫 회의의 끝나는 시간

    for (int i = 1; i < n; i++) {
        if (pre <= v[i].A) { // 끝나는 시간보다 이후에 시작하는 회의
            pre = v[i].B;
            answer++;
        }
    }

    cout << answer;

    return 0;
}