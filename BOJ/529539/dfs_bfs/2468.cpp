#include <iostream>
#include <algorithm>

using namespace std;

int n, answer = 0;
int map[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			if (!visited[ny][nx])
				dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	int maxHeight = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxHeight = max(maxHeight, map[i][j]);
		}

	for (int rain = 0; rain <= maxHeight; rain++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] <= rain)
					visited[i][j] = true;
				else
					visited[i][j] = false;
			}
		}
		int safeArea = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					safeArea++;
					dfs(i, j);
				}
			}
		}
		answer = max(answer, safeArea);
	}
	cout << answer;
}