#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, m;
	cin >> n >> k >> m;

	vector<vector<int>> station(n + 1);
	vector<vector<int>> hypertube(m, vector<int>(k));
	vector<int> visited(n + 1, 0);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++) {
			int st;
			cin >> st;
			hypertube[i].push_back(st);
			station[st].push_back(i);
		}

	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int currSt = q.front();
		q.pop();
		for (int id : station[currSt]) {
			for (int nextSt : hypertube[id]) {
				if (nextSt != currSt && visited[nextSt] == 0) {
					visited[nextSt] = visited[currSt] + 1;
					q.push(nextSt);
				}
			}
		}
	}

	if (visited[n] == 0)
		cout << -1;
	else
		cout << visited[n];
}