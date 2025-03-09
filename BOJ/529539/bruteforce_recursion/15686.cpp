#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, answer = INT_MAX;
vector<vector<int>> arr;
vector<pair<int, int>> chicken, house, usedChicken;

void recursion(int currIdx) {
	if (usedChicken.size() == m) {
		int sum = 0;
		for (auto currHouse : house) {
			int y = currHouse.first;
			int x = currHouse.second;
			int dist = INT_MAX;
			for (auto currChicken : usedChicken) {
				int cy = currChicken.first;
				int cx = currChicken.second;
				dist = min(dist, abs(x - cx) + abs(y - cy));
			}
			sum += dist;
		}
		answer = min(answer, sum);
		return;
	}
	for (int i = currIdx; i < chicken.size(); i++) {
		usedChicken.push_back(chicken[i]);
		recursion(i + 1);
		usedChicken.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	arr.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				chicken.push_back({i, j});
			if (arr[i][j] == 1)
				house.push_back({i, j});
		}

	recursion(0);
	cout << answer << '\n';
}