#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> adj[204];
int visited[204];
int n = 0;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 인근 노드로 탐색
        for (auto next : adj[cur]) {
            // 이미 네트워크 찾은 경우 제외
            if (visited[next]) {
                continue;
            }
            visited[next] = 1;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    n = computers.size();

    // 인근 노드 정보 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    // 탐색하며 네트워크 개수 구하기
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        bfs(i);
        answer++;
    }
    return answer;
}