#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

void bfs(pair<int, int> &start, vector<pair<int, int>> &combs,
         pair<int, int> &target) {
    queue<pair<int, int>> q;
    vector<bool> is_visited(combs.size(), false);
    q.push(start);

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        if (x == target.X && y == target.Y) {
            cout << "happy\n";
            return;
        }

        for (int i = 0; i < combs.size(); i++) {
            int dist = abs(combs[i].X - x) + abs(combs[i].Y - y);
            if (is_visited[i]) {
                continue;
            }
            if (dist > 1000) {
                continue;
            }

            is_visited[i] = true;
            q.push({combs[i].X, combs[i].Y});
        }
    }
    cout << "sad\n";
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        int x, y;
        pair<int, int> start;
        vector<pair<int, int>> nodes;
        pair<int, int> target;

        cin >> n;
        cin >> x >> y;

        start = make_pair(x, y);

        while (n--) {
            cin >> x >> y;
            nodes.push_back(make_pair(x, y));
        }

        cin >> x >> y;
        target = make_pair(x, y);
        nodes.push_back(target);
        sort(nodes.begin(), nodes.end());
        bfs(start, nodes, target);
    }
    return 0;
}