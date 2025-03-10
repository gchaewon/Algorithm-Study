#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector<pair<int, int>> queens(n);

bool check(int row, int col) {
	for (auto queen : queens) {
		int qRow = queen.first;
		int qCol = queen.second;
		if (row == qRow || col == qCol)
			return false;
		if (abs(row - qRow) == abs(col - qCol))
			return false;
	}
	return true;
}

void dfs(int row) {
	if (row == n)
		cnt++;
	for (int col = 0; col < n; col++) {
		if (!check(row, col))
			continue;
		queens.push_back({row, col});
		dfs(row + 1);
		queens.pop_back();
	}
}

int main() {
	cin >> n;
	dfs(0);
	cout << cnt << '\n';
}