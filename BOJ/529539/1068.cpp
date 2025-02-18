#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[50];
int cnt = 0;

void dfs(int now) {
	if (tree[now].size() == 0) {
		cnt++;
	} else {
		for (int child : tree[now])
			dfs(child);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> d;

	int root = 0;
	for (int i = 0; i < n; i++) {
		int parent = arr[i];
		if (parent == -1) {
			root = i;
		} else {
			if (parent == d || i == d)
				continue;
			else
				tree[parent].push_back(i);
		}
	}
	if (root == d) {
		cout << 0;
	} else {
		dfs(root);
		cout << cnt;
	}
}