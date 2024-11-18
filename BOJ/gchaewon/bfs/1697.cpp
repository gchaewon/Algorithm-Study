#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    vector<int> v(100002, 0);
    vector<int> dir = {-1, 1, 2};
    queue<int> q;

    cin >> N >> K;

    q.push(N);
    v[N] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == K) {
            cout << v[x] - 1;
            return 0;
        }

        for (auto d : dir) {
            int dx = x;
            d != 2 ? dx += d : dx *= d;

            if (dx < 0 || dx > 100000 || v[dx] != 0) {
                continue;
            }

            v[dx] = v[x] + 1;
            q.push(dx);
        }
    }

    return 0;
}