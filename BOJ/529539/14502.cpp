#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int yLen, xLen, answer = 0;
int graph[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int graph[8][8]) {
	queue<pair<int, int>> q;
	for (int i = 0; i < yLen; i++)
		for (int j = 0; j < xLen; j++)
			if (graph[i][j] == 2)
				q.push({i, j});
	while (q.size()) {
		pair<int, int> pos = q.front();
		q.pop();
		int y = pos.first;
		int x = pos.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen && graph[ny][nx] == 0) {
				graph[ny][nx] = 2;
				q.push({ny, nx});
			}
		}
	}
	int count = 0;
	for (int i = 0; i < yLen; i++)
		for (int j = 0; j < xLen; j++)
			if (graph[i][j] == 0)
				count++;
	return count;
}

void dfs(int wall) {
	if (wall == 3) {
		int newGraph[8][8];
		memcpy(newGraph, graph, sizeof(graph));
		answer = max(answer, bfs(newGraph));
	} else {
		for (int i = 0; i < yLen; i++)
			for (int j = 0; j < xLen; j++) {
				if (graph[i][j] == 0) {
					graph[i][j] = 1;
					dfs(wall + 1);
					graph[i][j] = 0;
				}
			}
	}
}

int main() {
	cin >> yLen >> xLen;
	for (int i = 0; i < yLen; i++)
		for (int j = 0; j < xLen; j++)
			cin >> graph[i][j];
	dfs(0);
	cout << answer;
}