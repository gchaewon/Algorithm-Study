#include <cmath>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    map<int, priority_queue<int, vector<int>, greater<int>>>
        h; // {절댓값, {절댓값을 가진 입력 배열(오름 차순)}}
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) {
            int abs_x = abs(x);
            h[abs_x].push(x);
        } else {
            if (h.size() == 0) {
                cout << 0 << "\n";
            } else {
                auto &arr = h.begin()->second;
                auto &abs_num = h.begin()->first;

                cout << arr.top() << "\n";
                arr.pop();

                if (arr.size() == 0) {
                    h.erase(abs_num);
                }
            }
        }
    }

    return 0;
}