#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &computers, vector<bool> &is_grouped, int n, int a,
         int b) {
    queue<int> q;
    is_grouped[a] = true;
    q.push(b);

    while (!q.empty()) {
        int next = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (i == next || is_grouped[i]) {
                continue;
            }
            if (computers[next][i] == 1) {
                is_grouped[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> is_grouped(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_grouped[i] || is_grouped[j]) {
                continue;
            }
            if (computers[i][j] == 1) {
                bfs(computers, is_grouped, n, i, j);
                answer++;
            }
        }
    }

    return answer;
}