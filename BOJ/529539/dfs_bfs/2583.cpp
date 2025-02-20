#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int yLen, xLen, k;
int graph[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int area = 0;

void dfs(int y, int x) {
	area++;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen)
			if (!graph[ny][nx] && !visited[ny][nx])
				dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> yLen >> xLen >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = yLen - y2; y < yLen - y1; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1;
	}

	vector<int> v;
	for (int i = 0; i < yLen; i++) {
		for (int j = 0; j < xLen; j++) {
			area = 0;
			if (!graph[i][j] && !visited[i][j]) {
				dfs(i, j);
				v.push_back(area);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}