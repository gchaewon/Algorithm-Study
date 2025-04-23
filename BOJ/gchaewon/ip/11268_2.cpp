#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

// 오름차순으로 정렬해야지 pq에서 내림차순으로 나옴
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        return a > b;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    priority_queue<int, vector<int>,
                   cmp> pq; // 커스텀 함수 사용해서 정렬
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) {
            pq.push(x);
        } else {
            if (pq.size() == 0) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}