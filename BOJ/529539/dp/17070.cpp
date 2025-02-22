#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> graph;

int useDP() {
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, 0)));
	dp[0][1][0] = 1;
	for (int y = 0; y < n; y++) {
		for (int x = 1; x < n; x++) {
			if (graph[y][x] == 1)
				continue;
			if (x > 0)
				dp[y][x][0] += dp[y][x - 1][0] + dp[y][x - 1][2];
			if (y > 0)
				dp[y][x][1] += dp[y - 1][x][1] + dp[y - 1][x][2];
			if (x > 0 && y > 0 && graph[y - 1][x] == 0 && graph[y][x - 1] == 0)
				dp[y][x][2] += dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
		}
	}
	return dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}

int bfs() {
	int dy[3] = {0, 1, 1};
	int dx[3] = {1, 0, 1};
	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 1}, 0});
	int answer = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if (y == n - 1 && x == n - 1) {
			answer++;
			continue;
		}
		vector<int> iter;
		if (dir == 0)
			iter = {0, 2};
		else if (dir == 1)
			iter = {1, 2};
		else
			iter = {0, 1, 2};
		for (int nd : iter) {
			int ny = y + dy[nd];
			int nx = x + dx[nd];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n && graph[ny][nx] == 0) {
				if (nd == 2) {
					if (graph[y + 1][x] == 1 || graph[y][x + 1] == 1)
						continue;
				}
				q.push({{ny, nx}, nd});
			}
		}
	}
	return answer;
}

int main() {
	cin >> n;
	graph.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];

	cout << useDP() << '\n';
	// cout << bfs() << '\n';
}