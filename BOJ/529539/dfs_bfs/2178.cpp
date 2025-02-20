#include <iostream>
#include <string>
#include <queue>

using namespace std;

int yLen, xLen;
int arr[100][100];
int visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen)
				if (!visited[ny][nx] && arr[ny][nx]) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ny, nx});
				}
		}
	}
	return visited[yLen - 1][xLen - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> yLen >> xLen;
	for (int i = 0; i < yLen; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < xLen; j++)
			arr[i][j] = tmp[j] - '0';
	}

	cout << bfs();
}