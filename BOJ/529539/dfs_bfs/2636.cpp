#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int yLen, xLen;
int arr[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> cheese;
int currCheese = 0;

void bfs() {
	for (int y = 0; y < yLen; y++)
		for (int x = 0; x < xLen; x++)
			visited[y][x] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = 1;
	while (q.size()) {
		pair<int, int> pos = q.front();
		q.pop();
		int y = pos.first;
		int x = pos.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < xLen && ny >= 0 && ny < yLen)
				if (!visited[ny][nx]) {
					visited[ny][nx] = 1;
					if (arr[ny][nx] == 1) {
						arr[ny][nx] = 0;
						currCheese--;
					} else {
						q.push({ny, nx});
					}
				}
		}
	}
	cheese.push_back(currCheese);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> yLen >> xLen;
	for (int y = 0; y < yLen; y++)
		for (int x = 0; x < xLen; x++) {
			cin >> arr[y][x];
			if (arr[y][x])
				currCheese++;
		}
	cheese.push_back(currCheese);
	int time = 0;
	while (currCheese > 0) {
		time++;
		bfs();
	}
	cout << time << '\n';
	cout << cheese[cheese.size() - 2] << '\n';
}
