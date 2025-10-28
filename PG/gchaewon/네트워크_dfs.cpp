#include <string>
#include <vector>

using namespace std;

int visited[204];

void dfs(int from, int n, vector<vector<int>> computers) {
    // 사이클 만들어지면 종료
    if (visited[from] != 0) {
        return;
    }
    visited[from] = 1;
    // 연결된 컴퓨터 중 방문하지 않은 것 dfs
    for (int to = 0; to < n; to++) {
        if (computers[from][to] != 1 || visited[to] != 0) {
            continue;
        }
        dfs(to, n, computers);
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        // 방문한 적 없는 경우 dfs
        if (visited[i] == 0) {
            dfs(i, n, computers);
            answer++;
        }
    }

    return answer;
}